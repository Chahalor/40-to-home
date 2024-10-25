/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:40:03 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/25 14:51:16 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

/*
Return if a character is a digit (0-9).
@param int c - Character to check.
@return int - 1 if the character is a digit, 0 otherwise.
*/
int					ft_isdigit(int c);

/*
Return if a character is an alphabetic letter (A-Z, a-z).
@param int c - Character to check.
@return int - 1 if the character is an alphabetic letter, 0 otherwise.
*/
int					ft_isalpha(int c);

/*
Return if a character is alphanumeric (A-Z, a-z, 0-9).
@param int c - Character to check.
@return int - 1 if the character is alphanumeric, 0 otherwise.
*/
int					ft_isalnum(int c);

/*
Return if a character is a valid ASCII character (0-127).
@param int c - Character to check.
@return int - 1 if the character is an ASCII character, 0 otherwise.
*/
int					ft_isascii(int c);

/*
Return if a character is printable (including space, but excluding control
 characters).
@param int c - Character to check.
@return int - 1 if the character is printable, 0 otherwise.
*/
int					ft_isprint(int c);

/*
Return the length of a string.
@param const char *s - String to measure.
@return unsigned long int - The length of the string.
*/
unsigned long int	ft_strlen(const char *s);

/*
Return a pointer to the first occurrence of a character in a string.
@param const char *s - String to search.
@param int c - Character to find.
@return char* - Pointer to the first occurrence of the character,
 or NULL if not found.
*/
char				*ft_strchr(const char *s, int c);

/*
Return a pointer to the last occurrence of a character in a string.
@param const char *s - String to search.
@param int c - Character to find.
@return char* - Pointer to the last occurrence of the character,
 or NULL if not found.
*/
char				*ft_strrchr(const char *s, int c);

/*
Compare two strings up to n characters.
@param const char *s1 - First string.
@param const char *s2 - Second string.
@param size_t n - Maximum number of characters to compare.
@return int - 0 if strings are equal, negative if s1 < s2, positive if s1 > s2.
*/
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/*
Locate a substring in a string, searching up to len characters.
@param const char *big - String to search.
@param const char *little - Substring to find.
@param size_t len - Maximum length to search.
@return char* - Pointer to the beginning of the found substring,
  or NULL if not found.
*/
char				*ft_strnstr(const char *big, const char *little,
						size_t len);

/*
Copy up to size characters from src to dst, ensuring null-termination.
@param char *dst - Destination buffer.
@param const char *src - Source string.
@param unsigned long int size - Size of the destination buffer.
@return unsigned long int - The length of the source string.
*/
unsigned long int	ft_strlcpy(char *dst, const char *src,
						unsigned long int size);

/*
Concatenate src to dst, ensuring null-termination, but only up to size bytes.
@param char *dst - Destination buffer.
@param const char *src - Source string to append.
@param size_t size - Size of the destination buffer.
@return size_t - The total length of the string they tried to creat
 (length of dst + src).
*/
size_t				ft_strlcat(char *dst, const char *src, size_t size);

/*
Fill a block of memory with a specific value.
@param void *s - Pointer to the block of memory.
@param int c - Value to set.
@param unsigned long int n - Number of bytes to set.
@return void* - Pointer to the block of memory.
*/
void				*ft_memset(void *s, int c, unsigned long int n);

/*
Copy n bytes from src to dest.
@param void *dest - Destination buffer.
@param const void *src - Source buffer.
@param unsigned long int n - Number of bytes to copy.
@return void* - Pointer to the destination buffer.
*/
void				*ft_memcpy(void *dest, const void *src,
						unsigned long int n);

/*
Search for a character in a block of memory.
@param const void *s - Block of memory to search.
@param int c - Character to find.
@param unsigned long int n - Number of bytes to search.
@return void* - Pointer to the first occurrence of the character,
 or NULL if not found.
*/
void				*ft_memchr(const void *s, int c, unsigned long int n);

/*
Compare two blocks of memory.
@param const void *s1 - First block of memory.
@param const void *s2 - Second block of memory.
@param unsigned long int n - Number of bytes to compare.
@return int - 0 if equal, negative if s1 < s2, positive if s1 > s2.
*/
int					ft_memcmp(const void *s1, const void *s2,
						unsigned long int n);

/*
Move n bytes from src to dest, handling overlapping memory areas.
@param void *dest - Destination buffer.
@param const void *src - Source buffer.
@param size_t n - Number of bytes to move.
@return void* - Pointer to the destination buffer.
*/
void				*ft_memmove(void *dest, const void *src, size_t n);

/*
Zero out n bytes of memory.
@param void *s - Pointer to the block of memory.
@param unsigned long int n - Number of bytes to zero out.
@return void
*/
void				ft_bzero(void *s, unsigned long int n);

/*
Allocate and zero-initialize an array of nmemb elements of size bytes each.
@param unsigned long int nmemb - Number of elements to allocate.
@param unsigned long int size - Size of each element.
@return void* - Pointer to the allocated memory, or NULL if allocation fails.
*/
void				*ft_calloc(unsigned long int nmemb, unsigned long int size);

/*
Duplicate a string by allocating memory for a new copy.
@param const char *s - String to duplicate.
@return char* - Pointer to the newly allocated copy of the string,
 or NULL if allocation fails.
*/
char				*ft_strdup(const char *s);

/*
Convert a lowercase letter to uppercase.
@param int c - Character to convert.
@return int - The uppercase equivalent, or the original character if
 it's not a lowercase letter.
*/
int					ft_toupper(int c);

/*
Convert an uppercase letter to lowercase.
@param int c - Character to convert.
@return int - The lowercase equivalent, or the original character
 if it's not an uppercase letter.
*/
int					ft_tolower(int c);

/*
Convert a string to an integer.
@param const char *nptr - String to convert.
@return int - The integer value of the string.
*/
int					ft_atoi(const char *nptr);

/*
Extract a substring from a string.
@param char const *s - The source string.
@param unsigned int start - Starting index of the substring.
@param size_t len - Length of the substring.
@return char* - Pointer to the allocated substring, or NULL if allocation fails.
*/
char				*ft_substr(char const *s, unsigned int start, size_t len);

/*
Concatenate two strings by allocating memory for the result.
@param char const *s1 - First string.
@param char const *s2 - Second string.
@return char* - Pointer to the newly allocated concatenated string,
 or NULL if allocation fails.
*/
char				*ft_strjoin(char const *s1, char const *s2);

/*
Trim characters from both ends of a string.
@param char const *s1 - String to trim.
@param char const *set - Set of characters to remove from the ends.
@return char* - Pointer to the newly allocated trimmed string,
 or NULL if allocation fails.
*/
char				*ft_strtrim(char const *s1, char const *set);

/*
Split a string into an array of substrings based on a delimiter character.
@param char const *s - String to split.
@param char c - Delimiter character.
@return char** - Pointer to an array of strings, or NULL if allocation fails.
*/
char				**ft_split(char const *s, char c);

/*
Convert an integer to a string.
@param int n - Integer to convert.
@return char* - Pointer to the newly allocated string representation
 of the integer, or NULL if allocation fails.
*/
char				*ft_itoa(int n);

/*
Apply a function to each character of a string to create a new string.
@param char const *s - Source string.
@param char (*f)(unsigned int, char) - Function to apply to each character.
@return char* - Pointer to the newly allocated string,
 or NULL if allocation fails.
*/
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
Apply a function to each character of a string, modifying the string in place.
The function is applied to each character with its index.
@param char *s - String to modify.
@param void (*f)(unsigned int, char*) - Function to apply to each character,
 taking the index and a pointer to the character.
@return void
*/
void				ft_striteri(char *s, void (*f)(unsigned int, char*));

/*
Write a character to the given file descriptor.
@param char c - Character to write.
@param int fd - File descriptor where the character is written.
@return void
*/
void				ft_putchar_fd(char c, int fd);

/*
Write a string to the given file descriptor.
@param char *s - String to write.
@param int fd - File descriptor where the string is written.
@return void
*/
void				ft_putstr_fd(char *s, int fd);

/*
Write a string followed by a newline to the given file descriptor.
@param char *s - String to write.
@param int fd - File descriptor where the string and newline are written.
@return void
*/
void				ft_putendl_fd(char *s, int fd);

/*
Write an integer to the given file descriptor.
@param int n - Integer to write.
@param int fd - File descriptor where the integer is written.
@return void
*/
void				ft_putnbr_fd(int n, int fd);

/*
A structure representing an element of a singly linked list.

Fields:
- void *content: A pointer to the content stored in the list element.
 It can point to any type of data.
- struct s_list *next: A pointer to the next element in the list,
 or NULL if it is the last element.
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*
Create a new list element with the given content.
@param void *content - The content to store in the new element.
@return t_list* - Pointer to the new list element, or NULL if allocation fails.
*/
t_list				*ft_lstnew(void *content);

/*
Add a new element at the beginning of the list.
@param t_list **lst - Pointer to the first element of the list.
@param t_list *new - The new element to add to the front.
@return void
*/
void				ft_lstadd_front(t_list **lst, t_list *new);

/*
Return the number of elements in the list.
@param t_list *lst - Pointer to the first element of the list.
@return int - The number of elements in the list.
*/
int					ft_lstsize(t_list *lst);

/*
Return the last element of the list.
@param t_list *lst - Pointer to the first element of the list.
@return t_list* - Pointer to the last element of the list,
 or NULL if the list is empty.
*/
t_list				*ft_lstlast(t_list *lst);

/*
Add a new element at the end of the list.
@param t_list **lst - Pointer to the first element of the list.
@param t_list *new - The new element to add to the back.
@return void
*/
void				ft_lstadd_back(t_list **lst, t_list *new);

/*
Delete one element of the list using a given function to free the content.
@param t_list *lst - The element to delete.
@param void (*del)(void*) - Function used to free the content of the element.
@return void
*/
void				ft_lstdelone(t_list *lst, void (*del)(void*));

/*
Clear the entire list, applying a function to free the content of each element.
@param t_list **lst - Pointer to the first element of the list.
@param void (*del)(void*) - Function used to free the content of each element.
@return void
*/
void				ft_lstclear(t_list **lst, void (*del)(void*));

/*
Iterate through the list and apply a function to the content of each element.
@param t_list *lst - Pointer to the first element of the list.
@param void (*f)(void*) - Function to apply to the content of each element.
@return void
*/
void				ft_lstiter(t_list *lst, void (*f)(void*));

/*
Create a new list by applying a function to each element of an existing list.
Each new element's content is generated by the function f.
@param t_list *lst - Pointer to the first element of the original list.
@param void *(*f)(void*) - Function to apply to the content of each element.
@param void (*del)(void*) - Function to free the content in case of failure.
@return t_list* - Pointer to the new list, or NULL if allocation fails.
*/
t_list				*ft_lstmap(t_list *lst, void *(*f)(void*),
						void (*del)(void*));

#endif