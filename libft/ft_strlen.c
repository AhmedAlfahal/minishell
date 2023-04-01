/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:55:43 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/01 03:25:59 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s || *s == 0)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlen_2d(char **s)
{
	int	i;

	i = 0;
	if (!s || *s == 0)
		return (0);
	while (s[i] != NULL)
	{
		i++;
	}
	return (i);
}
