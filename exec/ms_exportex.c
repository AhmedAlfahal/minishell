/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exportex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 01:23:33 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/28 18:29:49 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	find_updatexpx(t_ms *data, char *name, char *value)
{
	t_list	*temp;
	t_list	*tmp;

	temp = data->expd;
	if (temp && ft_strncmp(temp->name, name, ft_strlen(temp->name)) >= 0)
	{
		ft_lstadd_front(&temp, ft_lstnew(name, value, 0));
		return (0);
	}
	while (temp && temp->next)
	{
		if (ft_strncmp(temp->next->name, name,
				ft_strlen(temp->name)) >= 0)
		{
			tmp = temp->next;
			temp->next = ft_lstnew(name, value, 0);
			temp->next->next = tmp;
			return (0);
		}
		temp = temp->next;
	}
	ft_lstadd_back(&temp, ft_lstnew(name, value, 0));
	return (0);
}

int	find_upxp(t_ms *data, char *name, char *value)
{
	t_list	*temp;

	temp = data->expd;
	while (temp)
	{
		if (ft_strlen(temp->name) == ft_strlen(name)
			&& ft_strncmp(temp->name, name, ft_strlen(temp->name)) == 0)
		{
			if (!value && temp->value)
			{
				free_vn(name, value);
				return (0);
			}
			if (temp->value && ft_strncmp(temp->value, "", 1) != 0)
				free(temp->value);
			temp->value = value;
			free_vn(name, NULL);
			return (0);
		}
		temp = temp->next;
	}
	if (!temp)
		find_updatexpx(data, name, value);
	return (0);
}

int	check_expath(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	if (s[i] == '=' && !s[i + 1])
		return (1);
	return (0);
}

int	check_namepath(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '=')
	{
		if (!ft_isalpha(s[i]) && !ft_isdigit(s[i]) && s[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	env_fun(t_ms *data, int k)
{
	t_list	*temp;
	t_cmd	*cm;

	temp = data->envd;
	cm = data->cmds;
	if (cm[k].args[1])
		return (1);
	while (temp)
	{
		if (temp->err == 0)
			printf("%s=%s\n", (char *)temp->name, (char *)temp->value);
		temp = temp->next;
	}
	return (0);
}
