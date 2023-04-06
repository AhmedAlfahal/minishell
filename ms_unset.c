/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 23:47:14 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/06 03:10:45 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_fun(t_ms *data)
{
	t_cmd	*cm;
	int		i;

	cm = data->cmds;
	i = 0;
	while (cm->args[++i])
	{
		if ((ft_isalpha(cm->args[i][0]) || cm->args[i][0] == '_')
			&& !check_unsetpath(cm->args[i]))
		{
			find_unsetxp(&data->envd, env_name(cm->args[i]));
			find_unsetxp(&data->expd, env_name(cm->args[i]));
		}
		else
		{
			write(2, "minishell: unset: `", 19);
			write(2, cm->args[i], ft_strlen(cm->args[i]));
			write(2, "\': not a valid identifier\n", 26);
		}
	}
	return (0);
}

int	check_unsetpath(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	if (s[i] == '=')
		return (1);
	return (0);
}


int	find_unsetxp(t_list **data, char *name)
{
	t_list	*temp;
	t_list	*tmp;
	int		i;

	temp = *data;
	i = 0;
	if (ft_strncmp(temp->name, name, ft_strlen(name)) == 0)
	{
		tmp = temp;
		temp = temp->next;
		ft_lstdelone(tmp);
		free(name);
		return (0);
	}
	find_unsetxpx(data, name);
	return (0);
}


int	find_unsetxpx(t_list **data, char *name)
{
	t_list	*temp;
	t_list	*tmp;

	temp = *data;
	while (temp->next)
	{
		if (ft_strncmp(temp->next->name, name, ft_strlen(name)) == 0)
		{
			tmp = temp->next;
			temp->next = temp->next->next;
			ft_lstdelone(tmp);
		}
		temp = temp->next;
	}
	if (name)
		free(name);
	return (0);
}
