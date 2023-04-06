/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:39:51 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/07 01:50:40 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_cots(t_cmd *c, int i, int j, int k)
{
	char	*tmp;

	tmp = NULL;
	while (c->args[i][j])
	{
		if (c->args[i][j] == '\'' || c->args[i][j] == '"')
			k++;
		j++;
	}
	tmp = malloc(sizeof(char) * (ft_strlen(c->args[i]) - k + 1));
	ft_bzero(tmp, sizeof(char) * (ft_strlen(c->args[i]) - k + 1));
	j = 0;
	k = 0;
	while (c->args[i][j])
	{
		if (c->args[i][j] != '\'' && c->args[i][j] != '"')
			tmp[k++] = c->args[i][j];
		j++;
	}
	tmp[k] = 0;
	free(c->args[i]);
	c->args[i] = tmp;
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
	char	*s;

	s = NULL;
	while (c->args[i])
	{
		if ((c->args[i][0] == '"' \
		&& c->args[i][ft_strlen(c->args[i]) - 1] == '\'') \
		|| (c->args[i][0] == '\'' \
		&& c->args[i][ft_strlen(c->args[i]) - 1] == '"'))
			remove_cots(c, i, 0, 0);
		else if (c->args[i][0] == '"')
		{
			s = ft_strtrim(c->args[i], "\"");
			free(c->args[i]);
			c->args[i] = s;
		}
		else if (c->args[i][0] == '\'')
		{
			s = ft_strtrim(c->args[i], "\'");
			free(c->args[i]);
			c->args[i] = s;
		}
		i++;
	}
}

static void	pipes_error(t_ms *m)
{
	int	i;

	i = 0;
	m->error = 0;
	if ((m->c_cmds == m->counters->pipes && m->c_cmds != 0) \
	|| (ft_strlen(m->rdln) == 1 && m->rdln[0] == '|') \
	|| cots_check(m->rdln, 0, ft_strlen(m->rdln)))
		m->error = 1;
	while (m->cmds[i].args != NULL && i + 1 != m->c_cmds)
	{
		if ((m->cmds[i].args[0] == 0 && m->cmds[i + 1].args[0] != 0 \
		&& m->cmds[i].c_rdr == 0) || (m->cmds[m->c_cmds - 1].args[0] == 0 \
		&& m->cmds[m->c_cmds - 1].c_rdr == 0))
			m->error = 1;
		i++;
	}
	if (m->error == 1)
		write(2, "syntax error near unexpected token\n", 36);
}

void	pars(t_ms *m)
{
	char	**tmp;

	tmp = ft_split(m->rdln, '|');
	while (tmp[m->c_cmds] && m->counters->error != 1)
		check_rdr_error(tmp[m->c_cmds++], m->counters);
	if (m->counters->error != 1)
		tmp = add_rdr_spaces(tmp);
	init_pipes(m);
	while (tmp[m->c_cmds] && m->counters->error != 1)
	{
		m->cmds[m->c_cmds].args = ft_split(tmp[m->c_cmds], ' ');
		malloc_rdrs(&m->cmds[m->c_cmds]);
		clean_rdrs(&m->cmds[m->c_cmds], 0);
		clean_cots(&m->cmds[m->c_cmds], 0);
		m->c_cmds++;
	}
	print_pipes(m);
	if (m->counters->error == 1)
	{
		free_2d_array(tmp);
		return ;
	}
	pipes_error(m);
	free_2d_array(tmp);
}
