/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:39:32 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/18 21:38:25 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_input(t_cmd *inputdr, int k)
{
	int	i;
	int	fd;

	i = 0;
	while (i < inputdr[k].c_rdr)
	{
		if (inputdr[k].rdr[i].rdr_type == input)
		{
			fd = open(inputdr[k].rdr[i].file_name, O_RDONLY);
			if (fd == -1)
				return (-1);
		}
		i++;
	}
	return (fd);
}

static int	get_output(t_cmd *outputdr, int k)
{
	int	i;
	int	fd;

	i = 0;
	while (i < outputdr[k].c_rdr)
	{
		if (outputdr[k].rdr[i].rdr_type == output)
		{
			fd = open(outputdr[k].rdr[i].file_name,
					O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (fd == -1)
				return (-1);
		}
		i++;
	}
	return (fd);
}

static int	get_append(t_cmd *appnd, int k)
{
	int	i;
	int	fd;

	i = 0;
	while (i < appnd[k].c_rdr)
	{
		if (appnd[k].rdr[i].rdr_type == append)
		{
			fd = open(appnd[k].rdr[i].file_name,
					O_WRONLY | O_APPEND | O_CREAT, 0644);
			if (fd == -1)
				return (-1);
		}
		i++;
	}
	return (fd);
}

// static int	redir_fun_ex(t_cmd	*cm, int *i, int fd, int k)
// {
// 	int	j;

// 	j = 0;
// 	if (i[0] == cm[k].c_rdr)
// 	{
// 		fd = get_output(cm, k);
// 		if (i[1] > 0)
// 			j = get_append(cm, k);
// 		if (fd == -1 || j == -1)
// 			return (-1);
// 		if (dup2(fd, STDOUT_FILENO) == -1)
// 			perror("dup2");
// 		close(fd);
// 	}
// 	else if (i[1] == cm[k].c_rdr)
// 	{
// 		fd = get_append(cm, k);
// 		if (i[0] > 0)
// 			j = get_output(cm, k);
// 		if (fd == -1 || j == -1)
// 			return (-1);
// 		dup2(fd, STDOUT_FILENO);
// 		close(fd);
// 	}
// 	return (0);
// }

static int	redir_fun_ex(t_cmd	*cm, int *i, int k)
{
	int	o;
	int	j;

	o = get_output(cm, k);
	j = get_append(cm, k);
	if (o == -1 || j == -1)
		return (-1);
	if (i[0] == cm[k].c_rdr)
	{
		if (dup2(o, STDOUT_FILENO) == -1)
			perror("dup2");
	}
	else if (i[1] == cm[k].c_rdr)
	{
		if (dup2(j, STDOUT_FILENO) == -1)
			perror("dup2");
	}
	if (i[0] > 0)
		close(o);
	if (i[1] > 0)
		close(j);
	return (0);
}

int	redir_fun(t_ms *data, int k)
{
	int		fd;
	int		i[2];
	t_cmd	*cm;
	int		err;

	err = 0;
	cm = data->cmds;
	fd = 0;
	if (check_red(cm, input, k))
	{
		fd = get_input(cm, k);
		if (fd == -1)
			return (-1);
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	i[0] = check_red(cm, output, k);
	i[1] = check_red(cm, append, k);
	err = redir_fun_ex(cm, i, k);
	if (err == -1)
		return (-1);
	return (0);
}
