/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_excute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:07:09 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/24 16:50:33 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exce(t_ms	*data)
{
	char	*hd;

	hd = NULL;
	if (data->c_cmds == 1 && data->cmds->args[0])
	{
		get_hd(data, 0);
	}
	if (data->c_cmds == 1 && !data->cmds->args[0])
		get_hd(data, 0);
	if (data->c_cmds >= 2)
	{
		hd = get_hd_last(data, 0);
		pipe_fun(data, hd);
	}
	return (0);
}

int	builtin_fun(t_ms *data, int i)
{
	red_check(data, i);
	if (ft_strncmp(ft_stolower(data->cmds[i].args[0]), "echo", 5) == 0)
		return (echo_fun(data, i));
	else if (ft_strncmp(ft_stolower(data->cmds[i].args[0]), "pwd", 4) == 0)
		return (pwd_fun(data, i));
	else if (ft_strncmp(data->cmds[i].args[0], "cd", 3) == 0)
		return (cd_fun(data, i));
	else if (ft_strncmp(ft_stolower(data->cmds[i].args[0]), "env", 4) == 0)
		return (env_fun(data, i));
	else if (ft_strncmp(data->cmds[i].args[0], "export", 7) == 0)
		return (export_fun(data, i));
	else if (ft_strncmp(data->cmds[i].args[0], "unset", 6) == 0)
		return (unset_fun(data, i));
	return (1);
}

int	check_builtin(t_ms *data, int i)
{
	if (!data->cmds[i].args[0])
		return (0);
	if (ft_strncmp(ft_stolower(data->cmds[i].args[0]), "echo", 5) == 0)
		return (1);
	else if (ft_strncmp(ft_stolower(data->cmds[i].args[0]), "pwd", 4) == 0)
		return (1);
	else if (ft_strncmp(data->cmds[i].args[0], "cd", 3) == 0)
		return (1);
	else if (ft_strncmp(ft_stolower(data->cmds[i].args[0]), "env", 4) == 0)
		return (1);
	else if (ft_strncmp(data->cmds[i].args[0], "export", 7) == 0)
		return (1);
	else if (ft_strncmp(data->cmds[i].args[0], "unset", 6) == 0)
		return (1);
	return (0);
}

int	check_builtin_perent(t_ms *data, int i)
{
	if (!data->cmds[i].args[0])
		return (0);
	else if (ft_strncmp(data->cmds[i].args[0], "cd", 3) == 0)
		return (1);
	else if (ft_strncmp(data->cmds[i].args[0], "export", 7) == 0
		&& data->cmds[i].args[1])
		return (1);
	else if (ft_strncmp(data->cmds[i].args[0], "unset", 6) == 0)
		return (1);
	return (0);
}
