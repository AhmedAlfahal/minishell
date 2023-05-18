/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:32:00 by hmohamed          #+#    #+#             */
/*   Updated: 2023/05/18 08:29:23 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_pipes(t_ms *m)
{
	m->c_cmds = 0;
	m->cmds = malloc(sizeof(t_cmd) * (m->counters->pipes + 2));
	ft_bzero(m->cmds, sizeof(t_cmd) * (m->counters->pipes + 2));
}

static void	init_counter(t_ms *m, char **env)
{
	m->error_code = 0;
	m->counters = malloc(sizeof(t_c));
	ft_bzero(m->counters, sizeof(t_c));
	dupper_2d(m, env);
	init_envlist(m, env);
	m->c_cmds = 0;
}

static void	exiting(t_ms *m)
{
	int	code;

	code = m->error_code;
	if (!m->rdln)
		printf("exit\n");
	else if (ft_strlen(m->rdln) == 4 && !ft_strncmp("exit", m->rdln, 4))
		printf("exit\n");
	free_all(m, 1);
	exit(code);
}

void	handler(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		return ;
	}
	if (signal == SIGQUIT)
		return ;
}

int	main(int ac, char **av, char **env)
{
	t_ms	m;

	ac_exiting(ac, av);
	m.error_code = 0;
	init_counter(&m, env);
	while (1)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, handler);
		m.error = 0;
		m.rdln = readline("minishell$:");
		add_history(m.rdln);
		if ((ft_strlen(m.rdln) == 4 && !ft_strncmp("exit", m.rdln, 4)) \
		|| !m.rdln)
			exiting(&m);
		pars(&m);
		if (m.error == 0)
			exce(&m);
		free_all(&m, 0);
	}
	free_all(&m, 1);
	return (0);
}
