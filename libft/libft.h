/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:15:57 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/30 17:12:39 by aalfahal         ###   ########.fr       */
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
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_ispace(char *s);
int		next_isalnum(char *s);
int		ft_is_expn(char *c);
int		index_expn(char *s);
char	*ft_stolower(char *str);
int		ft_cotlen(char *s);
void	ft_cut(char **s, int start, int end);
int		ft_wospace_len(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *str, int c);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
int		ft_isrdr(char *s);
int		crdr(char **s);
int		cots_check(char *s, int start, int end);
int		ft_strlen_2d(char **s);

/*********************************--Part Two--*********************************/

long	ft_atol(const char *str);
char	*ft_itoa(int n);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin2(char const *s1, char const *s2);
char	*ft_strjoin3(char const *s1, char const *s2);
char	*ft_strjoin4(char const *s1, char const *s2, char c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putstr_fd(char *s, int fd);

#endif
