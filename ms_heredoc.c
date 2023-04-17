/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:49:43 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/17 23:43:09 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*open_hdoc(t_rdr *hdoc, int i)
{
	char	*s;
	char	*str;
	char	*temp;

	str = NULL;
	if (hdoc[i].rdr_type == herdock)
	{
		while (1)
		{
			s = readline("> ");
			if (ft_strncmp(hdoc[i].file_name,
					s, ft_strlen(hdoc[i].file_name)) == 0 && ft_strncmp
				(hdoc[i].file_name, s, ft_strlen(s)) == 0)
				break ;
			temp = str;
			str = ft_strjoin4(temp, s, '\n');
			free(temp);
		}
		if (!str)
			return (NULL);
		temp = str;
		str = ft_strjoin(temp, "\n");
		free(temp);
	}
	return (str);
}

static int	ex_hd(t_ms *data, char *str, int k)
{
	int		fd[2];
	int		id;

	pipe(fd);
	id = fork();
	if (id == 0)
	{
		if (!data->cmds[k].args[1])
		{
			write(fd[1], str, ft_strlen(str));
			dup2(fd[0], STDIN_FILENO);
		}
		free(str);
		close(fd[0]);
		close(fd[1]);
		if (data->cmds[k].args[0])
			exec_ve(data, k);
		exit(0);
	}
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	return (0);
}

int	get_hd(t_ms *data, int k)
{
	char	*hd;
	int		i;

	i = 0;
	hd = NULL;
	while (i < data->cmds[k].c_rdr)
	{
		if (data->cmds[k].rdr[i].rdr_type == herdock)
		{
			if (hd)
				free(hd);
			hd = open_hdoc(data->cmds[k].rdr, i);
		}
		i++;
	}
	if (data->cmds[k].args[0] && builtin_fun(data, k) != 0)
		ex_hd(data, hd, k);
	if (hd)
		free(hd);
	return (0);
}

int	hd_mid_pp(t_ms *data, int k)
{
	char	*hd;
	int		i;

	i = 0;
	hd = NULL;
	while (i < data->cmds[k].c_rdr)
	{
		if (data->cmds[k].rdr[i].rdr_type == herdock)
		{
			if (hd)
				free(hd);
			hd = open_hdoc(data->cmds[k].rdr, i);
		}
		i++;
	}
	if (hd)
		free(hd);
	return (0);
}
