/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 05:36:32 by aalfahal          #+#    #+#             */
/*   Updated: 2023/03/28 04:01:45 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	count_all_helper(char *rdln, int *i, t_c *counter)
{
	if (rdln[*i] == '"')
		counter->d_com++;
	else if (rdln[*i] == '\'')
		counter->s_com++;
	else if (rdln[*i] == '\\')
		counter->bslsh++;
	else if (rdln[*i] == '|')
		counter->pipes++;
	else if (rdln[*i] == ';')
		counter->smcln++;
	else if (rdln[*i] == '>' && rdln[*i + 1] == '>')
	{
		counter->rr_redir++;
		*i = *i + 1;
	}
	else if (rdln[*i] == '<' && rdln[*i + 1] == '<')
	{
		*i = *i + 1;
		counter->ll_redir++;
	}
	else if (rdln[*i] == '>')
		counter->r_redir++;
	else if (rdln[*i] == '<')
		counter->l_redir++;
}

static void	count_all(t_c *counter, char *rdln)
{
	int	i;

	i = 0;
	while (rdln[i])
	{
		count_all_helper(rdln, &i, counter);
		i++;
	}
	printf("bslsh		%d\n", counter->bslsh);
	printf("d_com		%d\n", counter->d_com);
	printf("l_redir		%d\n", counter->l_redir);
	printf("ll_redir	%d\n", counter->ll_redir);
	printf("r_redir		%d\n", counter->r_redir);
	printf("rr_redir	%d\n", counter->rr_redir);
	printf("pipes		%d\n", counter->pipes);
	printf("s_com		%d\n", counter->s_com);
	printf("smcln		%d\n", counter->smcln);
}

static void	init_all(t_ms *m)
{
	m->counters = malloc(sizeof(t_c));
	ft_bzero(m->counters, sizeof(t_c));
}

int	main(int ac, char **av, char **env)
{
	t_ms	m;
	(void)ac;
	(void)av;
	m.env = env;
	init_all(&m);
	while (1)
	{
		m.rdln = readline("minishell$:");
		if (ft_strlen(m.rdln) == 4 && !ft_strncmp("exit", m.rdln, 4))
			exit(0);
		count_all(m.counters, m.rdln);
	}
	return (0);
}

// if s[i] == '\'' || '"'
// 	if(!flag)
// 		flag = s[i];
// 	else if(flag == s[i])
// 		 flag = 0;
