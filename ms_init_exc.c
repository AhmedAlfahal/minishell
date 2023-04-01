/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init_exc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 23:30:26 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/01 04:11:35 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_envlist(t_ms *data, char **env)
{
	int		i;

	i = 0;
	data->envd = NULL;
	while (env[i])
	{
		ft_lstadd_back(&data->envd,
			ft_lstnew(env_name(env[i]), env_value(env[i]), 0));
		i++;
	}
	return (0);
}

char	*env_name(char *path)
{
	int		i;
	char	*str;

	i = 0;
	while (path[i] && path[i] != '=')
		i++;
	str = malloc(i * sizeof(char) + 1);
	i = 0;
	while (path[i] && path[i] != '=')
	{
		str[i] = path[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*env_value(char *path)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (path[i] && path[i] != '=')
		i++;
	i++;
	str = malloc(ft_strlen(path + i) * sizeof(char) + 1);
	j = 0;
	while (path[i])
	{
		str[j++] = path[i++];
	}
	str[j] = '\0';
	return (str);
}


