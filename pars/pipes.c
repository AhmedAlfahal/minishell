/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:39:51 by aalfahal          #+#    #+#             */
/*   Updated: 2023/03/28 23:59:44 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	pars(t_ms *m)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_split(m->rdln, '|');
	m->cmds = malloc(sizeof(t_cmd) * (m->counters->pipes + 3));
	ft_bzero(m->cmds, sizeof(t_cmd) * (m->counters->pipes + 3));
	while (tmp[i])
	{
		m->cmds[i].args = ft_split(tmp[i], ' ');
		i++;
	}
	print_pipes(m);
	free_2d_array(tmp);
}
