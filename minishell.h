/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 04:13:48 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/03 00:38:15 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include<stdio.h>
# include<fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

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
	int	redirs;
	int	input;
	int	output;
	int	herdock;
	int	append;
}		t_c;

typedef struct s_redirection
{
	int		rdr_type;
	char	*file_name;
}			t_rdr;

typedef struct s_commands
{
	char	**args;
	t_rdr	*input;
	t_rdr	*output;
}			t_cmd;

typedef struct s_minishell
{
	char	**env;
	char	*rdln;
	t_cmd	*cmds;
	int		c_cmds;
	t_c		*counters;
	int		error;
	int		i;
	t_list	*envd;
	t_list	*expd;
}	t_ms;

/******************************Pars_utils*****************************/

int		cms_ck(char *s, int i);
int		cots_check(char *s, int start, int end);
void	print_2d_array(char **d);
void	count(t_c *counter, char *rdln);
void	dupper_2d(t_ms *m, char **source);
void	pars(t_ms *m);

/******************************Free_things*****************************/

void	free_all(t_ms *m, int exit);
void	free_2d_array(char **s);

/******************************Printers*****************************/

void	print_counters(t_c *counter);
void	print_pipes(t_ms *m);

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
void	echo_fun(t_ms *data);
int		exce(t_ms	*data);
int		builtin_fun(t_ms *data);
int		pwd_fun(void);
int		cd_fun(t_ms *data);
int		init_envlist(t_ms *data, char **env);
int		env_fun(t_ms *data);
int		export_fun(t_ms *data);
int		sort_env(t_ms *data);
int		set_exp(t_ms *data);
int		find_upnv(t_ms *data, char *name, char *value);
int		check_envpath(char *s);
int		check_expath(char *s);
int		find_upxp(t_ms *data, char *name, char *value);
int		find_updatexpx(t_ms *data, char *name, char *value);
int		check_expcmd(t_cmd *cm, t_ms *data, int i);
int		find_unsetxp(t_list **data, char *name);
int		find_unsetxpx(t_list **data, char *name);
int		unset_fun(t_ms *data);
int		check_unsetpath(char *s);

#endif