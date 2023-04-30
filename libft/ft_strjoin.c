/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 23:02:33 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/16 21:40:47 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dup;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 && !s2)
		return ((char *)s1);
	if (!s1 && s2)
		return ((char *)s2);
	if (!s1 && !s2)
		return (NULL);
	dup = (char *) malloc(sizeof(char) * ft_strlen(s1)
			+ sizeof(char) * ft_strlen(s2) + 1);
	if (!dup)
		return (NULL);
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		dup[i++] = s2[j++];
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char	*dup;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 && !s2)
		return ((char *)s1);
	if (!s1 && !s2)
		return (NULL);
	dup = (char *) malloc(sizeof(char) * ft_strlen(s1)
			+ sizeof(char) * ft_strlen(s2) + 2);
	if (!dup)
		return (NULL);
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i++] = '=';
	while (s2[j] != '\0')
		dup[i++] = s2[j++];
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin3(char const *s1, char const *s2)
{
	char	*dup;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 && !s2)
		return ((char *)s1);
	if (!s1 && !s2)
		return (NULL);
	dup = (char *) malloc(sizeof(char) * ft_strlen(s1)
			+ sizeof(char) * ft_strlen(s2) + 2);
	if (!dup)
		return (NULL);
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i++] = '/';
	while (s2[j] != '\0')
		dup[i++] = s2[j++];
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin4(char const *s1, char const *s2, char c)
{
	char	*dup;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (s1 && !s2)
		return ((char *)s1);
	if (!s1 && s2)
		return ((char *)s2);
	if (!s1 && !s2)
		return (NULL);
	dup = (char *) malloc(sizeof(char) * ft_strlen(s1)
			+ sizeof(char) * ft_strlen(s2) + 2);
	if (!dup)
		return (NULL);
	while (s1[++i] != '\0')
		dup[i] = s1[i];
	dup[i++] = c;
	while (s2[j] != '\0')
		dup[i++] = s2[j++];
	dup[i] = '\0';
	return (dup);
}
