/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:29:55 by aalfahal          #+#    #+#             */
/*   Updated: 2023/03/30 06:24:37 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pars/minishell.h"

void	print_counters(t_c *counter)
{
	printf("l_redir		%d\n", counter->l_redir);
	printf("ll_redir	%d\n", counter->ll_redir);
	printf("r_redir		%d\n", counter->r_redir);
	printf("rr_redir	%d\n", counter->rr_redir);
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
