/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 05:36:32 by aalfahal          #+#    #+#             */
/*   Updated: 2023/03/28 05:39:17 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static void	init_all(t_ms *m)
{
	m->counters = malloc(sizeof(t_c));
	ft_bzero(m->counters, sizeof(t_c));
	count(m->counters, m->rdln);
	ft_bzero(m->counters, sizeof(t_c));
}

int	main(int ac, char **av, char **env)
{
	t_ms	m;

	(void)ac;
	(void)av;
	while (1)
	{
		m.rdln = readline("minishell$:");
		if (ft_strlen(m.rdln) == 4 && !ft_strncmp("exit", m.rdln, 4))
			exit(0);
		dupper_2d(&m, env);
		init_all(&m);
		free_all(&m);
	}
	return (0);
}

// if s[i] == '\'' || '"'
// 	if(!flag)
// 		flag = s[i];
// 	else if(flag == s[i])
// 		 flag = 0;
