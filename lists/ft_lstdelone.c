/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:12:17 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/08 04:39:10 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst->name);
	if (ft_strncmp(lst->value, "", 1) != 0)
		free(lst->value);
	free(lst);
}
