/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:39:32 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/14 02:04:21 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_input(t_cmd *inputdr)
{
	int	i;
	int	fd;

	i = 0;
	while (i < inputdr->c_rdr)
	{
		if (inputdr->rdr[i].rdr_type == input)
		{
			fd = open(inputdr->rdr[i].file_name, O_RDONLY);
			if (fd == -1)
				return (-1);
		}
		i++;
	}
	return (fd);
}

static int	get_output(t_cmd *outputdr)
{
	int	i;
	int	fd;

	i = 0;
	while (i < outputdr->c_rdr)
	{
		if (outputdr->rdr[i].rdr_type == output)
		{
			fd = open(outputdr->rdr[i].file_name,
					O_WRONLY | O_CREAT | O_TRUNC, 0777);
			if (fd == -1)
				return (-1);
		}
		i++;
	}
	return (fd);
}

static int	get_append(t_cmd *appnd)
{
	int	i;
	int	fd;

	i = 0;
	while (i < appnd->c_rdr)
	{
		if (appnd->rdr[i].rdr_type == append)
		{
			fd = open(appnd->rdr[i].file_name, O_APPEND | O_CREAT, 0777);
			if (fd == -1)
				return (-1);
		}
		i++;
	}
	return (fd);
}

static void	redir_fun_ex(t_cmd	*cm, int *i, int fd)
{
	if (i[0] > i[1])
	{
		get_append(cm);
		fd = get_output(cm);
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	else if (i[0] < i[1])
	{
		get_output(cm);
		fd = get_append(cm);
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
}

int	redir_fun(t_ms *data)
{
	int		fd;
	int		i[2];
	t_cmd	*cm;

	cm = data->cmds;
	fd = 0;
	if (check_red(cm, input))
	{
		fd = get_input(cm);
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	i[0] = check_red(cm, output);
	i[1] = check_red(cm, append);
	redir_fun_ex(cm, i, fd);
	return (0);
}
