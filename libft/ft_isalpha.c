/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:28:36 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/08 05:29:19 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int	re;

	re = 1;
	if (c < 'A' || (c > 'Z' && c < 'a') || c > 'z')
		re = 0;
	return (re);
}

int	ft_isdigit(int c)
{
	int	re;

	re = 0;
	if (c >= '0' && c <= '9')
		re = 1;
	return (re);
}

int	ft_isalpha(int s)
{
	if ((s >= 'a' && s <= 'z')
		|| (s >= 'A' && s <= 'Z'))
		return (1);
	else
		return (0);
}

int	ft_is_expn(char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
	{
		if (c[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

int	next_isalnum(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '$')
		{
			i++;
			j++;
			while (s[i] \
			&& (s[i] == '?' || ft_isalpha(s[i]) == 1 \
			|| ft_isdigit(s[i]) == 1 || s[i] == '_'))
			{
				j++;
				i++;
			}
			return (j);
		}
		i++;
	}
	return (i);
}

int	index_expn(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '$')
			return (i);
		i++;
	}
	return (i);
}
