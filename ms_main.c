/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:32:00 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/02 23:45:25 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_all(t_ms *m, char **env)
{
	m->counters = malloc(sizeof(t_c));
	ft_bzero(m->counters, sizeof(t_c));
	init_envlist(m, env);
}

static void	f_free(t_ms *m)
{
	ft_lstclear(&m->envd);
	ft_lstclear(&m->expd);
	free(m->counters);
}

int	main(int ac, char **av, char **env)
{
	t_ms	m;

	(void)ac;
	(void)av;
	dupper_2d(&m, env);
	init_all(&m, env);
	while (1)
	{
		m.rdln = readline("minishell$:");
		add_history(m.rdln);
		if (ft_strlen(m.rdln) == 4 && !ft_strncmp("exit", m.rdln, 4))
			break ;
		count(m.counters, m.rdln);
		pars(&m);
		if (m.error != 1)
			exce(&m);
		free_all(&m, 0);
	}
	f_free(&m);
	return (0);
}
