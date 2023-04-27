/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_hdoc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:43:29 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/27 19:24:29 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_hd_last(t_ms *data, int k)
{
	char	*hd;

	hd = NULL;
	while (k < data->c_cmds)
	{
		if (hd)
			free(hd);
		hd = hd_herstr(data, k);
		k++;
	}
	return (hd);
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
