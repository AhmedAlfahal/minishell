/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:29:55 by aalfahal          #+#    #+#             */
/*   Updated: 2023/03/30 23:41:49 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pars/minishell.h"

void	print_counters(t_c *counter)
{
	printf("input		%d\n", counter->input);
	printf("herdock		%d\n", counter->herdock);
	printf("output		%d\n", counter->output);
	printf("append		%d\n", counter->append);
	printf("redirs		%d\n", counter->redirs);
	printf("pipes		%d\n", counter->pipes);
}

void	print_pipes(t_ms *m)
{
	int	i;

	i = 0;
	while (m->cmds[i].args != NULL)
	{
		printf("pipe	%d	", i);
		print_2d_array(m->cmds[i].args);
		printf("\n");
		i++;
	}
}

void	print_2d_array(char **d)
{
	int	i;

	i = 0;
	while (d[i])
		printf("	[%s]	", d[i++]);
}
