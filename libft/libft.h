/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunez-n <enunez-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:25:49 by enunez-n          #+#    #+#             */
/*   Updated: 2022/08/29 16:52:01 by enunez-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 43

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// basic functions

int					ft_atoi(const char *str);
void				*ft_bzero(void *b, unsigned long len);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s1);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);

// lists functions (bonus)

void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);

//ft_printf.c functions:
int					ft_printf(const char *format, ...);
void				ft_evaluator(const char conversion, va_list args,
						int *printlen);

// printchars.c functions:
int					ft_printchar(int c);
int					ft_printstring(char *str);

// printdigits.c functions:
int					ft_printdec(long num);
int					ft_printudec(unsigned long n);
int					ft_countdec(long num);

// printhexa.c functions:
int					ft_basehexa(unsigned long long num, int up);
int					ft_printptr(uintptr_t ptr);

// Get_Next_Line

char				*ft_newstr(void);
char				*get_next_line(int fd);
char				*ft_save_buffer(int fd, char *buffsave);
char				*ft_get_line(char *buffsave);
char				*ft_clean_save(char *buffsave);
char				*ft_newstr_get(void);
char				*ft_strchr_get(char *s, int c);
char				*ft_strjoin_get(char *s1, char *s2);

#endif