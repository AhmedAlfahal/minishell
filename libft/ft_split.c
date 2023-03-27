/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:27:29 by hmohamed          #+#    #+#             */
/*   Updated: 2022/12/30 14:56:10 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	w_len(const char *str, char s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*str)
	{
		if (*str != s && j == 0)
		{
			j = 1;
			i++;
		}
		else if (*str == s)
			j = 0;
		str++;
	}
	return (i);
}

static char	*wdup(const char *str, int i, int j, int *p)
{
	char	*s;
	int		a;

	a = 0;
	s = (char *)malloc((j - i + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (i < j)
	{
		s[a] = str[i];
		a++;
		i++;
	}
	s[a] = '\0';
	*p = -1;
	return (s);
}

char	**ft_split(char const *s, char c)
{
	char	**temp;
	size_t	i;
	int		j;
	int		a;
	size_t	slen;

	slen = ft_strlen(s);
	i = 0;
	j = -1;
	a = -1;
	if (!s)
		return (NULL);
	temp = malloc((w_len(s, c) + 1) * sizeof(char *));
	if (temp == NULL)
		return (0);
	while (i <= slen)
	{
		if (s[i] != c && a < 0)
			a = i;
		else if ((s[i] == c || s[i] == '\0') && a >= 0)
			temp[++j] = wdup(s, a, i, &a);
		i++;
	}
	temp[++j] = 0;
	return (temp);
}
