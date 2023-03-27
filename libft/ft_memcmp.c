/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:18:07 by hmohamed          #+#    #+#             */
/*   Updated: 2022/10/07 13:47:07 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*sr1;
	char	*sr2;

	sr1 = (char *)s1;
	sr2 = (char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (sr1[i] != sr2[i])
			return ((unsigned char)sr1[i] - (unsigned char)sr2[i]);
		i++;
	}
	return (0);
}
