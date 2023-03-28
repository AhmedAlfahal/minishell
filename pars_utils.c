/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:46:04 by aalfahal          #+#    #+#             */
/*   Updated: 2023/03/28 23:30:42 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	to_chrlen(char *s, char c)
{
	int		i;
	int		ln;

	if (!s)
		return (0);
	i = 0;
	ln = (int)ft_strlen(s);
	while (i < ln)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	print_2d_array(char **d)
{
	int	i;

	i = 0;
	while (d[i])
		printf("	[%s]	", d[i++]);
}
