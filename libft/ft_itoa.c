/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal < aalfahal@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:04:22 by aalfahal          #+#    #+#             */
/*   Updated: 2022/10/29 18:24:37 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	lenn(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	nn;
	size_t			i;

	i = lenn(n);
	nn = n;
	str = malloc(sizeof(char) * (i) + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n == 0)
		str[--i] = '0';
	if (n < 0)
	{
		str[0] = '-';
		nn = n * -1;
	}
	while (nn > 0)
	{
		str[--i] = (nn % 10) + '0';
		nn = nn / 10;
	}
	return (str);
}
