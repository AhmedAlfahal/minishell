/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_hdoc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:43:29 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/29 13:23:02 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	**cop(char **last, char *hd)
{
	int		i;
	char	**first;

	i = ft_strlen_2d(last);
	first = malloc(sizeof(char *) * (i + 2));
	i = 0;
	if (last)
	{
		while (last[i])
		{
			first[i] = last[i];
			i++;
		}
		free(last);
	}
	first[i] = hd;
	i++;
	first[i] = NULL;
	return (first);
}

char	**get_hd_last(t_ms *data, int k)
{
	char	*hd;
	char	**hdar;
	char	**temp;

	hd = NULL;
	hdar = NULL;
	temp = NULL;
	while (k < data->c_cmds)
	{
		hd = hd_herstr(data, k);
		if (hd)
		{
			temp = hdar;
			hdar = cop(temp, hd);
			hd = NULL;
		}
		k++;
	}
	//print_2d_array(hdar);
	return (hdar);
}

void	h_status(t_ms *data, int k, int sts)
{
	struct stat	st;

	if (sts == 0)
		data->error_code = 0;
	else if (sts == 2)
		data->error_code = 1;
	else if (sts == 10)
	{
		if (access(data->cmds[k].args[0], F_OK) == 0)
		{
			if (stat(data->cmds[k].args[0], &st) == 0 && S_ISDIR(st.st_mode))
				data->error_code = 126;
			else if (access(data->cmds[k].args[0], R_OK | X_OK | W_OK) == 0)
				data->error_code = 126;
			else
				data->error_code = 126;
		}
		else
			data->error_code = 127;
	}
}

char	**free_hd(char **hd)
{
	int		i;
	int		j;
	char	**first;

	i = ft_strlen_2d(hd);
	if (i > 1)
	{
		first = malloc(sizeof(char *) * i);
		i = 1;
		j = 0;
		while (hd[i])
			first[j++] = hd[i++];
		free(hd);
		first[j] = NULL;
		return (first);
	}
	else
		free_2d_array(hd);
	return (NULL);
}
