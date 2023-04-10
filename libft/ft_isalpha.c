/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:17:46 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/10 22:31:11 by aalfahal         ###   ########.fr       */
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
	int		i;
	char	cot;
	int		flag;

	flag = 0;
	cot = 0;
	i = 0;
	if (!c)
		return (0);
	while (c[i])
	{
		if (c[i] == '"' || c[i] == '\'')
		{
			cot = c[i];
			if (flag == 0)
				flag = 1;
			else if (flag == 1)
				flag = 0;
		}
		if (c[i] == '$' && flag == 1 && cot == '\'')
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

// int	main(void)
// {
// 	printf("[%d]\n", next_isalnum("$USER....$USER"));
// }
