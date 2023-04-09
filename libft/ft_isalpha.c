/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:17:46 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/09 05:50:47 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>

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
			while (s[i] && (ft_isalpha(s[i]) == 1 || ft_isdigit(s[i]) == 1))
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

// int	main(void)
// {
// 	printf("[%d]\n", next_isalnum("$USER....$USER"));
// }
