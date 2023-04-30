/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:12:10 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/30 16:59:34 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
		data->error_code = 127;
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
		data->error_code = 127;
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

void	exit_arg_c(t_ms *data, int code)
{
	if (!ft_strncmp("9223372036854775807", data->cmds->args[1], 20))
		code = 255;
	else if (!ft_strncmp("9223372036854775808", data->cmds->args[1], 20)
		|| !ft_strncmp("-9223372036854775809", data->cmds->args[1], 21))
	{
		code = 255;
		write(2, " numeric argument required\n", 27);
	}
	else if (!ft_strncmp("-9223372036854775807", data->cmds->args[1], 21))
		code = 1;
	else if (!ft_strncmp("-9223372036854775808", data->cmds->args[1], 21))
		code = 0;
	else
		code = ft_atol(data->cmds->args[1]) % 256;
	free_all(data, 2);
	f_free(data);
	printf("exit\n");
	exit(code);
}

void	free_vn(char *name, char *value)
{
	if (name)
		free(name);
	if (value && ft_strncmp(value, "", 1) != 0)
		free(value);
}

void	ac_exiting(int ac, char **av)
{
	if (ac > 1)
	{
		access(av[1], F_OK);
		write(2, "minishell: ", 11);
		perror(av[1]);
		exit (127);
	}
}
