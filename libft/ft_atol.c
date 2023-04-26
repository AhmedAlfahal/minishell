/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:20:34 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/26 15:26:52 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	int					i;
	int					c;
	unsigned long long	num;

	i = 0;
	c = 1;
	num = 0;
	if (str == 0)
		return (0);
	if (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
		if (str[i++] == '-')
			c = -1;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if (num > 2147483648)
			return (255);
		i++;
	}
	if (str[i] != '\0')
		return (255);
	return (c * num);
}
