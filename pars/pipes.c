/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:39:51 by aalfahal          #+#    #+#             */
/*   Updated: 2023/05/18 08:27:12 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	remove_cots(char *s)
{
	t_tmp	t;

	ft_bzero(&t, sizeof(t_tmp));
	if (!s)
		return ;
	while (s[t.i])
	{
		if (s[t.i] == '\'' || s[t.i] == '"')
		{
			if (!t.a)
				t.a = s[t.i];
			else if (t.a == s[t.i])
				t.a = 0;
			else
				s[t.j++] = s[t.i];
		}
		else
			s[t.j++] = s[t.i];
		t.i++;
	}
	s[t.j] = '\0';
}

static void	clean_cots(t_cmd *c)
{
	int	i;

	i = 0;
	while (c->args[i])
	{
		remove_cots(c->args[i]);
		i++;
	}
}

static void	clean_rdrs(t_cmd *c)
{
	int		i;
	int		rdr;

	i = 0;
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
		{
			c->rdr[rdr].file_name = ft_strdup(c->args[i + 1]);
			remove_cots(c->rdr[rdr++].file_name);
		}
		i++;
	}
	rdr_remove(c);
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
		clean_rdrs(&m->cmds[m->c_cmds]);
		clean_cots(&m->cmds[m->c_cmds]);
		m->c_cmds++;
	}
	if (m->counters->error == 1)
	{
		free_2d_array(tmp);
		return ;
	}
	free_2d_array(tmp);
}
