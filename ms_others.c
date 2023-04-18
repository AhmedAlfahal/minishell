/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:58:31 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/18 23:54:43 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	err_file2(char *str, t_ms *data)
{
	write(2, "minishell: ", 11);
	ft_putstr_fd(str, 2);
	write(2, ": command not found\n", 20);
	free_all(data, 2);
	f_free(data);
	exit(data->error_code);
}

int	onecmd_fun(t_ms *data)
{
	int		id;

	id = fork();
	if (id == 0)
	{
		hd_mid_pp(data, 0);
	}
	wait(NULL);
	return (0);
}

void	red_check(t_ms *data, int i)
{
	if (data->cmds[i].c_rdr > 0)
	{
		if (!data->cmds[i].args[0])
		{
			if (redir_fun(data, i) == -1)
			{
				write(2, "minishell: ", 11);
				perror(data->cmds[i].rdr->file_name);
				data->error_code = 1;
			}
			free_all(data, 2);
			f_free(data);
			exit(data->error_code);
		}
		if (redir_fun(data, i) == -1)
		{
			write(2, "minishell: ", 11);
			perror(data->cmds[i].rdr->file_name);
			data->error_code = 1;
			exit(data->error_code);
		}
	}
}

int	other_fun(t_ms *data)
{
	char		**env;
	char		*path;
	int			id;

	env = NULL;
	id = fork();
	if (id == 0)
	{
		red_check(data, 0);
		env = dupper_lst(data->envd);
		if (data->cmds->args[0][0] == '/' || data->cmds->args[0][0] == '.')
			path = ft_strdup(data->cmds->args[0]);
		else
			path = find_path(data, -1, 0);
		if (path && execve(path, data->cmds->args, env) < -1)
			write(2, "error\n", 6);
		data->error_code = 127;
		free(path);
		free_2d_array(env);
		err_file(data->cmds->args[0], data);
	}
	wait(NULL);
	return (0);
}

void	err_file(char *str, t_ms *data)
{
	struct stat	st;

	if (str[0] == '/' || str[0] == '.')
	{
		if (stat(str, &st) != 0)
		{
			write(2, "minishell: ", 11);
			perror(str);
			free_all(data, 2);
			f_free(data);
			exit(data->error_code);
		}
		else
		{
			write(2, "minishell: ", 11);
			perror(str);
			free_all(data, 2);
			f_free(data);
			exit(data->error_code);
		}
	}
	else
		err_file2(str, data);
}
