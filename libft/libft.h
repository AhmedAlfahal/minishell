/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:15:57 by aalfahal          #+#    #+#             */
/*   Updated: 2023/03/31 22:09:36 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include"../minishell.h"
# include<stdlib.h>
# include<unistd.h>
# include<stdint.h>

/*********************************--Part One--*********************************/

int		ft_tolower(int s);
char	*ft_stolower(char *str);
int		ft_toupper(int s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlen_2d(char **s);

/*********************************--Part Two--*********************************/

char	*ft_itoa(int n);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**********************************--Bonus--***********************************/

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

// int		ft_lstsize(t_list *lst);
// void	ft_lstadd_front(t_list **lst, t_list (*new));
// void	ft_lstadd_back(t_list **lst, t_list (*new));
// t_list	*ft_lstlast(t_list *lst);
// t_list	*ft_lstnew(void *content);
// void	ft_lstdelone(t_list *lst);
// void	ft_lstclear(t_list **lst);


t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstiter(t_list *lst, void (*f)(int));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, int (*f)(int));

#endif
