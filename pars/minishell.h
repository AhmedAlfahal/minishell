/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 04:13:48 by aalfahal          #+#    #+#             */
/*   Updated: 2023/03/29 22:42:59 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include"../libft/libft.h"
# include<stdio.h>
# include<fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_counters
{
	int	pipes;
	int	d_cot;
	int	s_cot;
	int	l_redir;
	int	r_redir;
	int	ll_redir;
	int	rr_redir;
	int	bslsh;
	int	smcln;
}		t_c;

typedef struct s_redirection
{
	int		rdr_type;
	char	*file_name;
}			t_rdr;

typedef struct s_commands
{
	char	**args;
	t_rdr	redirs;
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
}			t_ms;

/******************************Pars_utils*****************************/

int		cms_ck(char *s, int i, t_c *c);
int		to_chrnlen(char *s, char c, int start, int end);
void	print_2d_array(char **d);
void	count(t_c *counter, char *rdln);
void	dupper_2d(t_ms *m, char **source);
void	pars(t_ms *m);

/******************************Free_things*****************************/

void	free_all(t_ms *m, int exit);
void	free_2d_array(char **s);

/******************************Free_things*****************************/

void	print_counters(t_c *counter);
void	print_pipes(t_ms *m);
#endif