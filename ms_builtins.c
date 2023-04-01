/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:02:20 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/01 04:31:02 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_fun(t_ms *data)
{
	t_cmd	*cm;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cm = data->cmds;
	if (ft_strncmp(ft_stolower(cm->args[i]), "echo", 4) == 0)
		i++;
	if (cm->args[i] && ft_strncmp(cm->args[i], "-n", 3) == 0)
	{
		j = 1;
		i++;
	}
	while (cm->args[i])
	{
		printf("%s", cm->args[i]);
		if (cm->args[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (!j || cm->args[1] == NULL)
		printf("\n");
}

int	pwd_fun(void)
{
	char	*path;

	path = malloc(1000000 * sizeof(char));
	if (getcwd(path, 1000000) == NULL)
		return (1);
	printf("%s\n", path);
	free(path);
	return (0);
}

int	cd_fun(t_ms *data)
{
	t_cmd	*cm;
	t_list	*temp;
	int		i;

	i = 0;
	temp = data->envd;
	cm = data->cmds;
	if (cm->args[1] == NULL)
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
	else if (chdir(cm->args[1]) < 0)
		perror("minishell: cd");
	return (0);
}

int	env_fun(t_ms *data)
{
	t_list	*temp;
	t_cmd	*cm;

	temp = data->envd;
	cm = data->cmds;
	if (cm->args[1])
		return (1);
	while (temp)
	{
		if (temp->err == 0)
			printf("%s=%s\n", temp->name, temp->value);
		temp = temp->next;
	}
	return (0);
}
