// #include <ncurses.h>

// int	main(void)
// {
// 	initscr();			// Démarre ncurses
// 	cbreak();			// Lecture sans attendre '\n'
// 	noecho();			// N'affiche pas les touches tapées
// 	keypad(stdscr, TRUE); // Active les touches spéciales (flèches etc.)
// 	curs_set(0);		// Cache le curseur

// 	mvprintw(5, 10, "Hello ncurses !");
// 	refresh();

// 	getch();			// Attend une touche
// 	endwin();			// Termine ncurses proprement
// 	return (0);
// }

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

# define DICT_SIZE 8192 // taille du tableau de hash

typedef struct s_word {
	char			*word;
	struct s_word	*next;
}	t_word;

typedef struct s_dict {
	t_word	*table[DICT_SIZE];
}	t_dict;


unsigned int	hash_word(
	const char *restrict str
)
{
	register unsigned int	hash = 5381;
	register int			c;

	if (!str)
		return (-1);
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; // hash * 33 + c
	return (hash % DICT_SIZE);
}

void	insert_word(
	t_dict *restrict dict,
	const char *restrict word
)
{
	const unsigned int	index = hash_word(word);

	t_word	*new = (t_word *)malloc(sizeof(t_word));
	new->word = strdup(word);
	new->next = dict->table[index];
	dict->table[index] = new;
}


bool	word_exists(
	t_dict *restrict dict,
	const char *restrict word
)
{
	if (!word)
		return false;

	const unsigned int	index = hash_word(word);
	t_word				*entry = dict->table[index];


	while (entry)
	{
		if (strcmp(entry->word, word) == 0)
			return true;
		entry = entry->next;
	}
	return false;
}

t_dict	*load_dict(
	const char *restrict filepath
)
{
	t_dict	*dict = calloc(1, sizeof(t_dict));
	FILE	*fp = fopen(filepath, "r");
	char	buffer[128];

	if (!fp)
		return NULL;

	while (fgets(buffer, sizeof(buffer), fp))
	{
		buffer[strcspn(buffer, "\n")] = 0; // enlever le \n
		insert_word(dict, buffer);
	}
	fclose(fp);
	return dict;
}

void	free_dict(t_dict *dict)
{
	register int	i;

	i = -1;
	while (++i < DICT_SIZE)
	{
		t_word *entry = dict->table[i];
		while (entry)
		{
			t_word *tmp = entry;
			entry = entry->next;
			free(tmp->word);
			free(tmp);
		}
	}
	free(dict);
}

int main(void)
{
	t_dict *dict = load_dict("../data/words.txt");
	if (!dict)
	{
		perror("Failed to load dictionary");
		return (1);
	}

	if (word_exists(dict, NULL))
		printf("Mot valide !\n");
	else
		printf("Mot inconnu.\n");

	free_dict(dict);
	return 0;
}
