/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:22:58 by jose-gon          #+#    #+#             */
/*   Updated: 2024/04/09 16:19:09 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ctype.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isalpha(int c);
int		ft_toupper(int c);
int		ft_isdigit(int c);
int		ft_tolower(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
/**
 * @brief Strncmp lexicographically compare the
     null-terminated strings s1 and s2.
 *
 * @param s1 string 1.
 * @param s2 string 2.
 * @param n number of characters to compare
 * @return int return greater than,
     equal to, or less than 0.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/**
 * @brief compares byte string s1 against byte string
     s2.
 *
 * @param s1 byte string s1.
 * @param s2 byte string s2.
 * @param n both strings are assumed to be n bytes long.
 * @return int returns zero if the two strings are identical,
     otherwise returns the difference between the first two differing
     bytes.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);
/**
 * @brief locates the first occurrence of c (converted
     to a char) in the string pointed to by s.  The terminating null
     character is considered to be part of the string; therefore if c is
     `\0', the functions locate the terminating `\0'.
 *
 * @param s string.
 * @param c char to locate
 * @return char* pointer to the located
     character, or NULL if the character does not appear in the string.
 */
char	*ft_strchr(const char *s, int c);
/**
 * @brief locates the last occurrence of c (converted
     to a char) in the string pointed to by s.  The terminating null
     character is considered to be part of the string; therefore if c is
     `\0', the functions locate the terminating `\0'.
 *
 * @param s string
 * @param c char to locate
 * @return char* pointer to the located
     character, or NULL if the character does not appear in the string.
 */
char	*ft_strrchr(const char *s, int c);
/**
 * @brief allocates sufficient memory for a copy of the
     string s1, does the copy, and returns a pointer to it.  The pointer
     may subsequently be used as an argument to the function free.
 *
 * @param s1 string to copy.
 * @return char* return a pointer to the copy.
 */
char	*ft_strdup(const char *s1);
/**
 * @brief converts an integer to string.
 *
 * @param n integer to convert
 * @return char* pointer to created string.
 */
char	*ft_itoa(int n);
/**
 * @brief locates the first occurrence of the null-ter-
     minated string needle in the string haystack, where not more than
     len characters are searched.
 *
 * @param haystack string where locate.
 * @param needle string to locate
 * @param len maximun number of characters to search
 * @return char* if needle is an empty string, haystack is returned; if needle
 *  occurs nowhere in haystack, NULL is returned; otherwise a pointer to the
     first character of the first occurrence of needle is returned.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
/**
 * @brief memory allocation with malloc and create a new string, from start
 * with max length given.
 * @param s target string.
 * @param start position to start.
 * @param len max length to copy.
 * @return char* pointer to new string created.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);
/**
 * @brief memory allocation to new string created by concatenation of s1 and s2
 * @param s1 string s1
 * @param s2 string s2
 * @return char* pointer to new string created.
 */
char	*ft_strjoin(char const *s1, char const *s2);
/**
 * @brief Remove all characters from the string 'set'
from the beginning and from the end of 's1', until
find a character not belonging to 'set'. The
resulting string is returned with a reservation of
malloc.
 * @param s1 string s.
 * @param set set of characters to trim.
 * @return char* pointer to string trimmed.
 */
char	*ft_strtrim(char const *s1, char const *set);
/**
 * @brief To each character of the string 's', apply the
function 'f' giving as parameters the index of each
character inside 's' and the character itself. Generate
a new string with the result of successive use
of 'f'.
 *
 * @param s string gived.
 * @param f function to apply.
 * @return char* the string created after the correct use of 'f' on
each character.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/**
 * @brief Reserve using malloc an array of strings
resulting from separating the string 's' into substrings
using the character 'c' as a delimiter. He
array must be terminated with a NULL pointer.
 *
 * @param s original string.
 * @param c delimiter character
 * @return char** array of strings.
 */
char	**ft_split(char const *s, char c);
/**
 * @brief writes len bytes of value c (converted to an
     unsigned char) to the string b.
 *
 * @param b string to fill
 * @param c value of char to write.
 * @param len lenght of bytes.
 * @return void* its first argument.
 */
void	*ft_memset(void *b, int c, size_t len);
/**
 * @brief copies n bytes from memory area src
 * to memory area dst.
 *
 * @param dst destination memory area.
 * @param src source memory area.
 * @param n number of bytes to copy.
 * @return void* original value of dst.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n);
/**
 * @brief copies len bytes from string src to string dst.
     The two strings may overlap; the copy is always done in a non-destructive
     manner.
 *
 * @param dst destination memory area.
 * @param src source memory area.
 * @param len lenght bytes to copy.
 * @return void* the original value of dst.
 */
void	*ft_memmove(void	*dst, const void *src, size_t len);
/**
 * @brief locates the first occurrence of c (converted to an
     unsigned char) in string s.
 *
 * @param s string gived.
 * @param c int value of char to find.
 * @param n max number bytes.
 * @return void* returns a pointer to the byte located, or NULL if
     no such byte exists within n bytes.
 */
void	*ft_memchr(const void *s, int c, size_t n);
/**
 * @brief allocates enough space for count objects.
 * The allocated memory is filled with bytes of value
     zero.
 *
 * @param count number of objects.
 * @param size size bytes of memory each object.
 * @return void* return a pointer to allocated memory.
 */
void	*ft_calloc(size_t count, size_t size);
/**
 * @brief To each character of the string 's', apply the function
’f’ giving as parameters the index of each
character within 's' and the address of itself
character, which can be modified if necessary.
 *
 * @param s string to iterate.
 * @param f function to apply.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
/**
 * @brief writes n zeroed bytes to the string s.  If n is
     zero, bzero() does nothing.
 *
 * @param s string
 * @param n nuber of bytes
 */
void	ft_bzero(void *s, size_t n);
/**
 * @brief copies up to dstsize - 1 characters from the string src to dst,
     NUL-terminating the result if dstsize is not 0.
 *
 * @param dst destination string
 * @param src source
 * @param dstsize size of dst
 * @return size_t the total length of the string they tried to create.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
/**
 * @brief appends string src to the end of dst.
 *
 * @param dst destination string
 * @param src source
 * @param dstsize size of dst
 * @return size_t the total length of the string they tried to create.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
/**
 * @brief creates a new node with the content gived and pointing to null
 *
 * @param content pointer to content.
 * @return t_list* creates a new node.
 */
t_list	*ft_lstnew(void *content);
/**
 * @brief find the last node from a list.
 *
 * @param lst list
 * @return t_list* pointer to last node.
 */
t_list	*ft_lstlast(t_list *lst);
/**
 * @brief create a resulting list
of the correct and successive application of the function
'f' over each node.
 *
 * @param lst list gived
 * @param f modification function.
 * @param del delete function.
 * @return t_list* the new list created.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
/**
 * @brief add a node to the first place of a list
 *
 * @param lst list gived.
 * @param new node to add.
 */
void	ft_lstadd_front(t_list **lst, t_list *new);
/**
 * @brief add a node to the last place of a list, or create a new one
 * if list is missed
 *
 * @param lst list
 * @param new node to add.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);
/**
 * @brief a 'lst' node as a parameter and releases the
memory of the content using the 'del' function
given as a parameter, in addition to releasing the node. The
'next' memory should not be freed.
 *
 * @param lst no the to free.
 * @param del a pointer to function used to free.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*));
/**
 * @brief delete and free the given 'lst' node and all
consecutive of that node, using the function
'del' and free.
 *
 * @param lst list node
 * @param del pointer to function del.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*));
/**
 * @brief iterates the list 'lst' and applies the function 'f' on the
content of each node
 *
 * @param lst list gived.
 * @param f function to apply.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));
/**
 * @brief counts number of nodes of a list.
 *
 * @param lst list gived.
 * @return int number of nodes.
 */
int		ft_lstsize(t_list *lst);

void	ft_free_all(char **s);
char	*get_next_line(int fd);
int		ft_check_newline(char *buff);
void	ft_join_to_stash(char **stash, char	*buff, int nread);
void	ft_clean_the_corpse(char **stash, int i);

#endif
