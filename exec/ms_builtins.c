/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:02:20 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/25 17:48:39 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	c_nes(char *s)
{
	int	i;

	i = 0;
	if (s[i] != '-')
		return (0);
	i++;
	if (s[i] != 'n')
		return (0);
	i++;
	while (s[i])
	{
		if (s[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static int	cd_check(t_ms *data, char *str)
{
	if (chdir(str) < 0)
	{
		perror("minishell: cd");
		data->error_code = 1;
		return (0);
	}
	data->error_code = 0;
	return (0);
}

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
	while (cm[k].args[i] && c_nes(cm[k].args[i]))
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
				return (cd_check(data, temp->value));
			}
			temp = temp->next;
		}
		write(2, "minishell: cd: HOME not set\n", 28);
	}
	return (cd_check(data, cm[k].args[1]));
}
