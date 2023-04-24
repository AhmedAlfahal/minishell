/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:39:32 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/24 16:51:09 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	get_input(char *inputdr)
{
	int	fd;

	fd = open(inputdr, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (dup2(fd, STDIN_FILENO))
		perror("dup2");
	close(fd);
	return (0);
}

static int	get_output(char *outputdr)
{
	int	fd;

	fd = open(outputdr, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (-1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		perror("dup2");
	close(fd);
	return (0);
}

static int	get_append(char *appnd)
{
	int	fd;

	fd = open(appnd, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
		return (-1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		perror("dup2");
	close(fd);
	return (0);
}

int	redir_fun(t_ms *data, int k)
{
	int	i;

	i = 0;
	while (i < data->cmds[k].c_rdr)
	{
		if (data->cmds[k].rdr[i].rdr_type == input)
		{
			if (get_input(data->cmds[k].rdr[i].file_name) == -1)
				return (-1);
		}
		else if (data->cmds[k].rdr[i].rdr_type == append)
		{
			if (get_append(data->cmds[k].rdr[i].file_name) == -1)
				return (-1);
		}
		else if (data->cmds[k].rdr[i].rdr_type == output)
		{
			if (get_output(data->cmds[k].rdr[i].file_name) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}
