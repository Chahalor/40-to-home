/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:40:03 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/02 08:38:43 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

// isFunc.c
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);

// strFunc.c
unsigned long int	ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);

// strFunc2.c
unsigned long int	ft_strlcpy(char *dst, const char *src,
						unsigned long int size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

// memFunc.c
void				*ft_memset(void *s, int c, unsigned long int n);
void				*ft_memcpy(void *dest, const void *src,
						unsigned long int n);
void				*ft_memchr(const void *s, int c, unsigned long int n);
int					ft_memcmp(const void *s1, const void *s2,
						unsigned long int n);
void				*ft_memmove(void *dest, const void *src, size_t n);
// memfunc2.c
void				ft_bzero(void *s, unsigned long int n);

// malloc time
void				*ft_calloc(unsigned long int nmemb, unsigned long int size);
char				*ft_strdup(const char *s);

// ft_txt.c
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *nptr);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

// Bonus
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

// ft_printf
int					ft_printf(const char *str, ...)
					__attribute__ ((format(printf, 1, 2)));

// get_next_line
char				*get_next_line(int fd);

#endif