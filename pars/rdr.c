/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:07:02 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/09 04:56:05 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

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
	else if (t->s[t->i] == t->a && !cots_check(t->s, 0, t->i))
	{
		local[t->j++] = ' ';
		local[t->j++] = t->a;
		local[t->j++] = ' ';
		t->i++;
	}
}

static char	*add_space_rdr(char *s)
{
	t_tmp	t;
	char	*tmp;

	tmp = malloc(ft_strlen(s) + ft_isrdr(s) + ft_isrdr(s) + 1);
	ft_bzero(&t, sizeof(t_tmp) * 1);
	t.s = s;
	while (s[t.i])
	{
		if ((s[t.i] == '>' || s[t.i] == '<') && !cots_check(s, 0, t.i))
			t.a = s[t.i];
		if (t.a == '>' && !cots_check(s, 0, t.i))
			t.b = '<';
		else if (t.a == '<' && !cots_check(s, 0, t.i))
			t.b = '>';
		if (!cots_check(s, 0, t.i))
			condition(&t, &tmp);
		if (s[t.i] == t.a && s[t.i + 1] == t.a)
			t.i = t.i + 2;
		if (s[t.i] == '\0')
			break ;
		tmp[t.j++] = s[t.i++];
	}
	tmp[t.j] = 0;
	free(s);
	return (tmp);
}

char	**add_rdr_spaces(char **tmp)
{
	int		i;

	i = 0;
	while (tmp[i])
	{
		tmp[i] = add_space_rdr(tmp[i]);
		i++;
	}
	return (tmp);
}

static void	rdr_remove(t_cmd *c, int k, int j, char **tmp)
{
	if (!c->args || *c->args == NULL)
		return ;
	tmp = malloc(sizeof(char *) * (ft_strlen_2d(c->args) - crdr(c->args) + 1));
	ft_bzero(tmp, sizeof(char *) * (ft_strlen_2d(c->args) - crdr(c->args) + 1));
	while (c->args[k])
	{
		if ((c->args[k][0] == '>' || c->args[k][0] == '<') \
		&& (c->args[k][1] != '>' || c->args[k][1] != '<'))
		{
			k = k + 2;
			if (k - 2 == ft_strlen_2d(c->args) - 1)
				k--;
			continue ;
		}
		tmp[j++] = ft_strdup(c->args[k++]);
	}
	free_2d_array(c->args);
	c->args = tmp;
}

void	clean_rdrs(t_ms *m, t_cmd *c, int i)
{
	int		rdr;

	rdr = 0;
	if (!c->args)
		return ;
	while (c->args[i] && crdr(c->args) > 0)
	{
		if (c->args[i][0] == '<' && c->args[i][1] == '<')
			c->rdr[rdr].rdr_type = herdock;
		else if (c->args[i][0] == '>' && c->args[i][1] == '>')
			c->rdr[rdr].rdr_type = append;
		else if (c->args[i][0] == '>')
			c->rdr[rdr].rdr_type = output;
		else if (c->args[i][0] == '<')
			c->rdr[rdr].rdr_type = input;
		if (c->rdr[rdr].rdr_type != 0)
			rdr_remove_helper(c, m, i, rdr++);
		i++;
	}
	rdr_remove(c, 0, 0, NULL);
}
