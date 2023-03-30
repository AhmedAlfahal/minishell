/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:02:20 by hmohamed          #+#    #+#             */
/*   Updated: 2023/03/31 01:11:01 by hmohamed         ###   ########.fr       */
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
	if (ft_strncmp(cm->args[i], "echo", 4) == 0)
		i++;
	if (ft_strncmp(cm->args[i], "-n", 3) == 0)
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
	if (!j)
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
	int		i;

	i = 0;
	cm = data->cmds;
	if (chdir(cm->args[1]) < 0)
		write(2, "Error\n", 6);
	return (0);
}
