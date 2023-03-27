/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:27:06 by hmohamed          #+#    #+#             */
/*   Updated: 2022/12/19 14:00:03 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	a;

	if (n == -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		write(fd, &"8", 1);
	}
	else if (n < 0)
	{
		write(fd, &"-", 1);
		ft_putnbr_fd(n / (-1), fd);
	}
	else
	{
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		a = n % 10 + '0';
		write(fd, &a, 1);
	}
}
