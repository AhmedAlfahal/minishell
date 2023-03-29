/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters_dupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:07:48 by aalfahal          #+#    #+#             */
/*   Updated: 2023/03/29 22:51:42 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	count_all_helper(char *rdln, int *i, t_c *counter)
{
	int	j;

	j = *i;
	if (rdln[*i] == '|' && rdln[*i + 1] == '|' && cms_ck(rdln, j, counter))
	{
		counter->pipes++;
		*i = *i + 1;
	}
	else if (rdln[*i] == '>' && rdln[*i + 1] == '>' \
	&& cms_ck(rdln, j, counter) == 0)
	{
		counter->rr_redir++;
		*i = *i + 1;
	}
	else if (rdln[*i] == '<' && rdln[*i + 1] == '<' \
	&& cms_ck(rdln, j, counter) == 0)
	{
		*i = *i + 1;
		counter->ll_redir++;
	}
	else if (rdln[*i] == '>' && cms_ck(rdln, j, counter) == 0)
		counter->r_redir++;
	else if (rdln[*i] == '<' && cms_ck(rdln, j, counter) == 0)
		counter->l_redir++;
}

void	count(t_c *counter, char *rdln)
{
	int	i;

	i = 0;
	while (rdln[i])
	{
		if (rdln[i] == '"')
			counter->d_cot++;
		else if (rdln[i] == '\'')
			counter->s_cot++;
		else if (rdln[i] == '\\' && cms_ck(rdln, i, counter) == 0)
			counter->bslsh++;
		else if (rdln[i] == '|' && cms_ck(rdln, i, counter) == 0)
			counter->pipes++;
		else if (rdln[i] == ';' && cms_ck(rdln, i, counter) == 0)
			counter->smcln++;
		count_all_helper(rdln, &i, counter);
		i++;
	}
	print_counters(counter);
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
