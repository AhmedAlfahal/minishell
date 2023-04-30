/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:38:26 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/28 18:04:59 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_envpath(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	if (s[i] == '=' && s[i + 1])
		return (1);
	return (0);
}

static int	find_upnv(t_ms *data, char *name, char *value)
{
	t_list	*temp;

	temp = data->envd;
	while (temp)
	{
		if (ft_strlen(temp->name) == ft_strlen(name)
			&& ft_strncmp(temp->name, name, ft_strlen(temp->name)) == 0)
		{
			if (temp->value && ft_strncmp(temp->value, "", 1) != 0)
				free(temp->value);
			temp->value = value;
			free_vn(name, NULL);
			return (0);
		}
		temp = temp->next;
	}
	if (!temp)
		ft_lstadd_back(&data->envd,
			ft_lstnew(name, value, 0));
	return (0);
}

static int	check_expcmd(t_cmd *cm, t_ms *data, int i, int k)
{
	if ((ft_isalpha(cm[k].args[i][0]) || cm[k].args[i][0] == '_')
		&& check_namepath(cm[k].args[i]))
	{
		if (check_envpath(cm[k].args[i]))
		{	
			find_upnv(data, env_name(cm[k].args[i]), env_value(cm[k].args[i]));
			find_upxp(data, env_name(cm[k].args[i]), env_value(cm[k].args[i]));
		}
		else if (check_expath(cm->args[i]))
		{
			find_upxp(data, env_name(cm[k].args[i]), "");
			find_upnv(data, env_name(cm[k].args[i]), "");
		}
		else
			find_upxp(data, env_name(cm[k].args[i]), NULL);
	}
	else
	{
		write(2, "minishell: export: `", 20);
		write(2, cm[k].args[i], ft_strlen(cm[k].args[i]));
		write(2, "\': not a valid identifier\n", 26);
		return (2);
	}
	return (0);
}

static int	set_exp(t_ms *data, int k)
{
	t_cmd	*cm;
	int		i;
	int		c;

	cm = data->cmds;
	i = 0;
	c = 0;
	while (cm[k].args[++i])
	{
		if (check_expcmd(cm, data, i, k) == 2)
			c = 2;
	}
	return (c);
}

int	export_fun(t_ms *data, int k)
{
	t_list	*temp;
	t_cmd	*cm;

	temp = data->expd;
	cm = data->cmds;
	if (!cm[k].args[1])
	{
		while (temp)
		{
			if (temp->value)
				printf("declare -x %s=\"%s\"\n",
					(char *)temp->name, (char *)temp->value);
			else
				printf("declare -x %s\n", (char *)temp->name);
			temp = temp->next;
		}
	}
	else
	{
		if (set_exp(data, k) == 2)
			data->error_code = 1;
		else
			data->error_code = 0;
	}
	return (0);
}
