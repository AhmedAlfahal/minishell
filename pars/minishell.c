/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 05:36:32 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/06 06:11:10 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_pipes(t_ms *m)
{
	m->c_cmds = 0;
	m->cmds = malloc(sizeof(t_cmd) * (m->counters->pipes + 2));
	ft_bzero(m->cmds, sizeof(t_cmd) * (m->counters->pipes + 2));
}

static void	init_counter(t_ms *m)
{
	m->counters = malloc(sizeof(t_c));
	ft_bzero(m->counters, sizeof(t_c));
	m->c_cmds = 0;
}

int	main(int ac, char **av, char **env)
{
	t_ms	m;

	(void)ac;
	(void)av;
	dupper_2d(&m, env);
	init_counter(&m);
	while (1)
	{
		m.rdln = readline("minishell$:");
		add_history(m.rdln);
		if (ft_strlen(m.rdln) == 4 && !ft_strncmp("exit", m.rdln, 4))
			break ;
		count(m.counters, m.rdln);
		pars(&m);
		m.c_cmds = 0;
		free_all(&m, 0);
	}
	free(m.counters);
	free_2d_array(m.env);
	return (0);
}
