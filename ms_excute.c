/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_excute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:07:09 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/13 01:01:31 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exce(t_ms	*data)
{
	if (data->c_cmds == 1)
	{
		if (builtin_fun(data, 0) != 0)
			other_fun(data);
	}
	if (data->c_cmds >= 2)
		pipe_fun(data);
	return (0);
}

int	builtin_fun(t_ms *data, int i)
{
	if (ft_strncmp(ft_stolower(data->cmds[i].args[0]), "echo", 5) == 0)
		return (echo_fun(data));
	else if (ft_strncmp(ft_stolower(data->cmds[i].args[0]), "pwd", 4) == 0)
		return (pwd_fun(data));
	else if (ft_strncmp(data->cmds[i].args[0], "cd", 3) == 0)
		return (cd_fun(data));
	else if (ft_strncmp(ft_stolower(data->cmds[i].args[0]), "env", 4) == 0)
		return (env_fun(data));
	else if (ft_strncmp(data->cmds[i].args[0], "export", 7) == 0)
		return (export_fun(data));
	else if (ft_strncmp(data->cmds[i].args[0], "unset", 6) == 0)
		return (unset_fun(data));
	return (1);
}
