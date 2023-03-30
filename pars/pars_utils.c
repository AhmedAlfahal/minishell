/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:46:04 by aalfahal          #+#    #+#             */
/*   Updated: 2023/03/30 06:26:07 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cots_check(char *s, int start, int end)
{
	int		l;
	char	p;

	if (!s)
		return (0);
	l = 0;
	p = 0;
	while (start < end)
	{
		if ((s[start] == '"' || s[start] == '\'') && l == 0)
		{
			p = s[start];
			start++;
			l = 1;
		}
		if (s[start] == p)
		{
			if (l == 1)
				l = 0;
			p = 0;
		}
		start++;
	}
	return (l);
}
