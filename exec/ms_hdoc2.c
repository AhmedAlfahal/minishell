/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_hdoc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:43:29 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/24 16:50:40 by hmohamed         ###   ########.fr       */
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
