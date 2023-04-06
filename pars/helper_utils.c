/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:07:48 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/06 05:55:00 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	condition(t_tmp *t, char **tmp)
{
	char	*local;

	local = *tmp;
	if (t->s[t->i] == t->a && t->s[t->i + 1] == t->a)
	{
		local[t->j++] = ' ';
		local[t->j++] = t->a;
		local[t->j++] = t->a;
		local[t->j++] = ' ';
	}
	else if (t->s[t->i] == t->a && t->s[t->i + 1] == t->b)
	{
		local[t->j++] = ' ';
		local[t->j++] = '<';
		local[t->j++] = '>';
		local[t->j++] = ' ';
	}
	else if (t->s[t->i] == t->a)
	{
		local[t->j++] = ' ';
		local[t->j++] = t->a;
		local[t->j++] = ' ';
		t->i++;
	}
}

char	*malloc_rdr_space(char *s)
{
	t_tmp	t;
	char	*tmp;

	tmp = malloc(ft_strlen(s) + ft_isrdr(s) + ft_isrdr(s) + 1);
	ft_bzero(&t, sizeof(t_tmp) * 1);
	t.s = s;
	while (s[t.i])
	{
		if (s[t.i] == '>' || s[t.i] == '<')
			t.a = s[t.i];
		if (t.a == '>')
			t.b = '<';
		else if (t.a == '<')
			t.b = '>';
		condition(&t, &tmp);
		if ((s[t.i] == t.a && s[t.i + 1] == t.a) \
		|| (s[t.i] == t.a && s[t.i + 1] == t.a))
			t.i = t.i + 2;
		if (s[t.i] == '\0')
			break ;
		tmp[t.j++] = s[t.i++];
	}
	tmp[t.j] = 0;
	free(s);
	return (tmp);
}

static void	count_all_helper(char *rdln, int *i, t_c *counter)
{
	int	j;

	j = *i;
	if (rdln[*i] == '>' && cots_check(rdln, 0, j + 1) == 0)
	{
		counter->redirs++;
		counter->output++;
	}
	else if (rdln[*i] == '<' && rdln[*i + 1] == '<' \
	&& cots_check(rdln, 0, j + 1) == 0)
	{
		*i = *i + 1;
		counter->redirs++;
		counter->herdock++;
	}
	else if (rdln[*i] == '<' && cots_check(rdln, 0, j + 1) == 0)
	{	
		counter->redirs++;
		counter->input++;
	}
}

void	count(t_c *counter, char *rdln)
{
	int	i;

	i = 0;
	while (rdln[i])
	{
		if (rdln[i] == '|' && rdln[i + 1] == '|' \
		&& cots_check(rdln, 0, i + 1) == 0)
		{
			counter->pipes++;
			i = i + 1;
		}
		else if (rdln[i] == '|' && cots_check(rdln, 0, i + 1) == 0)
			counter->pipes++;
		else if (rdln[i] == '>' && rdln[i + 1] == '>' \
		&& cots_check(rdln, 0, i + 1) == 0)
		{
			counter->redirs++;
			counter->append++;
			i = i + 1;
		}
		else
			count_all_helper(rdln, &i, counter);
		i++;
	}
}

void	dupper_2d(t_ms *m, char **source)
{
	int	i;

	i = ft_strlen_2d(source);
	m->env = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (source[i])
	{
		m->env[i] = ft_strdup(source[i]);
		i++;
	}
	m->env[i] = NULL;
}
