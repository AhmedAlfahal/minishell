/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:19:34 by aalfahal          #+#    #+#             */
/*   Updated: 2023/03/25 03:53:06 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if (n == 0 || !s1 || !s2)
		return (0);
	while (i <= n && a[i] == b[i] && a[i] != '\0' && b[i] != '\0')
	{
		if (i == n - 1)
		{
			return (0);
		}
		i++;
	}
	return (a[i] - b[i]);
}
