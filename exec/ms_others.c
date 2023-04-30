/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:58:31 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/30 15:52:01 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	err_file2(char *str, t_ms *data)
{
	if (str[0] == '/' || str[0] == '.')
	{
		perror(str);
	}
	else
	{
		write(2, "minishell: ", 11);
		ft_putstr_fd(str, 2);
		write(2, ": command not found\n", 20);
		data->error_code = 127;
	}
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
			}
			free_all(data, 2);
			f_free(data);
			exit(2);
		}
		if (redir_fun(data, i) == -1)
		{
			write(2, "minishell: ", 11);
			perror(data->cmds[i].rdr->file_name);
			free_all(data, 2);
			f_free(data);
			exit(2);
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

	if (access(str, F_OK) == 0)
	{
		if (stat(str, &st) == 0 && S_ISDIR(st.st_mode))
		{
			write(2, "minishell: ", 11);
			ft_putstr_fd(str, 2);
			ft_putstr_fd(": is a directory\n", 2);
			data->error_code = 126;
		}
		else if (access(str, R_OK | X_OK | W_OK) == 0)
		{
			perror("minishell:");
			data->error_code = 126;
		}
		else
		{
			write(2, "minishell: ", 11);
			perror(str);
			data->error_code = 1;
		}
	}
	else
		err_file2(str, data);
}
