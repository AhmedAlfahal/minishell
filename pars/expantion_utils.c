/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expantion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:06:22 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/08 05:01:48 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	replace_expan(char **s, char *val, char *name)
{
	char	*local;
	char	*tmp;
	int		i;
	int		j;

	local = *s;
	tmp = malloc(ft_strlen(local) - ft_strlen(name) + ft_strlen(val) + 1);
	i = 0;
	j = 0;
	while (local[i])
	{
		if (local[i + 1] == *name)
		{
			while (*val)
				tmp[j++] = *val++;
			i = i + ft_strlen(name) + 1;
			continue ;
		}
		tmp[j++] = local[i++];
	}
	tmp[j] = 0;
	free(*s);
	*s = tmp;
}

static void	find_expan(char **s, t_ms *m)
{
	char	*local;
	char	*tmp;
	char	*tmp_name;
	t_list	*e;

	e = m->expd;
	local = *s;
	tmp_name = NULL;
	tmp = ft_substr(local, index_expn(local) + 1, next_isalnum(local));
	while (e)
	{
		if (ft_strncmp((char *)e->name, tmp, ft_strlen(tmp)) == 0)
		{
			tmp_name = ft_strjoin("$", (char *)e->name);
			replace_expan(s, e->value, tmp);
			free(tmp_name);
		}
		e = e->next;
	}
	free(tmp);
}

void	clean_expantion(t_cmd *c, t_ms *m)
{
	int	i;

	i = 0;
	if (!c->args)
		return ;
	while (c->args[i])
	{
		if (ft_is_expn(c->args[i]) == 1)
			find_expan(&c->args[i], m);
		i++;
	}
}
