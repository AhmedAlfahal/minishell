/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:05:40 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/05 02:48:50 by aalfahal         ###   ########.fr       */
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

void	ft_bnzero(void *s, size_t start, size_t end)
{
	char	*str;

	str = (char *)s;
	while (start < end)
	{
		str[start] = 0;
		start++;
	}
}
