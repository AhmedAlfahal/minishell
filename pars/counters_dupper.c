/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters_dupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:07:48 by aalfahal          #+#    #+#             */
/*   Updated: 2023/03/29 06:04:17 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cms_ck(char *rdln, int *i, t_c *c)
{
	int	j;

	j = 0;
	(void)i;
	(void)rdln;
	if (c->s_com == 0 || c->d_com)
		return (0);
	return (1);
}

static void	count_all_helper(char *rdln, int *i, t_c *counter)
{
	if (rdln[*i] == '|' && rdln[*i + 1] == '|' && !cms_ck(rdln, i, counter))
	{
		counter->pipes++;
		*i = *i + 1;
	}
	else if (rdln[*i] == '|' && !cms_ck(rdln, i, counter))
		counter->pipes++;
	else if (rdln[*i] == ';' && !cms_ck(rdln, i, counter))
		counter->smcln++;
	else if (rdln[*i] == '>' && rdln[*i + 1] == '>' && !cms_ck(rdln, i, counter))
	{
		counter->rr_redir++;
		*i = *i + 1;
	}
	else if (rdln[*i] == '<' && rdln[*i + 1] == '<' && !cms_ck(rdln, i, counter))
	{
		*i = *i + 1;
		counter->ll_redir++;
	}
	else if (rdln[*i] == '>' && !cms_ck(rdln, i, counter))
		counter->r_redir++;
	else if (rdln[*i] == '<' && !cms_ck(rdln, i, counter))
		counter->l_redir++;
}

void	count(t_c *counter, char *rdln)
{
	int	i;

	i = 0;
	while (rdln[i])
	{
		if (rdln[i] == '"' && !cms_ck(rdln, &i, counter))
			counter->d_com++;
		else if (rdln[i] == '\'' && !cms_ck(rdln, &i, counter))
			counter->s_com++;
		else if (rdln[i] == '\\' && !cms_ck(rdln, &i, counter))
		counter->bslsh++;
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

void	dupper_2d(t_ms *m, char **source)
{
	int	i;

	i = ft_strlen_2d(source);
	m->env = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (source[i])
	{
		m->env[i] = ft_strdup(source[i]);
		i++;
	}
	m->env[i] = NULL;
}
