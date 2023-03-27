/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:28:34 by hmohamed          #+#    #+#             */
/*   Updated: 2022/10/07 13:48:00 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*temp;

	temp = (char *)s;
	i = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] == (unsigned char)c)
			return (&temp[i]);
		i++;
	}
	if (c == '\0' && temp[i] == '\0')
		return (&temp[i]);
	return (0);
}
