/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:32:42 by hbigourd          #+#    #+#             */
/*   Updated: 2024/01/14 01:57:54 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <errno.h>
# include <pthread.h>
# include <stdint.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100 
# endif

# ifndef NB_FILE_MAX
#  define NB_FILE_MAX 100
# endif

typedef struct s_split_info
{
	char	*set;
	size_t	i;
	size_t	j;
	char	*ss_tab;
	char	*s1;
	size_t	nb_list;
	char	tmp_set[2];
}			t_split_info;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void		*ft_memchr(void const *str, int c, size_t n);
void		*ft_memset(void *pointer, int value, size_t count);
void		*ft_memcpy(void *dest, void const *src, size_t size);
void		*ft_memccpy(void *dest, void const *src, int c, size_t size);
int			ft_memcmp(void const *pointer1, void const *pointer2, size_t size);
void		*ft_memmove(void *dest, void const *src, size_t size);
int			ft_atoi(char const *str);
char		*ft_itoa(int to_conv);
int			ft_isalpha(int nb);
char		**ft_split(char const *str, char sep);
char		*ft_strdup(char *src);
size_t		ft_strlen(char const *str);
int			ft_strncmp(char const *s1, char const *s2, size_t n);
int			ft_isdigit(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		ft_bzero(void *s, size_t n);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isalnum(int c);
char		*ft_strtrim(char const *s1, char const *set);
void		*ft_calloc(size_t nmemb, size_t size);
size_t		ft_strlcat(char *dest, char const *src, size_t n);
size_t		ft_strlcpy(char *dest, char const *src, size_t n);
char		*ft_strmapi(char const *str, char (*f)(unsigned int, char));
char		*ft_strchr(char const *str, int searchedChar);
char		*ft_strrchr(char const *str, int searchedChar);
char		*ft_strnstr(char const *big, char const *little, size_t len);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *str, char const *sep);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_front(t_list **lsts, t_list *n_lst);
void		ft_lstadd_back(t_list **lsts, t_list *n_lst);
int			ft_lstsize(t_list *lst);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lsts, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int			is_number_too_large(char *str);

char		*get_next_line(int fd);
int			ft_read(char **line, int fd);
char		*ft_strjoin_custom(char *reading, char *tmp);
size_t		ft_strlen_custom(const char *str);
int			ft_strchr_custom(const char *s, int c);
size_t		ft_strlcpy_custom(char *dest, char *src, size_t size);
char		*ft_strdup_custom(char *s);

#endif
