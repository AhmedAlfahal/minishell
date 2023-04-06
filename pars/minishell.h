/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 04:13:48 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/06 06:10:31 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef enum redirection_flags
{
	input = 1,
	output = 2,
	append = 3,
	herdock = 4,
}	t_rdr_flags;

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
}			t_ms;

/******************************Pars_utils*****************************/

int		cots_check(char *s, int start, int end);
void	count(t_c *counter, char *rdln);
void	dupper_2d(t_ms *m, char **source);
void	pars(t_ms *m);
void	check_rdr_error(char *s, t_c *counter);
void	malloc_rdrs(t_cmd *c);
void	clean_rdrs(t_cmd *c, int i);
void	init_pipes(t_ms *m);
char	**add_rdr_spaces(char **tmp);
char	*malloc_rdr_space(char *s);

/******************************Free_things*****************************/

void	free_all(t_ms *m, int exit);
void	free_2d_array(char **s);

/******************************Tmp_printers*****************************/

void	print_counters(t_c *counter);
void	print_pipes(t_ms *m);
void	print_2d_array(char **d);

#endif