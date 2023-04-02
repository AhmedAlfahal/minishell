/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters_dupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:07:48 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/02 22:55:07 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	rdr_condition(t_cmd *c, int *rdr, int *i)
{
	if (c->args[*i][0] == '>' \
	&& c->args[*i][1] != '>' && c->args[*i][1] != '<')
	{
		c->rdr[*rdr].rdr_type = output;
		c->rdr[*rdr].file_name = ft_substr(c->args[*i], 1, 2);
	}
	else if (c->args[*i][0] == '<' \
	&& c->args[*i][1] != '>' && c->args[*i][1] != '<')
	{
		c->rdr[*rdr].rdr_type = input;
		c->rdr[*rdr].file_name = ft_substr(c->args[*i], 1, 2);
	}
	else if (c->args[*i][0] == '<' && c->args[*i][1] == '<')
	{
		c->rdr[*rdr].rdr_type = herdock;
		c->rdr[*rdr].file_name = ft_strdup(c->args[*i + 1]);
	}
	else if (c->args[*i][0] == '>' && c->args[*i][1] == '>')
	{
		c->rdr[*rdr].rdr_type = append;
		c->rdr[*rdr].file_name = ft_strdup(c->args[*i + 1]);
	}
	if (c->rdr[*rdr].rdr_type != 0)
		*rdr = *rdr + 1;
}

void	clean_rdrs(t_cmd *c, int i)
{
	int		rdr;

	rdr = 0;
	if (!c->args)
		return ;
	while (c->args[i])
	{
		if (ft_strlen(c->args[i]) == 1)
		{
			if (c->args[i][0] == '>')
				c->rdr[rdr].rdr_type = output;
			else if (c->args[i][0] == '<')
				c->rdr[rdr].rdr_type = input;
			if (c->args[i][0] == '>' || c->args[i][0] == '<')
				c->rdr[rdr++].file_name = ft_strdup(c->args[i + 1]);
		}
		else if (ft_strlen(c->args[i]) == 2)
			rdr_condition(c, &rdr, &i);
		i++;
	}
}

static void	count_all_helper(char *rdln, int *i, t_c *counter)
{
	int	j;

	j = *i;
	if (rdln[*i] == '>' && cots_check(rdln, 0, j + 1) == 0)
	{
		counter->redirs++;
		counter->output++;
	}
	else if (rdln[*i] == '<' && rdln[*i + 1] == '<' \
	&& cots_check(rdln, 0, j + 1) == 0)
	{
		*i = *i + 1;
		counter->redirs++;
		counter->herdock++;
	}
	else if (rdln[*i] == '<' && cots_check(rdln, 0, j + 1) == 0)
	{	
		counter->redirs++;
		counter->input++;
	}
}

void	count(t_c *counter, char *rdln)
{
	int	i;

	i = 0;
	while (rdln[i])
	{
		if (rdln[i] == '|' && rdln[i + 1] == '|' \
		&& cots_check(rdln, 0, i + 1) == 0)
		{
			counter->pipes++;
			i = i + 1;
		}
		else if (rdln[i] == '|' && cots_check(rdln, 0, i + 1) == 0)
			counter->pipes++;
		else if (rdln[i] == '>' && rdln[i + 1] == '>' \
		&& cots_check(rdln, 0, i + 1) == 0)
		{
			counter->redirs++;
			counter->append++;
			i = i + 1;
		}
		else
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
