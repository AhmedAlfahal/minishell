/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:25:21 by hmohamed          #+#    #+#             */
/*   Updated: 2022/10/08 15:13:10 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*tem1;
	const char	*tem2;

	tem1 = dst;
	tem2 = src;
	i = 0;
	if (src == dst || !n)
		return (dst);
	while (i < n)
	{
		tem1[i] = tem2[i];
		i++;
	}
	return (tem1);
}
