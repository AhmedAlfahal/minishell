/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:29:42 by hmohamed          #+#    #+#             */
/*   Updated: 2022/10/08 16:58:00 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sr1;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		sr1 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (!sr1)
			return (NULL);
		while (s1[j] != 0)
			sr1[i++] = s1[j++];
		j = 0;
		while (s2[j] != 0)
			sr1[i++] = s2[j++];
		sr1[i] = 0;
		return (sr1);
	}
	return (0);
}
