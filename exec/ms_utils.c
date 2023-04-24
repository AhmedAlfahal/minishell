/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:12:10 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/24 16:51:17 by hmohamed         ###   ########.fr       */
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
