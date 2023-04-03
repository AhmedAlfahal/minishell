/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:38:40 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/04 02:53:24 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_rdr(t_cmd s)
{
	int	i;

	i = 0;
	while (s.rdr[i].file_name)
		free(s.rdr[i++].file_name);
	free(s.rdr);
}

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
	{
		if (m->cmds[i].c_rdr != 0)
			free_rdr(m->cmds[i]);
		free_2d_array(m->cmds[i++].args);
	}
	free(m->cmds);
}

void	free_all(t_ms *m, int exit)
{
	if (exit == 0)
	{
		free_cmds(m);
		ft_bzero(m->counters, sizeof(t_c));
		return ;
	}
}
