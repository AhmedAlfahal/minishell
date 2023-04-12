/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 04:13:48 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/13 01:20:05 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include<stdio.h>
# include<fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <sys/wait.h>

int	g_code;

typedef enum redirection_flags
{
	input = 1,
	output = 2,
	append = 3,
	herdock = 4,
}	t_rdr_flags;

typedef struct s_list
{
	void			*name;
	void			*value;
	int				err;
	struct s_list	*next;
}	t_list;

typedef struct s_counters
{
	int	pipes;
	int	error;
	int	redirs;
	int	input;
	int	output;
	int	herdock;
	int	append;
}		t_c;

typedef struct s_tmprdr
{
	char	*s;
	char	a;
	char	b;
	int		i;
	int		x;
	int		j;
}			t_tmp;

typedef struct s_redirection
{
	int		rdr_type;
	char	*file_name;
}			t_rdr;

typedef struct s_commands
{
	char	**args;
	t_rdr	*rdr;
	int		c_rdr;
}			t_cmd;

typedef struct s_minishell
{
	char	**env;
	char	**tmp;
	char	*rdln;
	t_cmd	*cmds;
	int		c_cmds;
	t_c		*counters;
	int		error;
	int		i;
	int		fd[2][2];
	t_list	*envd;
	t_list	*expd;
}			t_ms;

/******************************Pars_utils********************************/

void	dupper_2d(t_ms *m, char **source);
void	pars(t_ms *m);
void	count(t_c *counter, char *rdln);
void	init_pipes(t_ms *m);
int		cots_check(char *s, int start, int end);
void	remove_cots(char **s, t_tmp *t, char cot);

/******************************Redirections******************************/

char	**add_rdr_spaces(char **tmp);
void	check_rdr_error(char *s, t_c *counter);
void	malloc_rdrs(t_cmd *c);
void	clean_rdrs(t_cmd *c, int i);

/******************************Free_things*******************************/

void	free_all(t_ms *m, int exit);
void	free_2d_array(char **s);

/******************************Tmp_printers******************************/

void	print_counters(t_c *counter);
void	print_pipes(t_ms *m);
void	print_2d_array(char **d);

/******************************lists*****************************/

t_list	*ft_lstnew(void *name, void *value, int err);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
char	*env_name(char *path);
char	*env_value(char *path);

/******************************Exce_utils_builtins*****************************/
int		echo_fun(t_ms *data, int k);
int		exce(t_ms	*data);
int		builtin_fun(t_ms *data, int i);
int		pwd_fun(t_ms *data, int k);
int		cd_fun(t_ms *data, int k);
int		init_envlist(t_ms *data, char **env);
int		env_fun(t_ms *data, int k);
int		export_fun(t_ms *data, int k);
int		sort_env(t_ms *data);
int		check_expath(char *s);
int		find_upxp(t_ms *data, char *name, char *value);
int		unset_fun(t_ms *data, int k);
char	**dupper_lst(t_list *lst);
int		other_fun(t_ms *data);
char	*find_path(t_ms *data, int i, int ij);
char	**gen_path(t_ms *data);
void	err_file(char *str, t_ms *data);
void	f_free(t_ms *m);
int		check_namepath(char *s);
int		pipe_fun(t_ms *data);
void	exec_ve(t_ms *data, int i);
void	med_cmd(t_ms *data, int i);

#endif