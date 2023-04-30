/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:07:02 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/30 11:43:36 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

static void	condition(t_tmp *t, char *s, char **tmp)
{
	char	*local;

	local = *tmp;
	if (s[t->i] == t->a && s[t->i + 1] == t->a)
	{
		local[t->j++] = ' ';
		local[t->j++] = t->a;
		local[t->j++] = t->a;
		local[t->j++] = ' ';
	}
	else if (s[t->i] == t->a && s[t->i + 1] == t->b)
	{
		local[t->j++] = ' ';
		local[t->j++] = '<';
		local[t->j++] = '>';
		local[t->j++] = ' ';
	}
	else if (s[t->i] == t->a && !cots_check(s, 0, t->i))
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
	if (!tmp)
		return (NULL);
	ft_bzero(&t, sizeof(t_tmp) * 1);
	while (s[t.i])
	{
		if ((s[t.i] == '>' || s[t.i] == '<') && cots_check(s, 0, t.i) == 0)
			t.a = s[t.i];
		if (t.a == '>' && cots_check(s, 0, t.i) == 0)
			t.b = '<';
		else if (t.a == '<' && cots_check(s, 0, t.i) == 0)
			t.b = '>';
		if (cots_check(s, 0, t.i) == 0)
			condition(&t, s, &tmp);
		if (s[t.i] == t.a && s[t.i + 1] == t.a && cots_check(s, 0, t.i) == 0)
			t.i = t.i + 2;
		if (s[t.i] == '\0')
			break ;
		tmp[t.j++] = s[t.i++];
	}
	tmp[t.j] = 0;
	return (free(s), tmp);
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

void	rdr_remove(t_cmd *c)
{
	t_tmp	t;
	char	**tmp;

	ft_bzero(&t, sizeof(t_tmp));
	tmp = NULL;
	if (!c->args || *c->args == NULL)
		return ;
	tmp = malloc(sizeof(char *) * (ft_strlen_2d(c->args) - crdr(c->args) + 1));
	if (!tmp)
		return ;
	ft_bzero(tmp, sizeof(char *) * (ft_strlen_2d(c->args) - crdr(c->args) + 1));
	while (c->args[t.i])
	{
		if ((c->args[t.i][0] == '>' || c->args[t.i][0] == '<') \
		&& (c->args[t.i][1] != '>' || c->args[t.i][1] != '<'))
		{
			t.i = t.i + 2;
			if (t.i - 2 == ft_strlen_2d(c->args) - 1)
				t.i--;
			continue ;
		}
		tmp[t.j++] = ft_strdup(c->args[t.i++]);
	}
	free_2d_array(c->args);
	c->args = tmp;
}
