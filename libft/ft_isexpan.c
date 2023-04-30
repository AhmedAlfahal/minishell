/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isexpan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:17:46 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/22 20:15:52 by aalfahal         ###   ########.fr       */
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
	if ((c[t->i] == '$' && c[t->i + 1] == '$' && t->flag == 1 && t->cot == '"') \
	|| (c[t->i] == '$' && c[t->i + 1] == '$' && t->flag != 1))
	{
		t->i += 2;
		t->j = 1;
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
		if (t.j == 1)
		{
			t.j = 0;
			continue ;
		}
		else if (c[t.i] == '$' && next_isalnum(&c[t.i]) == 1)
		{
			t.i++;
			continue ;
		}
		else if (((c[t.i] == '$' && t.flag == 1 && t.cot == '"') \
		|| (c[t.i] == '$' && t.flag != 1)))
			return (1);
		t.i++;
	}
	return (0);
}

static void	next_isalnum_helper(char *s, int *i)
{
	while (s[*i] && (ft_isalpha(s[*i]) == 1 || ft_isdigit(s[*i]) == 1 \
	|| s[*i] == '_'))
		*i = *i + 1;
}

int	next_isalnum(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '$')
		{
			i++;
			if (s[i] == '?')
				return (++i);
			next_isalnum_helper(s, &i);
			if (s[i - 1] == '"' || s[i - 1] == '\'')
				i--;
			return (i);
		}
		i++;
	}
	return (i);
}

int	index_expn(char *s)
{
	t_vars	t;

	ft_bzero(&t, sizeof(t_vars));
	if (!s)
		return (0);
	while (s[t.i])
	{
		if (s[t.i] == '$' && s[t.i + 1] == '$')
		{
			t.i += 2;
			continue ;
		}
		else if (s[t.i] == '$' && next_isalnum(&s[t.i]) == 1)
		{
			t.i++;
			continue ;
		}
		else if (s[t.i] == '$')
			return (t.i);
		t.i++;
	}
	return (t.i);
}
