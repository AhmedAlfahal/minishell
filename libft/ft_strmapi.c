/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:31:29 by hmohamed          #+#    #+#             */
/*   Updated: 2022/10/08 17:01:49 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	a;
	char			*sr;

	a = 0;
	if (s && f)
	{
		while (s[a] != '\0')
			a++;
		sr = (char *)malloc(sizeof(char) * a + 1);
		if (sr == NULL)
			return (NULL);
		a = 0;
		while (s[a] != '\0')
		{
			sr[a] = f(a, s[a]);
			a++;
		}
		sr[a] = 0;
		return (sr);
	}
	return (0);
}
