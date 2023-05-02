/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 23:47:14 by hmohamed          #+#    #+#             */
/*   Updated: 2023/05/02 16:32:08 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_unsetpath(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	if (s[i] == '=')
		return (1);
	return (0);
}

static int	find_unsetxpx(t_list **data, char *name)
{
	t_list	*temp;
	t_list	*tmp;

	temp = *data;
	while (temp->next)
	{
		if (ft_strncmp(temp->next->name, name, ft_strlen(name)) == 0)
		{
			tmp = temp->next;
			if (temp->next->next)
				temp->next = temp->next->next;
			else
				temp->next = NULL;
			ft_lstdelone(tmp);
		}
		if (temp->next)
			temp = temp->next;
	}
	if (name)
		free(name);
	return (0);
}

static int	find_unsetxp(t_list **data, char *name)
{
	t_list	*temp;
	t_list	*tmp;

	temp = *data;
	if (ft_strncmp(temp->name, name, ft_strlen(name)) == 0)
	{
		tmp = temp;
		temp = temp->next;
		*data = temp;
		ft_lstdelone(tmp);
		free(name);
		return (0);
	}
	find_unsetxpx(data, name);
	return (0);
}

int	unset_fun(t_ms *data, int k)
{
	t_cmd	*cm;
	int		i;

	cm = data->cmds;
	i = 0;
	while (cm[k].args[++i])
	{
		if ((ft_isalpha(cm[k].args[i][0]) || cm[k].args[i][0] == '_')
			&& !check_unsetpath(cm[k].args[i]))
		{
			if (data->envd)
				find_unsetxp(&data->envd, env_name(cm[k].args[i]));
			if (data->expd)
				find_unsetxp(&data->expd, env_name(cm[k].args[i]));
		}
		else
		{
			write(2, "minishell: unset: `", 19);
			write(2, cm[k].args[i], ft_strlen(cm[k].args[i]));
			write(2, "\': not a valid identifier\n", 26);
		}
	}
	return (0);
}
