/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 20:10:52 by xperrin           #+#    #+#             */
/*   Updated: 2019/08/27 20:59:05 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <limits.h>
# include <inttypes.h>

# include "get_next_line.h"

# define M_GREEN "\033[1;32m"
# define M_YELLOW "\033[1;33m"
# define M_RED "\033[1;31m"
# define M_END "\033[0m"

# define CLR_SCR "\033[1;1H\033[2J"

# define ITOA_BUF 22
# define ITOA_B_BUF 66

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** part 1
*/
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *src, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
int					ft_atoi(const char *str);
int					ft_isalpha(int chr);
int					ft_isdigit(int chr);
int					ft_isalnum(int chr);
int					ft_isascii(int chr);
int					ft_isprint(int chr);
int					ft_toupper(int chr);
int					ft_tolower(int chr);
/*
** part 2
*/
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
/*
** bonus part
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstappend(t_list **alst, t_list *new);
t_list				*ft_lstnewl(void **ptr);
/*
** My string functions
*/
char				*ft_strprecat(char *dst, const char *src);
int					ft_islower(int chr);
int					ft_isupper(int chr);
int					ft_cntword(char const *s, char c);
size_t				ft_strrlen(char const *s, char c);
char				*ft_strndup(char const *s, size_t n);
char				*ft_strupcase(char *s);
char				*ft_strlowcase(char *s);
char				*ft_itoa_b(intmax_t n, char *base);
char				*ft_utoa_b(uintmax_t n, char *base);
void				ft_itoa_bs(char *buf, intmax_t n, char *base);
void				ft_utoa_bs(char *buf, uintmax_t n, char *base);
/*
** My memory functions
*/
void				ft_swap(void *a, void *b, size_t size);
/*
** My swap functions
*/
void				ft_bubblesort(void *base, size_t nemmb, size_t size,
								int (*cmp)(const void *, const void *));
/*
** My leak-free functions
*/
char				*ft_strjoinfreea(char *s1, char *s2);
char				*ft_strjoinfreeb(char *s1, char *s2);
char				*ft_strsubfree(char *s, unsigned int start, size_t len);
void				ft_freearray(void **array, size_t nmemb);
void				ft_strdeltab(char **tab, size_t tab_len);
/*
** My math functions
*/
int					ft_cntdigit(int n);
int					ft_cntdigt_b(intmax_t n, size_t radix);
int					ft_pow(int x, int y);
int					ft_sqrt(int x);
/*
** My rand function
*/
int					ft_rand(size_t bits);

#endif
