/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:58:31 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/10 00:19:05 by hmohamed         ###   ########.fr       */
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
	exit(g_code);
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
		env = dupper_lst(data->envd);
		if (data->cmds->args[0][0] == '/' || data->cmds->args[0][0] == '.')
			path = ft_strdup(data->cmds->args[0]);
		else
			path = find_path(data, -1, 0);
		if (path && execve(path, data->cmds->args, env) < -1)
		{
			write(2, "error\n", 6);
			free(path);
			g_code = 127;
		}
		free_2d_array(env);
		err_file(data->cmds->args[0], data);
	}
	wait(NULL);
	return (0);
}

char	*find_path(t_ms *data, int i, int ij)
{
	char	**path;
	char	*ptmp;
	int		j;

	path = gen_path(data);
	j = 0;
	ptmp = NULL;
	if (!path)
	{
		g_code = 127;
		return (ptmp);
	}
	while (path[++i])
	{
		ptmp = ft_strjoin3(path[i], data->cmds[ij].args[0]);
		j = access(ptmp, F_OK);
		if (j == 0)
			break ;
		free (ptmp);
		ptmp = NULL;
	}
	if (j != 0)
		g_code = 127;
	free_2d_array(path);
	return (ptmp);
}

char	**gen_path(t_ms *data)
{
	char	**path;
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
	return (path);
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
			exit(g_code);
		}
		else
		{
			write(2, "minishell: ", 11);
			perror(str);
			free_all(data, 2);
			f_free(data);
			exit(g_code);
		}
	}
	else
		err_file2(str, data);
}
