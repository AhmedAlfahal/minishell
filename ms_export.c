/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:38:26 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/02 03:13:02 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	export_fun(t_ms *data)
{
	t_list	*temp;
	t_cmd	*cm;

	temp = data->expd;
	cm = data->cmds;
	if (!cm->args[1])
	{
		while (temp)
		{
			if (temp->value)
				printf("declare -x %s=\"%s\"\n", temp->name, temp->value);
			else
				printf("declare -x %s\n", temp->name);
			temp = temp->next;
		}
	}
	else
	{
		set_exp(data);
	}
	return (0);
}

int	set_exp(t_ms *data)
{
	t_list	*temp;
	t_cmd	*cm;
	int		i;

	temp = data->expd;
	cm = data->cmds;
	i = 1;
	while (cm->args[i])
	{
		if (ft_isalpha(cm->args[i][0]) || cm->args[i][0] == '_')
		{
			if (check_envpath(cm->args[i]))
			{	
				find_updatenv(data,
					env_name(cm->args[i]), env_value(cm->args[i]));
				find_updatexp(data,
					env_name(cm->args[i]), env_value(cm->args[i]));
			}
			else if (check_expath(cm->args[i]))
			{
				find_updatexp(data, env_name(cm->args[i]), "");
				find_updatenv(data,env_name(cm->args[i]), "");
			}
			else
				find_updatexp(data, env_name(cm->args[i]), NULL);
		}
		i++;
	}
	return (0);
}

int	check_envpath(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	if (s[i] == '=' && s[i + 1])
		return (1);
	return (0);
}

int	find_updatenv(t_ms *data, char *name, char *value)
{
	t_list	*temp;
	int		i;

	temp = data->envd;
	i = 0;
	while (temp)
	{
		if (ft_strncmp(temp->name, name, ft_strlen(temp->name)) == 0)
		{
			if (temp->value && ft_strncmp(temp->value, "", 1) != 0)
				free(temp->value);
			temp->value = value;
			return (0);
		}
		temp = temp->next;
	}
	if (!temp)
		ft_lstadd_back(&data->envd,
			ft_lstnew(name, value, 0));
	return (0);
}

int	find_updatexp(t_ms *data, char *name, char *value)
{
	t_list	*temp;
	int		i;

	temp = data->expd;
	i = 0;
	while (temp)
	{
		if (ft_strncmp(temp->name, name, ft_strlen(name)) == 0)
		{
			if (temp->value && ft_strncmp(temp->value, "", 1) != 0)
				free(temp->value);
			if (!value && temp->value)
				return (0);
			temp->value = value;
			return (0);
		}
		temp = temp->next;
	}
	if (!temp)
		find_updatexpx(data, name, value);
	return (0);
}
