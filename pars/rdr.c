/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:07:02 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/02 04:19:33 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void	rdr_remove(t_cmd *c, int i, int nums)
{
	char	**tmp;
	int		j;
	int		k;

	tmp = malloc(sizeof(char *) * (ft_strlen_2d(c->args) - nums + 1));
	ft_bzero(c->args, sizeof(char *) * (ft_strlen_2d(c->args) - nums + 1));
	j = 0;
	k = 0;
	while (c->args[k])
	{
		if (k == i)
		{
			k++;
			continue ;
		}
		else if (nums == 2 && k == i + 1)
		{
			k++;
			continue ;
		}
		tmp[j++] = ft_strdup(c->args[k++]);
	}
	tmp[j] = 0;
	free_2d_array(c->args);
	c->args = tmp;
}
