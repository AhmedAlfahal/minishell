/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isexpan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:17:46 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/14 10:10:50 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static void	next_isalnum_helper(t_vars *t, char *s)
{
	t->i++;
	t->j++;
	while (s[t->i] \
	&& (s[t->i] == '?' || ft_isalpha(s[t->i]) == 1 \
	|| ft_isdigit(s[t->i]) == 1 \
	|| s[t->i] == '_' || s[t->i + 1] == '"' || s[t->i + 1] == '\''))
	{
		t->j++;
		t->i++;
	}
}

int	next_isalnum(char *s, int ignored)
{
	t_vars	t;

	ft_bzero(&t, sizeof(t_vars));
	if (!s)
		return (0);
	while (s[t.i])
	{
		if (s[t.i] == '$' && t.k != ignored)
		{
			t.i++;
			t.k++;
		}
		else if (s[t.i] == '$' && t.k == ignored)
		{
			next_isalnum_helper(&t, s);
			if (s[t.i] == '"' || s[t.i] == '\'')
				t.i--;
			return (t.i);
		}
		t.i++;
	}
	return (t.i);
}

int	index_expn(char *s, int ignored)
{
	t_vars	t;

	ft_bzero(&t, sizeof(t_vars));
	if (!s)
		return (0);
	while (s[t.i])
	{
		if (s[t.i] == '$' && t.j != ignored)
		{
			t.i++;
			t.j++;
		}
		else if (s[t.i] == '$')
			return (t.i);
		t.i++;
	}
	return (t.i);
}
