/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:38:40 by aalfahal          #+#    #+#             */
/*   Updated: 2023/03/29 00:54:05 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_2d_array(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s[i]);
	free(s);
}

static void	free_cmds(t_ms *m)
{
	int	i;

	i = 0;
	while (m->cmds[i].args != NULL)
		free_2d_array(m->cmds[i++].args);
	free(m->cmds);
}

void	free_all(t_ms *m, int exit)
{
	if (exit == 0)
	{
		free_cmds(m);
		return ;
	}
}
