/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:46:04 by aalfahal          #+#    #+#             */
/*   Updated: 2023/03/29 23:14:48 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cms_ck(char *s, int i, t_c *c)
{
	int	j;
	int	x;

	j = 0;
	x = 0;
	if (c->s_cot == 0 && c->d_cot == 0)
		return (0);
	if (c->d_cot >= 1)
	{
		if ((to_chrnlen(s, '"', 0, i + 1) == 1 \
		&& to_chrnlen(s, '"', i, ft_strlen(s)) > 0) \
		|| (to_chrnlen(s, '"', 0, i + 1) % 2 == 1 \
		&& to_chrnlen(s, '"', i, ft_strlen(s)) > 0))
			x = 1;
	}
	if (c->s_cot >= 1)
	{
		if ((to_chrnlen(s, '\'', 0, i + 1) == 1 \
		&& to_chrnlen(s, '\'', i, ft_strlen(s)) > 0) \
		|| (to_chrnlen(s, '\'', 0, i + 1) % 2 == 1 \
		&& to_chrnlen(s, '\'', i, ft_strlen(s)) > 0))
			x = 1;
	}
	return (x);
}

int	to_chrnlen(char *s, char c, int start, int end)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (start < end)
	{
		if (s[start] == c)
			i++;
		start++;
	}
	return (i);
}

void	print_2d_array(char **d)
{
	int	i;

	i = 0;
	while (d[i])
		printf("	[%s]	", d[i++]);
}
