/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_excute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:07:09 by hmohamed          #+#    #+#             */
/*   Updated: 2023/03/31 01:08:14 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exce(t_ms	*data)
{
	int	i;

	i = 0;
	builtin_fun(data);
	return (0);
}

int	builtin_fun(t_ms *data)
{
	if (data ->c_cmds == 1 && ft_strncmp(data->cmds->args[0], "echo", 5) == 0)
		echo_fun(data);
	if (data ->c_cmds == 1 && ft_strncmp(data->cmds->args[0], "pwd", 4) == 0)
	{
		if (data->cmds->args[1] != NULL
			&& ft_strncmp(data->cmds->args[1], "-", 1) == 0)
			return (0);
		pwd_fun();
	}
	if (data ->c_cmds == 1 && ft_strncmp(data->cmds->args[0], "cd", 3) == 0)
		cd_fun(data);
	return (0);
}
