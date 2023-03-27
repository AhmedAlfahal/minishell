/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:33:49 by hmohamed          #+#    #+#             */
/*   Updated: 2022/10/08 18:09:13 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	j;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		temp = (char *)malloc(sizeof(char) * 1);
		temp[0] = 0;
		return (temp);
	}
	if (len < ft_strlen(s))
		temp = (char *)malloc(len + 1);
	else
	{
		temp = (char *)malloc((ft_strlen(s) - (size_t)start));
		len = ft_strlen(s);
	}
	if (temp == NULL)
		return (NULL);
	j = 0;
	while (j < len)
		temp[j++] = s[start++];
	temp[j] = 0;
	return (temp);
}
