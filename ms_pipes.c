/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:37:03 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/12 23:31:08 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdio.h>

int	pipe_fun(t_ms *data)
{
	int			fd[2][2];
	int			id;
	int			i;
	char		**env;
	char		*path;

	if (pipe(fd[0]) < 0)
	{
		perror("pipe0");
		exit(0);
	}
	if (pipe(fd[1]) < 0)
	{
		perror("pipe1");
		exit(0);
	}
	env = NULL;
	i = 0;
	while (i < data->c_cmds)
	{
		if (i == 0)
		{
			id = fork();
			if (id == 0)
			{
				close(fd[0][0]);
				printf ("hi im hashim and  i is : %d\n", i);
				if (dup2(fd[0][1], STDOUT_FILENO) < 0)
				{
					perror("dup2_1");
					exit(0);
				}
				close(fd[1][0]);
				close(fd[1][1]);
				close(fd[0][1]);
				env = dupper_lst(data->envd);
				if (data->cmds[i].args[0][0] == '/' || data->cmds[i].args[0][0] == '.')
					path = ft_strdup(data->cmds[i].args[0]);
				else
					path = find_path(data, -1, i);
				if (path && execve(path, data->cmds[i].args, env) < -1)
				{
					write(2, "error\n", 6);
					free(path);
					g_code = 127;
				}
				free_2d_array(env);
				err_file(data->cmds[i].args[0], data);
			}
		}
		else if (i == data->c_cmds - 1)
		{
			id = fork();
			if (id == 0)
			{
				if ((i + 1) % 2 == 0)
				{
					if (dup2(fd[0][0], STDIN_FILENO) < 0)
					{
						perror("dup2_2");
						exit(0);
					}
				}
				else if ((i + 1) % 2 != 0)
				{
					if (dup2(fd[1][0], STDIN_FILENO) < 0)
					{
						perror("dup2_2");
						exit(0);
					}
				}
				close(fd[0][0]);
				close(fd[1][0]);
				close(fd[1][1]);
				close(fd[0][1]);
				env = dupper_lst(data->envd);
				if (data->cmds[i].args[0][0] == '/' || data->cmds[i].args[0][0] == '.')
					path = ft_strdup(data->cmds[i].args[0]);
				else
					path = find_path(data, -1, i);
				printf ("hi im hashim and  i is : %d\n", i);
				if (path && execve(path, data->cmds[i].args, env) < -1)
				{
					write(2, "error\n", 6);
					free(path);
					g_code = 127;
				}
				free_2d_array(env);
				err_file(data->cmds[i].args[0], data);
			}
		}
		else if (i < data->c_cmds - 1)
		{
			if((i + 1) > 2 && (i + 1) % 2 != 0)
			{
				close(fd[0][0]);
				close(fd[0][1]);
				if (pipe(fd[0]) < 0)
				{
					perror("pipe0");
					exit(0);
				}
			}
			else if((i + 1) > 2 && (i + 1) % 2 == 0)
			{
				close(fd[1][0]);
				close(fd[1][1]);
				if (pipe(fd[1]) < 0)
				{
					perror("pipe0");
					exit(0);
				}
			}
			id = fork();
			if (id == 0)
			{
				if ((i + 1) % 2 == 0)
				{
					if (dup2(fd[0][0], STDIN_FILENO) < 0)
					{
						perror("dup2_2");
						exit(0);
					}
					if (dup2(fd[1][1], STDOUT_FILENO) < 0)
					{
						perror("dup2_3");
						exit(0);
					}
				}
				else if ((i + 1) % 2 != 0)
				{
					if (dup2(fd[1][0], STDIN_FILENO) < 0)
					{
						perror("dup2_2");
						exit(0);
					}
					if (dup2(fd[0][1], STDOUT_FILENO) < 0)
					{
						perror("dup2_3");
						exit(0);
					}
				}
				close(fd[0][0]);
				close(fd[1][0]);
				close(fd[1][1]);
				close(fd[0][1]);
				env = dupper_lst(data->envd);
				if (data->cmds[i].args[0][0] == '/' || data->cmds[i].args[0][0] == '.')
					path = ft_strdup(data->cmds[i].args[0]);
				else
					path = find_path(data, -1, i);
				if (path && execve(path, data->cmds[i].args, env) < -1)
				{
					write(2, "error\n", 6);
					free(path);
					g_code = 127;
				}
				free_2d_array(env);
				err_file(data->cmds[i].args[0], data);
			}
		}
		i++;
	}
	close(fd[0][0]);
	close(fd[1][0]);
	close(fd[1][1]);
	close(fd[0][1]);
	i = 0;
	while (i < data->c_cmds)
	{
		wait(NULL);
		i++;
	}
	//wait(NULL);
	return (0);
}

// int	pipes_fun(char **env)
// {
// 	int fd[2][2];
// 	int id;
// 	char *ls[2] = {"ls", NULL};
// 	char *cat[2] = {"cat", NULL};
// 	char *grep[3] = {"grep", "ms", NULL};
// 	char *wc[2] = {"wc", NULL};
 
// 	// (void)av;
// 	// (void)ac;
// 	if (pipe(fd[0]) < 0)
// 	{
// 		perror("pipe0");
// 		exit(0);
// 	}
// 	if (pipe(fd[1]) < 0)
// 	{
// 		perror("pipe1");
// 		exit(0);
// 	}
// 	id = fork();
// 	if(id == 0)
// 	{
// 		printf("hello");
// 		close(fd[0][0]);
// 		if (dup2(fd[0][1], STDOUT_FILENO) < 0)
// 		{
// 			perror("dup2_1");
// 			exit(0);
// 		}
// 		close(fd[1][0]);
// 		close(fd[1][1]);
// 		close(fd[0][1]);
// 		if (execve("/bin/ls", ls, env) < 0)
// 		{
// 			perror("execve1");
// 			exit(0);
// 		}
// 	}
// 	id = fork();
// 	if (id == 0)
// 	{
// 		// char s[1000];
// 		if (dup2(fd[0][0], STDIN_FILENO) < 0)
// 		{
// 			perror("dup2_2");
// 			exit(0);
// 		}
// 		if (dup2(fd[1][1], STDOUT_FILENO) < 0)
// 		{
// 			perror("dup2_3");
// 			exit(0);
// 		}
// 		close(fd[0][0]);
// 		close(fd[1][0]);
// 		close(fd[1][1]);
// 		close(fd[0][1]);
// 		if (execve("/bin/cat", cat, env) < 0)
// 		{
// 			perror("execve2");
// 			exit(0);
// 		}
// 	}
// 	close(fd[0][0]);
// 	close(fd[0][1]);
// 	if (pipe(fd[0]) < 0)
// 	{
// 		perror("pipe0");
// 		exit(0);
// 	}
// 	id = fork();
// 	if (id == 0)
// 	{
// 		if (dup2(fd[1][0], STDIN_FILENO) < 0)
// 		{
// 			perror("dup2_4");
// 			exit(0);
// 		}
// 		if (dup2(fd[0][1], STDOUT_FILENO) < 0)
// 		{
// 			perror("dup2_4");
// 			exit(0);
// 		}
// 		close(fd[0][0]);
// 		close(fd[1][0]);
// 		close(fd[1][1]);
// 		close(fd[0][1]);
// 		if (execve("/usr/bin/grep", grep, env) < 0)
// 		{
// 			perror("execve3");
// 			exit(0);
// 		}
// 	}
// 	id = fork();
// 	if (id == 0)
// 	{
// 		if (dup2(fd[0][0], STDIN_FILENO) < 0)
// 		{
// 			perror("dup2_4");
// 			exit(0);
// 		}
// 		close(fd[0][0]);
// 		close(fd[1][0]);
// 		close(fd[1][1]);
// 		close(fd[0][1]);
// 		if (execve("/usr/bin/wc", wc, env) < 0)
// 		{
// 			perror("execve3");
// 			exit(0);
// 		}
// 	}
// 	wait(NULL);
// 	//wait(NULL);
// 	// wait(NULL);
// 	close(fd[0][0]);
// 	close(fd[1][0]);
// 	close(fd[1][1]);
// 	close(fd[0][1]);
// 	return (0);
// }

// int	main(int ac, char **av, char **env)
// {
// 	pipes_fun(env);
// 	return (0);
// }
