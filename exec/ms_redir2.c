/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redir2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 01:35:11 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/24 16:51:11 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_red(t_cmd *tcheck, int type, int k)
{
	int	i;

	i = tcheck[k].c_rdr - 1;
	while (i >= 0)
	{
		if (tcheck[k].rdr[i].rdr_type == type)
			return (i + 1);
		i--;
	}
	return (0);
}
