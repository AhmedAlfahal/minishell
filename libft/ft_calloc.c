/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal < aalfahal@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:52:53 by aalfahal          #+#    #+#             */
/*   Updated: 2022/10/13 16:30:27 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	if (count >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	s = malloc(count * size);
	if (!s)
		return (NULL);
	ft_bzero(s, size * count);
	return (s);
}
