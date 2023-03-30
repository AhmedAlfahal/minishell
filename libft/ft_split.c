/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:00:46 by aalfahal          #+#    #+#             */
/*   Updated: 2023/03/30 09:05:16 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	sep_count(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] != c && (s[j + 1] == c || s[j + 1] == '\0') \
		&& cots_check(s, 0, j + 1) == 0)
			i++;
		j++;
	}
	return (i);
}

static size_t	next_sep(char *s, char c, int i)
{
	while (s[i])
	{
		if (s[i] == c && cots_check(s, 0, i) == 0)
			return (i);
		i++;
	}
	return (ft_strlen(s));
}

char	**ft_split(char *s, char c)
{
	int		j;
	int		i;
	int		seps;
	char	**split;

	if (!s)
		return (NULL);
	j = 0;
	i = 0;
	seps = sep_count(s, c);
	split = (char **)malloc(sizeof(char *) * (seps + 1));
	if (!split)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (j < seps)
			split[j++] = ft_substr(s, i, next_sep(s, c, i));
		i = next_sep(s, c, i);
		while (s[i] != c && s[i])
			i++;
	}
	split[j] = 0;
	return (split);
}
