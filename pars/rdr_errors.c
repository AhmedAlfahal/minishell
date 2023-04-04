/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 03:22:18 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/04 23:04:54 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

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
		ft_bzero(c->rdr, sizeof(t_rdr) * (c->c_rdr + 1));
	}
}

static int	ft_wospace_len(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s || *s == 0)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
			i++;
		else
		{
			j++;
			i++;
		}
	}
	return (j);
}

static char	*clone_wo_space(char *s)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char) * ft_wospace_len(s) + 1);
	while (*s)
	{
		if (*s == ' ' || (*s >= 9 && *s <= 13))
			s++;
		else
			tmp[i++] = *s++;
	}
	tmp[i] = 0;
	return (tmp);
}

static void	condition(char *tmp, int i, int len, int *error)
{
	if (tmp[i] == '<' && tmp[i + 1] == '<')
	{
		if (len - i == 2)
			*error = 1;
		else if (tmp[i + 2] == '<' || tmp[i + 2] == '>')
			*error = 1;
	}
	else if (tmp[i] == '>' && tmp[i + 1] == '>')
	{
		if (len - i == 2)
			*error = 1;
		else if (tmp[i + 2] == '<' || tmp[i + 2] == '>')
			*error = 1;
	}
	else if (((tmp[i] == '>' || tmp[i] == '<') \
	&& (tmp[i + 1] == '<' || tmp[i + 1] == '>') && cots_check(tmp, 0, i) == 0))
		*error = 1;
	else if (tmp[i] == '>' && len - i == 1)
		*error = 1;
	else if (tmp[i] == '<' && len - i == 1)
		*error = 1;
}

void	check_rdr_error(char *s, t_c *counter)
{
	int			i;
	size_t		len;
	char		*tmp;

	i = 0;
	tmp = clone_wo_space(s);
	len = ft_strlen(tmp);
	while (tmp[i])
	{
		condition(tmp, i, len, &counter->error);
		if (counter->error == 1)
		{
			write(2, "syntax error near unexpected token\n", 36);
			break ;
		}
		i++;
	}
	free(tmp);
}
