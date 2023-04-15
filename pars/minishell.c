/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 05:36:32 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/15 03:34:59 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_pipes(t_ms *m)
{
	m->c_cmds = 0;
	m->cmds = malloc(sizeof(t_cmd) * (m->counters->pipes + 2));
	ft_bzero(m->cmds, sizeof(t_cmd) * (m->counters->pipes + 2));
}

static void	init_counter(t_ms *m, char **env)
{
	m->counters = malloc(sizeof(t_c));
	ft_bzero(m->counters, sizeof(t_c));
	dupper_2d(m, env);
	init_envlist(m, env);
	m->c_cmds = 0;
}

void	f_free(t_ms *m)
{
	ft_lstclear(&m->envd);
	ft_lstclear(&m->expd);
}

int	main(int ac, char **av, char **env)
{
	t_ms	m;

	(void)ac;
	(void)av;
	m.error_code = 0;
	init_counter(&m, env);
	while (1)
	{
		m.error = 0;
		m.rdln = readline("minishell$:");
		if (!m.rdln)
			return (printf("exit\n"), 0);
		add_history(m.rdln);
		if (ft_strlen(m.rdln) == 4 && !ft_strncmp("exit", m.rdln, 4))
			break ;
		pars(&m);
		// if (m.error == 0)
		// 	exce(&m);
		free_all(&m, 0);
	}
	f_free(&m);
	free_all(&m, 1);
	return (0);
}
