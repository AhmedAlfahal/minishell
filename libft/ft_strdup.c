/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:28:52 by hmohamed          #+#    #+#             */
/*   Updated: 2022/10/08 15:45:42 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dp;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dp = (char *)malloc(i * sizeof(char) + 1);
	if (!dp)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dp[i] = src[i];
		i++;
	}
	dp[i] = '\0';
	return (dp);
}
