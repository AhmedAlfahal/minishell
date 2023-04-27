/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:37:03 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/27 16:57:57 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	pipe_init(t_ms *data)
{
	if (pipe(data->fd[0]) < 0)
	{
		perror("pipe0");
		return ;
	}
	if (pipe(data->fd[1]) < 0)
	{
		perror("pipe1");
		return ;
	}
}

static void	first_cmd(t_ms *data, int i)
{
	int		id;

	id = fork();
	if (id == 0)
	{
		close(data->fd[0][0]);
		if (dup2(data->fd[0][1], STDOUT_FILENO) < 0)
		{
			perror("dup2_1");
			exit(0);
		}
		close(data->fd[1][0]);
		close(data->fd[1][1]);
		close(data->fd[0][1]);
		exec_ve(data, i);
	}
}

static void	last_cmd(t_ms *data, int i, char *hd, int *id)
{

	if (check_red(data->cmds, herdock, i) > 0)
		get_hd_fd(data, i, hd);
	else
	{
		*id = fork();
		if (*id == 0)
		{
			if ((i + 1) % 2 == 0)
				dup2(data->fd[0][0], STDIN_FILENO);
			else if ((i + 1) % 2 != 0)
				dup2(data->fd[1][0], STDIN_FILENO);
			close(data->fd[0][0]);
			close(data->fd[1][0]);
			close(data->fd[1][1]);
			close(data->fd[0][1]);
			exec_ve(data, i);
		}
	}	
}

int	pipe_fun(t_ms *data, char *hd, int i)
{
	int			st;
	int			id;

	pipe_init(data);
	while (i < data->c_cmds)
	{
		if (i == 0)
			first_cmd(data, i);
		else if (i == data->c_cmds - 1)
			last_cmd(data, i, hd, &id);
		else if (i < data->c_cmds - 1)
			med_cmd(data, i);
		i++;
	}
	close(data->fd[0][0]);
	close(data->fd[1][0]);
	close(data->fd[1][1]);
	close(data->fd[0][1]);
	i = -1;
	while (++i < data->c_cmds - 1)
		wait(&st);
	waitpid(id, &st, 0);
	h_status(data, i, WEXITSTATUS(st));
	return (0);
}
