/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:15:57 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/23 15:17:40 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include<stdlib.h>
# include<unistd.h>
# include<stdint.h>

/*********************************--Structs--**********************************/

typedef struct s_tmp_vars
{
	int		i;
	int		j;
	int		k;
	char	cot;
	int		flag;
}			t_vars;

/*********************************--Part One--*********************************/

int		ft_tolower(int s);
int		ft_toupper(int s);
int		ft_isdigit(int s);
int		ft_ispace(char *s);
int		ft_isalpha(int c);
int		next_isalnum(char *s);
int		ft_is_expn(char *c);
int		index_expn(char *s);
char	*ft_stolower(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_bzero(void *s, size_t n);
void	ft_cut(char **s, int start, int end);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);
int		ft_wospace_len(char *s);
int		ft_cotlen(char *s);
int		cots_check(char *s, int start, int end);
int		ft_strlen_2d(char **s);
int		ft_isrdr(char *s);
int		crdr(char **s);

/*********************************--Part Two--*********************************/

char	*ft_itoa(int n);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin2(char const *s1, char const *s2);
char	*ft_strjoin3(char const *s1, char const *s2);
char	*ft_strjoin4(char const *s1, char const *s2, char c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

#endif
