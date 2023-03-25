/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:17:02 by aalfahal          #+#    #+#             */
/*   Updated: 2023/03/25 03:54:16 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	char		tmp;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	tmp = (char )c;
	while (i >= 0)
	{
		if (s[i] == tmp)
		{
			return (&((char *)s)[i]);
		}
		else if (i == 0)
		{
			return (NULL);
		}
		i--;
	}
	return (NULL);
}
