/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:07:48 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/30 11:36:30 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
}

void	dupper_2d(t_ms *m, char **source)
{
	int	i;

	i = ft_strlen_2d(source);
	m->env = malloc(sizeof(char *) * (i + 1));
	if (!m->env)
		return ;
	i = 0;
	while (source[i])
	{
		m->env[i] = ft_strdup(source[i]);
		i++;
	}
	m->env[i] = NULL;
}

static int	null_detector(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i][0] == '\0')
			return (1);
		i++;
	}
	return (0);
}

void	cut_null(t_cmd *c)
{
	t_tmp	t;
	char	**tmp;

	tmp = malloc(sizeof(char *) * ft_strlen_2d(c->args) + 1);
	if (!tmp)
		return ;
	ft_bzero(&t, sizeof(t_tmp));
	if (null_detector(c->args) == 0)
	{
		free(tmp);
		return ;
	}
	while (c->args[t.i])
	{
		if (c->args[t.i][0] == '\0')
		{
			t.i++;
			continue ;
		}
		tmp[t.j++] = ft_strdup(c->args[t.i++]);
	}
	tmp[t.j] = NULL;
	free_2d_array(c->args);
	c->args = tmp;
}
