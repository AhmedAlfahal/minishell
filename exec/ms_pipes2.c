/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipes2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:28:08 by hmohamed          #+#    #+#             */
/*   Updated: 2023/05/01 15:45:49 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	pipe_init2(t_ms *data, int i)
{
	if ((i + 1) > 2 && (i + 1) % 2 != 0)
	{
		close(data->fd[0][0]);
		close(data->fd[0][1]);
		if (pipe(data->fd[0]) < 0)
		{
			perror("pipe0");
			return ;
		}
	}
	else if ((i + 1) > 2 && (i + 1) % 2 == 0)
	{
		close(data->fd[1][0]);
		close(data->fd[1][1]);
		if (pipe(data->fd[1]) < 0)
		{
			perror("pipe0");
			return ;
		}
	}
}

static void	med_cmdex(t_ms *data, int i, int id)
{
	pipe_init2(data, i);
	id = fork();
	if (id == 0)
	{
		if (check_red(data->cmds, herdock, i) > 0)
			hd_pipe(data, i);
		free_hdmain(data);
		if ((i + 1) % 2 == 0)
		{
			if (!check_red(data->cmds, herdock, i))
				dup2(data->fd[0][0], STDIN_FILENO);
			dup2(data->fd[1][1], STDOUT_FILENO);
		}
		else if ((i + 1) % 2 != 0)
		{
			if (!check_red(data->cmds, herdock, i))
				dup2(data->fd[1][0], STDIN_FILENO);
			dup2(data->fd[0][1], STDOUT_FILENO);
		}
		close(data->fd[0][0]);
		close(data->fd[1][0]);
		close(data->fd[1][1]);
		close(data->fd[0][1]);
		exec_ve(data, i);
	}
}

void	exec_ve(t_ms *data, int i)
{
	char	**env;
	char	*path;

	red_check(data, i);
	if (!data->cmds[i].args[0] || builtin_fun(data, i) == 0)
	{
		free_all(data, 2);
		f_free(data);
		exit(0);
	}
	env = dupper_lst(data->envd);
	if (data->cmds[i].args[0][0] == '/' || data->cmds[i].args[0][0] == '.')
		path = ft_strdup(data->cmds[i].args[0]);
	else
		path = find_path(data, -1, i);
	if (path && execve(path, data->cmds[i].args, env) < -1)
		write(2, "error\n", 6);
	free(path);
	free_2d_array(env);
	err_file(data->cmds[i].args[0], data);
	free_all(data, 2);
	f_free(data);
	exit(10);
}

void	med_cmd(t_ms *data, int i)
{
	med_cmdex(data, i, 0);
}
