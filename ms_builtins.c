/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:02:20 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/13 01:11:59 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo_fun(t_ms *data, int k)
{
	t_cmd	*cm;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cm = data->cmds;
	if (ft_strncmp(ft_stolower(cm[k].args[i]), "echo", 4) == 0)
		i++;
	if (cm[k].args[i] && ft_strncmp(cm[k].args[i], "-n", 3) == 0)
	{
		j = 1;
		i++;
	}
	while (cm[k].args[i])
	{
		printf("%s", cm[k].args[i]);
		if (cm[k].args[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (!j || cm[k].args[1] == NULL)
		printf("\n");
	return (0);
}

int	pwd_fun(t_ms *data, int k)
{
	char	*path;

	if (data->cmds[k].args[1] != NULL
		&& ft_strncmp(data->cmds[k].args[1], "-", 1) == 0)
		return (1);
	path = malloc(1000000 * sizeof(char));
	if (getcwd(path, 1000000) == NULL)
		return (1);
	printf("%s\n", path);
	free(path);
	return (0);
}

int	cd_fun(t_ms *data, int k)
{
	t_cmd	*cm;
	t_list	*temp;

	temp = data->envd;
	cm = data->cmds;
	if (cm[k].args[1] == NULL)
	{
		while (temp)
		{
			if (ft_strncmp(temp->name, "HOME", 4) == 0)
			{
				if (chdir(temp->value) < 0)
					perror("minishell: cd");
				return (0);
			}
			temp = temp->next;
		}
		write(2, "minishell: cd: HOME not set\n", 28);
	}
	else if (chdir(cm[k].args[1]) < 0)
		perror("minishell: cd");
	return (0);
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