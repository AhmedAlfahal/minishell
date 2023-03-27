/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 04:13:48 by aalfahal          #+#    #+#             */
/*   Updated: 2023/03/27 23:17:15 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include"libft/libft.h"
# include<stdio.h>
# include<fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_counters
{
	int	pipes;
	int	d_com;
	int	s_com;
	int	l_redir;
	int	r_redir;
	int	ll_redir;
	int	rr_redir;
	int	bslsh;
	int	smcln;
}		t_c;

typedef struct s_redirection
{
	char	**a_cmd;
	char	*file_name;
}			t_rdr;

typedef struct s_commands
{
	char	**args;
}			t_cmd;

typedef struct s_minishell
{
	char	**env;
	char	*rdln;
	t_cmd	*cmds;
	t_rdr	*redirs;
	t_c		*counters;
	int		i;
}			t_ms;

#endif