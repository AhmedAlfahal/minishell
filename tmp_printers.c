/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:29:55 by aalfahal          #+#    #+#             */
/*   Updated: 2023/03/29 22:42:20 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pars/minishell.h"

void	print_counters(t_c *counter)
{
	printf("bslsh		%d\n", counter->bslsh);
	printf("s_com		%d\n", counter->s_cot);
	printf("d_com		%d\n", counter->d_cot);
	printf("l_redir		%d\n", counter->l_redir);
	printf("ll_redir	%d\n", counter->ll_redir);
	printf("r_redir		%d\n", counter->r_redir);
	printf("rr_redir	%d\n", counter->rr_redir);
	printf("pipes		%d\n", counter->pipes);
	printf("smcln		%d\n", counter->smcln);
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
