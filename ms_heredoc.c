/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:49:43 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/17 02:39:58 by hmohamed         ###   ########.fr       */
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
			if (temp)
				free(temp);
		}
		temp = str;
		str = ft_strjoin(temp, "\n");
		if (temp)
			free(temp);
	}
	return (str);
}

static int	ex_hd(t_ms *data, char *str, int k)
{
	int		fd[2];
	int		id;
	int		i;

	pipe(fd);
	i = 0;
	id = fork();
	if (id == 0)
	{
		write(fd[1], str, ft_strlen(str));
		free(str);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		if (data->cmds[k].args[0])
			exec_ve(data, k);
	}
	else
	{
		close(fd[0]);
		close(fd[1]);
		wait(NULL);
	}
	return (0);
}

int	*get_hd(t_ms *data, int k)
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
	ex_hd(data, hd, k);
	return (0);
}
