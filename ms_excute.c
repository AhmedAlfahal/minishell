/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_excute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:07:09 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/05 01:10:32 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exce(t_ms	*data)
{
	int		i;

	i = 0;
	builtin_fun(data);
	other_fun(data);
	return (0);
}

int	builtin_fun(t_ms *data)
{
	if (data ->c_cmds == 1
		&& ft_strncmp(ft_stolower(data->cmds->args[0]), "echo", 5) == 0)
		echo_fun(data);
	if (data ->c_cmds == 1
		&& ft_strncmp(ft_stolower(data->cmds->args[0]), "pwd", 4) == 0)
	{
		if (data->cmds->args[1] != NULL
			&& ft_strncmp(data->cmds->args[1], "-", 1) == 0)
			return (0);
		pwd_fun();
	}
	if (data ->c_cmds == 1 && ft_strncmp(data->cmds->args[0], "cd", 3) == 0)
		cd_fun(data);
	if (data ->c_cmds == 1
		&& ft_strncmp(ft_stolower(data->cmds->args[0]), "env", 4) == 0)
		env_fun(data);
	if (data ->c_cmds == 1
		&& ft_strncmp(data->cmds->args[0], "export", 7) == 0)
		export_fun(data);
	if (data ->c_cmds == 1
		&& ft_strncmp(data->cmds->args[0], "unset", 6) == 0)
		unset_fun(data);
	return (0);
}

int	other_fun(t_ms *data)
{
	char	**env;

	env = dupper_lst(data->envd);
	if (execve("/bin/ls", data->cmds->args, env) < -1)
	{
		printf("error\n");
		exit(0);
	}
	return (0);
}
