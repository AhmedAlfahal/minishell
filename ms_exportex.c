/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exportex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 01:23:33 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/02 03:27:22 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_upxp(t_ms *data, char *name, char *value)
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


int	find_updatexpx(t_ms *data, char *name, char *value)
{
	t_list	*temp;
	t_list	*tmp;

	temp = data->expd;
	if (ft_strncmp(temp->name, name, ft_strlen(name)) >= 0)
	{
		ft_lstadd_front(&temp, ft_lstnew(name, value, 0));
		return (0);
	}
	while (temp->next)
	{
		if (ft_strncmp(temp->next->name, name,
				ft_strlen(name)) >= 0)
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
