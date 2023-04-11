/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:39:51 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/11 13:25:53 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	remove_cots(char **s, t_tmp *t, char cot)
{
	char	*tmp;
	char	*c;

	tmp = NULL;
	ft_bzero(t, sizeof(t_tmp) * 1);
	c = *s;
	while (c[t->j])
	{
		if (c[t->j] == cot)
			t->x++;
		t->j++;
	}
	tmp = malloc(sizeof(char) * (ft_strlen(c) - t->x + 1));
	ft_bzero(tmp, sizeof(char) * (ft_strlen(c) - t->x + 1));
	t->j = 0;
	t->x = 0;
	while (c[t->j])
	{
		if (c[t->j] != cot)
			tmp[t->x++] = c[t->j];
		t->j++;
	}
	tmp[t->x] = 0;
	free(*s);
	*s = tmp;
}

int	cots_check(char *s, int start, int end)
{
	int		l;
	char	p;

	if (!s)
		return (0);
	l = 0;
	p = 0;
	while (start < end)
	{
		if ((s[start] == '"' || s[start] == '\'') && l == 0)
		{
			p = s[start];
			start++;
			l = 1;
		}
		if (s[start] == p)
		{
			if (l == 1)
				l = 0;
			p = 0;
		}
		start++;
	}
	return (l);
}

static void	clean_cots(t_cmd *c, int i)
{
	t_tmp	t;

	while (c->args[i])
	{
		if (c->args[i][0] == '"' \
		&& c->args[i][ft_strlen(c->args[i]) - 1] == '"')
			remove_cots(&c->args[i], &t, '"');
		else if (c->args[i][0] == '\'' \
		&& c->args[i][ft_strlen(c->args[i]) - 1] == '\'')
			remove_cots(&c->args[i], &t, '\'');
		else if (ft_cotlen(c->args[i]) > 0)
		{
			remove_cots(&c->args[i], &t, '\'');
			remove_cots(&c->args[i], &t, '"');
		}
		i++;
	}
}

void	pars(t_ms *m)
{
	char	**tmp;

	count(m->counters, m->rdln);
	check_rdr_error(m, m->rdln);
	tmp = ft_split(m->rdln, '|');
	if (m->counters->error != 1)
		tmp = add_rdr_spaces(tmp);
	init_pipes(m);
	while (tmp[m->c_cmds] && m->counters->error != 1)
	{
		m->cmds[m->c_cmds].args = ft_split(tmp[m->c_cmds], ' ');
		clean_expantion(&m->cmds[m->c_cmds], m);
		malloc_rdrs(&m->cmds[m->c_cmds]);
		clean_rdrs(&m->cmds[m->c_cmds], 0);
		clean_cots(&m->cmds[m->c_cmds], 0);
		m->c_cmds++;
	}
	if (m->counters->error == 1)
	{
		free_2d_array(tmp);
		return ;
	}
	free_2d_array(tmp);
}
