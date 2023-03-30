/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal < aalfahal@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 21:16:23 by aalfahal          #+#    #+#             */
/*   Updated: 2022/10/29 21:30:14 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*new_node;
	int		i;

	new_node = lst;
	i = 0;
	while (new_node != NULL)
	{
		new_node = new_node->next;
		i++;
	}
	return (i);
}
