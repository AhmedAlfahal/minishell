/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isrdr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 00:26:06 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/09 03:02:55 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isrdr(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if ((s[i] == '>' && s[i + 1] == '>') \
		|| (s[i] == '<' && s[i + 1] == '<') \
		|| (s[i] == '<' && s[i + 1] == '>') \
		|| (s[i] == '>' && s[i + 1] == '<'))
		{
			j++;
			i = i + 2;
			continue ;
		}
		else if (s[i] == '<' || s[i] == '>')
			j++;
		i++;
	}
	return (j);
}

int	crdr(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i][0] == '>' || s[i][0] == '<')
			j++;
		i++;
	}
	return (j);
}

int	ft_cotlen(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '"')
			j++;
		i++;
	}
	return (j);
}
