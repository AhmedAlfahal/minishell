/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:58:31 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/06 05:21:52 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		err_file(data->cmds->args[0]);
		exit(0);
	}
	wait(NULL);
	return (0);
}

char	*find_path(t_ms *data, int i)
{
	char	**path;
	char	*ptmp;
	int		j;

	path = gen_path(data);
	j = 0;
	ptmp = NULL;
	if (path)
	{
		while (path[++i])
		{
			ptmp = ft_strjoin3(path[i], data->cmds->args[0]);
			j = access(ptmp, F_OK);
			if (j == 0)
				break ;
			free (ptmp);
		}
	}
	else
		err_file(data->cmds->args[0]);
	if (path)
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

void	err_file(char *str)
{
	write(2, "minishell: ", 11);
	perror(str);
	exit(127);
}
