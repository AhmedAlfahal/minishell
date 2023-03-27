/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:43:50 by hmohamed          #+#    #+#             */
/*   Updated: 2022/10/08 18:06:34 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*tf;

	if (!haystack && len == 0)
		return (0);
	tf = (char *)haystack;
	i = 0;
	if (needle[0] == '\0' || haystack == needle)
		return (tf);
	while (tf[i] != '\0' && i < len)
	{
		j = 0;
		while (tf[i + j] != '\0' && tf[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return (&tf[i]);
			j++;
		}
		i++;
	}
	return (0);
}
