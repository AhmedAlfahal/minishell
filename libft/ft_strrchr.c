/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:32:11 by hmohamed          #+#    #+#             */
/*   Updated: 2022/10/16 13:17:13 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(int i, char *s, int c)
{
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)s;
	while (s[i] != '\0')
	{
		if (temp[i] == (unsigned char)c && !check(i + 1, temp, c))
			return (&temp[i]);
		i++;
	}
	if (c == '\0' && temp[i] == '\0')
		return (&temp[i]);
	return (0);
}
