/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:05:40 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/14 01:24:47 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	ft_cut(char **s, int start, int end)
{
	char	*str;
	int		i;
	int		j;
	char	*local;

	str = malloc(sizeof(char) * (end - start + ft_strlen(*s) + 1));
	local = *s;
	i = 0;
	j = 0;
	while (local[i])
	{
		if (i >= start && i <= end)
		{
			i++;
			continue ;
		}
		str[j++] = local[i++];
	}
	str[j] = 0;
	free(*s);
	*s = str;
}
