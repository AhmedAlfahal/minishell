/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_excute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:07:09 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/06 01:43:37 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exce(t_ms	*data)
{
	int		i;

	i = 0;
	if (builtin_fun(data) != 0 && data->c_cmds == 1)
		other_fun(data);
	return (0);
}

int	builtin_fun(t_ms *data)
{
	if (data ->c_cmds == 1
		&& ft_strncmp(ft_stolower(data->cmds->args[0]), "echo", 5) == 0)
		return (echo_fun(data));
	else if (data ->c_cmds == 1
		&& ft_strncmp(ft_stolower(data->cmds->args[0]), "pwd", 4) == 0)
		return (pwd_fun(data));
	else if (data ->c_cmds == 1
		&& ft_strncmp(data->cmds->args[0], "cd", 3) == 0)
		return (cd_fun(data));
	else if (data ->c_cmds == 1
		&& ft_strncmp(ft_stolower(data->cmds->args[0]), "env", 4) == 0)
		return (env_fun(data));
	else if (data ->c_cmds == 1
		&& ft_strncmp(data->cmds->args[0], "export", 7) == 0)
		return (export_fun(data));
	else if (data ->c_cmds == 1
		&& ft_strncmp(data->cmds->args[0], "unset", 6) == 0)
		return (unset_fun(data));
	return (1);
}

int	other_fun(t_ms *data)
{
	char	**env;
	char	*path;
	int		id;

	env = dupper_lst(data->envd);
	id = fork();
	if (id == 0)
	{
		path = find_path(data, -1);
		if (execve(path, data->cmds->args, env) < -1)
		{
			write(2, "error\n", 6);
			free(path);
			exit(0);
		}
	}
	wait(NULL);
	return (0);
}

char	*find_path(t_ms *data, int i)
{
	char	**path;
	char	*ptmp;
	t_list	*tmp;

	tmp = data->envd;
	path = NULL;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, "PATH", 5) == 0)
		{
			path = ft_split(tmp->value, ':');
			break ;
		}
		tmp = tmp->next;
	}
	while (path[++i])
	{
		ptmp = ft_strjoin3(path[i], data->cmds->args[0]);
		if (access(ptmp, X_OK) == 0)
			break ;
		free (ptmp);
	}
	free_2d_array(path);
	return (ptmp);
}
