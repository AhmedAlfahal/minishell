/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 04:13:48 by aalfahal          #+#    #+#             */
/*   Updated: 2023/03/27 22:34:19 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include"libft/libft.h"
# include<stdio.h>
# include<fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_pipe
{
	char	*cmd;
	char	**args;
}			t_p;

typedef struct s_counters
{
	int	pipes;
	int	commas;
	int	redir;
	int	bslsh;
	int	smcln;
}			t_c;

typedef struct s_redirection
{
	char	*p_cmd;
	char	*p_cmd_arg;
	char	*a_cmd;
	char	*a_cmd_arg;
}			t_rdr;

typedef struct s_minishell
{
	char	**env;
	char	*rdln;
	char	*cmd;
	char	*cmd_arg;
	t_p		*pipes;
	t_rdr	*redirs;
	t_c		*counters;
	int		i;
}			t_ms;

#endif