/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 05:36:32 by aalfahal          #+#    #+#             */
/*   Updated: 2023/03/27 22:57:57 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	count_all(t_c *counter, char *rdln)
{
	int	i;

	i = 0;
	while (rdln[i])
	{
		if (rdln[i] == '"')
			counter->d_com++;
		else if (rdln[i] == '\'')
			counter->s_com++;
		else if (rdln[i] == '\\')
			counter->bslsh++;
		else if (rdln[i] == '|')
			counter->pipes++;
		else if (rdln[i] == ';')
			counter->smcln++;
		else if (rdln[i] == '>' && rdln[i + 1] == '>')
			counter->rr_redir++;
		else if (rdln[i] == '<' && rdln[i + 1] == '<')
			counter->rr_redir++;
	}
}

static void	init_all(t_ms *m)
{
	m->counters = malloc(sizeof(t_c));
	ft_bzero(m->counters, sizeof(t_c));
	
}

int	main(int ac, char **av)
{
	t_ms	m;
	(void)ac;
	(void)av;
	init_all(&m);
	while (1)
	{
		m.rdln = readline("minishell$:");
	}
	return (0);
}

// if s[i] == '\'' || '"'
// 	if(!flag)
// 		flag = s[i];
// 	else if(flag == s[i])
// 		 flag = 0;
