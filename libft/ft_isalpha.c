/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:28:36 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/13 22:36:38 by hmohamed         ###   ########.fr       */
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

static void	ft_is_expn_helper(t_vars *t, char *c)
{
	if (c[t->i] == '"' || c[t->i] == '\'')
	{
		if (t->flag == 0)
		{
			t->cot = c[t->i];
			t->flag = 1;
		}
		else if (t->flag == 1 && t->cot == c[t->i])
		{
			t->cot = 0;
			t->flag = 0;
		}
	}
}

int	ft_is_expn(char *c)
{
	t_vars	t;

	ft_bzero(&t, sizeof(t_vars));
	if (!c)
		return (0);
	while (c[t.i])
	{
		ft_is_expn_helper(&t, c);
		if (c[t.i] == '$' && t.flag == 1 && t.cot == '"')
			return (1);
		else if (c[t.i] == '$' && t.flag != 1)
			return (1);
		t.i++;
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
			&& (s[i] == '?' || ft_isalpha(s[i]) == 1 || ft_isdigit(s[i]) == 1 \
			|| s[i] == '_' || s[i] == '"' || s[i] == '\''))
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