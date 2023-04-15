/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redir2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 01:35:11 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/14 21:50:27 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_red(t_cmd *tcheck, int type, int k)
{
	int	i;

	i = 0;
	while (i < tcheck[k].c_rdr)
	{
		if (tcheck[k].rdr[i].rdr_type == type)
			return (i + 1);
		i++;
	}
	return (0);
}
