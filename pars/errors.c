/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 03:22:18 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/30 11:31:50 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

void	malloc_rdrs(t_cmd *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!c->args)
		return ;
	while (c->args[i])
	{
		if (ft_isrdr(c->args[i]) > 0)
			j = j + ft_isrdr(c->args[i]);
		i++;
	}
	c->c_rdr = j;
	if (j > 0)
	{
		c->rdr = malloc(sizeof(t_rdr) * (c->c_rdr + 1));
		if (!c->rdr)
			return ;
		ft_bzero(c->rdr, sizeof(t_rdr) * (c->c_rdr + 1));
	}
}

static char	*clone_wo_space(char *s)
{
	t_tmp	t;

	ft_bzero(&t, sizeof(t_tmp));
	t.tmp = malloc(sizeof(char) * (ft_wospace_len(s) + 1));
	if (!t.tmp)
		return (NULL);
	ft_bzero(t.tmp, (ft_wospace_len(s) + 1));
	while (*s)
	{
		while ((*s == ' ' || (*s >= 9 && *s <= 13)) && *s)
		{
			t.j = 1;
			s++;
		}
		if (t.j == 1)
		{
			t.j = 0;
			t.tmp[t.i++] = ' ';
		}
		else
			t.tmp[t.i++] = *s++;
	}
	t.s = ft_strtrim(t.tmp, " ");
	free(t.tmp);
	return (t.s);
}

static void	pipes_condition(char *tmp, int i, int len, int *error)
{
	if (tmp[i] == '|' && (tmp[i + 1] == '|') && cots_check(tmp, 0, i) == 0)
	{
		if (len - i == 2)
			*error = 1;
		*error = 1;
	}
	else if (tmp[i] == '|' && len - i == 1)
		*error = 1;
	else if (tmp[i] == '|' && i == 0)
		*error = 1;
	else if (ft_strlen(&tmp[i]) >= 3)
		if (tmp[i] == '|' && tmp[i + 1] == ' ' && tmp[i + 2] == '|')
			*error = 1;
	if (i > 0)
		if (tmp[i] == '|' && (tmp[i - 1] == '<' || tmp[i - 1] == '>') \
		&& cots_check(tmp, 0, i) == 0)
			*error = 1;
}

static void	rdr_condition(char *tmp, int i, int len, int *error)
{
	if (tmp[i] == '<' && tmp[i + 1] == '<' && cots_check(tmp, 0, i) == 0)
	{
		if (len - i == 2)
			*error = 1;
		else if ((tmp[i + 2] == '<' || tmp[i + 2] == '>') \
		&& cots_check(tmp, 0, i) == 0)
			*error = 1;
	}
	else if (tmp[i] == '>' && tmp[i + 1] == '>' && cots_check(tmp, 0, i) == 0)
	{
		if (len - i == 2)
			*error = 1;
		else if ((tmp[i + 2] == '<' || tmp[i + 2] == '>') \
		&& cots_check(tmp, 0, i) == 0)
			*error = 1;
	}
	else if ((tmp[i] == '>' || tmp[i] == '<') \
	&& len - i == 1 && cots_check(tmp, 0, i) == 0)
		*error = 1;
	else if ((((tmp[i] == '>' || tmp[i] == '<') && tmp[i + 1] == ' ' \
	&& (tmp[i + 2] == '>' || tmp[i + 2] == '<')) \
	|| ((tmp[i] == '>' || tmp[i] == '<') \
	&& (tmp[i + 1] == '>' || tmp[i + 1] == '<'))) \
	&& cots_check(tmp, 0, i + 2) == 0)
		*error = 1;
}

void	check_rdr_error(t_ms *m, char *s)
{
	t_tmp	t;

	ft_bzero(&t, sizeof(t_tmp));
	t.s = clone_wo_space(s);
	t.j = ft_strlen(t.s);
	if (cots_check(t.s, 0, t.j) != 0)
		m->counters->error = 1;
	while (t.s[t.i])
	{
		if (cots_check(t.s, 0, t.i) == 0)
		{
			rdr_condition(t.s, t.i, t.j, &m->counters->error);
			pipes_condition(t.s, t.i, t.j, &m->counters->error);
		}
		if (m->counters->error == 1)
		{
			write(2, "minishell: ", 12);
			write(2, "syntax error near unexpected token\n", 36);
			m->error_code = 258;
			m->error = 1;
			break ;
		}
		t.i++;
	}
	free(t.s);
}
