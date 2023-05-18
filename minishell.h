/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 04:13:48 by aalfahal          #+#    #+#             */
/*   Updated: 2023/05/18 08:29:21 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <sys/wait.h>

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
	char	*tmp;
	char	*malloced;
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
	char	*pcontect;
	char	**args;
	t_rdr	*rdr;
	int		c_rdr;
	t_list	*envd;
	t_list	*expd;
}			t_cmd;

typedef struct s_minishell
{
	char	**env;
	char	**tmp;
	char	*rdln;
	t_cmd	*cmds;
	int		c_cmds;
	t_c		*counters;
	int		error_code;
	int		error;
	int		i;
	int		fd[2][2];
	t_list	*envd;
	t_list	*expd;
}			t_ms;

/******************************Pars_utils********************************/

void	rl_replace_line(const char *text, int clear_undo);
void	dupper_2d(t_ms *m, char **source);
void	pars(t_ms *m);
void	count(t_c *counter, char *rdln);
void	init_pipes(t_ms *m);
int		cots_check(char *s, int start, int end);
void	cut_null(t_cmd *c);

/******************************Redirections******************************/

char	**add_rdr_spaces(char **tmp);
void	check_rdr_error(t_ms *m, char *s);
void	malloc_rdrs(t_cmd *c);
void	rdr_remove(t_cmd *c);
void	clean_expantion(t_cmd *c, t_ms *m);

/******************************Free_things*******************************/

void	free_all(t_ms *m, int exit);
void	free_2d_array(char **s);
void	f_free(t_ms *m);

/******************************Lists*************************************/

t_list	*ft_lstnew(void *name, void *value, int err);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
char	*env_name(char *path);
char	*env_value(char *path);

/******************************Exce_utils_builtins***********************/

void	exiting_arg(t_ms *m);
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
int		pipe_fun(t_ms *data, int i, int st);
void	exec_ve(t_ms *data, int i);
void	med_cmd(t_ms *data, int i);
int		check_red(t_cmd *tcheck, int type, int k);
int		redir_fun(t_ms *data, int k);
void	red_check(t_ms *data, int i);
int		get_hd(t_ms *data, int k);
int		check_builtin(t_ms *data, int i);
char	*hd_herstr(t_ms *data, int k);
void	free_hdmain(t_ms *data);
int		check_builtin_perent(t_ms *data, int i);
void	get_hd_last(t_ms *data, int k);
void	h_status(t_ms *data, int k, int sts);
void	exit_arg_c(t_ms *data, int code);
void	free_vn(char *name, char *value);
void	hd_pipe(t_ms *data, int i);
void	ac_exiting(int ac, char **av);

#endif