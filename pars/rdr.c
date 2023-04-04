/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:07:02 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/04 07:47:57 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

static void	rdr_condition3(t_cmd *c, int *rdr, int *i)
{
	if ((c->args[*i][0] == '"' \
	&& c->args[*i][ft_strlen(c->args[*i]) - 1] == '"') \
	|| (c->args[*i][0] == '\'' \
	&& c->args[*i][ft_strlen(c->args[*i]) - 1] == '\''))
		return ;
	if (ft_strchr(c->args[*i], '<') && ft_strchr(c->args[*i], '<')[1] == '<')
	{
		c->rdr[*rdr].rdr_type = herdock;
		c->rdr[*rdr].file_name = ft_substr(ft_strchr(c->args[*i], '<') \
		, 2, ft_strlen(ft_strchr(c->args[*i], '<')));
	}
	else
		rdr_condition4(c, *rdr, *i);
	if (c->rdr[*rdr].rdr_type != 0 \
	&& (c->rdr[*rdr].rdr_type == input || c->rdr[*rdr].rdr_type == herdock))
		ft_bzero(ft_strchr(c->args[*i], '<'), \
		ft_strlen(ft_strchr(c->args[*i], '<')));
	else if (c->rdr[*rdr].rdr_type != 0 \
	&& (c->rdr[*rdr].rdr_type == output || c->rdr[*rdr].rdr_type == append))
		ft_bzero(ft_strchr(c->args[*i], '>'), \
		ft_strlen(ft_strchr(c->args[*i], '>')));
	*rdr = *rdr + 1;
}

static void	rdr_remove(t_cmd *c, int k, int j, char **tmp)
{
	if (!c->args || *c->args == NULL)
		return ;
	tmp = malloc(sizeof(char *) * (ft_strlen_2d(c->args) - crdr(c->args) + 1));
	ft_bzero(tmp, sizeof(char *) * (ft_strlen_2d(c->args) - crdr(c->args) + 1));
	while (c->args[k])
	{
		if (((c->args[k][0] == '>' || c->args[k][0] == '<') \
		&& (c->args[k][1] != '>' && c->args[k][1] != '<' \
		&& c->args[k][1] != '\0')) || c->args[k][0] == '\0')
		{
			k++;
			continue ;
		}
		else if ((c->args[k][0] == '>' || c->args[k][0] == '<') \
		&& (c->args[k][1] != '>' || c->args[k][1] != '<'))
		{
			k = k + 2;
			if (k - 2 == ft_strlen_2d(c->args) - 1)
				k--;
			continue ;
		}
		tmp[j++] = ft_strdup(c->args[k++]);
	}
	free_2d_array(c->args);
	c->args = tmp;
}

static void	rdr_condition1(t_cmd *c, int *rdr, int *i)
{
	if (ft_strlen(c->args[*i]) == 1)
	{
		if (c->args[*i][0] == '>')
			c->rdr[*rdr].rdr_type = output;
		else if (c->args[*i][0] == '<')
			c->rdr[*rdr].rdr_type = input;
		if (c->rdr[*rdr].rdr_type != 0)
			c->rdr[*rdr].file_name = ft_strdup(c->args[*i + 1]);
	}
	else if (ft_strlen(c->args[*i]) == 2)
	{
		if (c->args[*i][0] == '>' \
		&& c->args[*i][1] != '>' && c->args[*i][1] != '<')
			c->rdr[*rdr].rdr_type = output;
		else if (c->args[*i][0] == '<' \
		&& c->args[*i][1] != '>' && c->args[*i][1] != '<')
			c->rdr[*rdr].rdr_type = input;
		if (c->rdr[*rdr].rdr_type != 0)
			c->rdr[*rdr].file_name = ft_substr(c->args[*i], 1, 2);
	}
	if (c->rdr[*rdr].rdr_type != 0)
		*rdr = *rdr + 1;
}

static void	rdr_condition2(t_cmd *c, int *rdr, int *i)
{		
	if (ft_strlen(c->args[*i]) == 2 \
	&& (c->args[*i][1] == '>' || c->args[*i][1] == '<'))
	{
		if (c->args[*i][0] == '<' && c->args[*i][1] == '<')
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
}

void	clean_rdrs(t_cmd *c, int i)
{
	int		rdr;

	rdr = 0;
	if (!c->args)
		return ;
	while (c->args[i])
	{
		if (ft_isrdr(c->args[i]) > 0)
		{
			rdr_condition1(c, &rdr, &i);
			rdr_condition2(c, &rdr, &i);
			if (ft_strlen(c->args[i]) > 2)
				rdr_condition3(c, &rdr, &i);
		}
		i++;
	}
	rdr_remove(c, 0, 0, NULL);
}
