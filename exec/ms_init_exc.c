/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init_exc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 23:30:26 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/24 16:50:46 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	init_envlist(t_ms *data, char **env)
{
	int		i;

	i = 0;
	data->envd = NULL;
	data->expd = NULL;
	while (env[i])
	{
		ft_lstadd_back(&data->envd,
			ft_lstnew(env_name(env[i]), env_value(env[i]), 0));
		i++;
	}
	sort_env(data);
	i = 0;
	while (data->env[i])
	{
		ft_lstadd_back(&data->expd,
			ft_lstnew(env_name(data->env[i]), env_value(data->env[i]), 0));
		i++;
	}
	free_2d_array(data->env);
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

int	sort_env(t_ms *data)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (data->env[i])
	{
		j = i + 1;
		while (data->env[j])
		{
			if (ft_strncmp(data->env[j], data->env[i],
					ft_strlen(data->env[j])) <= 0)
			{
				temp = data->env[i];
				data->env[i] = data->env[j];
				data->env[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (0);
}

char	**dupper_lst(t_list *lst)
{
	int		i;
	char	**env;

	i = ft_lstsize(lst);
	env = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (lst)
	{
		env[i] = ft_strjoin2(lst->name, lst->value);
		i++;
		lst = lst->next;
	}
	env[i] = NULL;
	return (env);
}
