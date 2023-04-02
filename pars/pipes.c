/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:39:51 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/02 06:18:34 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_rdrs(t_cmd *c)
{
	// int	i;

	// i = 0;
	malloc_rdrs(c);
	if (c->c_rdr == 0)
	{
		free(c->rdr);
		return ;
	}
	clean_rdrs(c, 0, 0);
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

static void	clean_cots(t_cmd *c)
{
	int		i;
	char	*s;

	i = 0;
	s = NULL;
	while (c->args[i])
	{
		if (c->args[i][0] == '"')
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
		if ((m->cmds[i].args[0] == 0 && m->cmds[i + 1].args[0] != 0) \
		|| m->cmds[m->c_cmds - 1].args[0] == 0)
			m->error = 1;
		i++;
	}
	if (m->error == 1)
		write(2, "syntax error near unexpected token\n", 36);
}

void	pars(t_ms *m)
{
	char	**tmp;

	m->c_cmds = 0;
	tmp = ft_split(m->rdln, '|');
	while (tmp[m->c_cmds] && m->counters->error != 1)
		check_rdr_error(tmp[m->c_cmds++], m->counters);
	m->c_cmds = 0;
	m->cmds = malloc(sizeof(t_cmd) * (m->counters->pipes + 3));
	ft_bzero(m->cmds, sizeof(t_cmd) * (m->counters->pipes + 3));
	while (tmp[m->c_cmds] && m->counters->error != 1)
	{
		m->cmds[m->c_cmds].args = ft_split(tmp[m->c_cmds], ' ');
		check_rdrs(&m->cmds[m->c_cmds]);
		clean_cots(&m->cmds[m->c_cmds]);
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
