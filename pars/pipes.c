/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:39:51 by aalfahal          #+#    #+#             */
/*   Updated: 2023/03/30 09:00:33 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipes_error(t_ms *m)
{
	int	i;

	i = 0;
	m->error = 0;
	if ((m->c_cmds == m->counters->pipes) \
	|| (ft_strlen(m->rdln) == 1 && m->rdln[0] == '|'))
		m->error = 1;
	while (m->cmds[i].args != NULL && i + 1 != m->c_cmds)
	{
		if ((m->cmds[i].args[0] == 0 && m->cmds[i + 1].args[0] != 0) \
		|| m->cmds[m->c_cmds - 1].args[0] == 0)
			m->error = 1;
		i++;
	}
	if (m->error == 1 || cots_check(m->rdln, 0, ft_strlen(m->rdln)))
		write(2, "Syntax Error\n", 14);
}

void	pars(t_ms *m)
{
	char	**tmp;

	m->c_cmds = 0;
	tmp = ft_split(m->rdln, '|');
	m->cmds = malloc(sizeof(t_cmd) * (m->counters->pipes + 3));
	ft_bzero(m->cmds, sizeof(t_cmd) * (m->counters->pipes + 3));
	while (tmp[m->c_cmds])
	{
		m->cmds[m->c_cmds].args = ft_split(tmp[m->c_cmds], ' ');
		m->c_cmds++;
	}
	print_pipes(m);
	pipes_error(m);
	free_2d_array(tmp);
}
