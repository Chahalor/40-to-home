#include <ncurses.h>
#include <stdlib.h>

int main(void) {
	initscr();            // Initialisation de ncurses
	cbreak();             // Ligne par ligne, sans mise en tampon
	noecho();             // Pas d'affichage des frappes clavier
	curs_set(0);          // Masquer le curseur

	// Récupérer la taille de l'écran
	int height, width;
	getmaxyx(stdscr, height, width);

	// Calculer la taille des 4 blocs (2 lignes, 2 colonnes)
	int half_height = height / 2;
	int half_width  = width / 2;

	// Créer 4 fenêtres pour chaque bloc
	WINDOW *win1 = newwin(half_height, half_width, 0, 0);
	WINDOW *win2 = newwin(half_height, width - half_width, 0, half_width);
	WINDOW *win3 = newwin(height - half_height, half_width, half_height, 0);
	WINDOW *win4 = newwin(height - half_height, width - half_width, half_height, half_width);

	// Dessiner des bordures pour chaque bloc
	box(win1, 0, 0);
	box(win2, 0, 0);
	box(win3, 0, 0);
	box(win4, 0, 0);

	// Afficher du texte dans chaque bloc
	mvwprintw(win1, 1, 2, "Bloc 1 : Header/Logo");
	mvwprintw(win2, 1, 2, "Bloc 2 : Infos globales");
	mvwprintw(win3, 1, 2, "Bloc 3 : Etat compilation");
	mvwprintw(win4, 1, 2, "Bloc 4 : Barre de progression");

	// Rafraîchir les fenêtres pour afficher le contenu
	wrefresh(win1);
	wrefresh(win2);
	wrefresh(win3);
	wrefresh(win4);

	// Attendre que l'utilisateur appuie sur une touche
	getch();

	// Nettoyer
	delwin(win1);
	delwin(win2);
	delwin(win3);
	delwin(win4);
	endwin();
	return 0;
}
