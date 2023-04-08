/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:28:36 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/08 05:29:19 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int	re;

	re = 1;
	if (c < 'A' || (c > 'Z' && c < 'a') || c > 'z')
		re = 0;
	return (re);
}

int	ft_isdigit(int c)
{
	int	re;

	re = 0;
	if (c >= '0' && c <= '9')
		re = 1;
	return (re);
}
