/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expantion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:06:22 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/11 13:03:28 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	replace_expan(char **s, char *val, char *name)
{
	char	*local;
	char	*tmp;
	t_tmp	t;

	local = *s;
	tmp = malloc(ft_strlen(local) - ft_strlen(name) + ft_strlen(val) + 1);
	ft_bzero(&t, sizeof(t_tmp));
	while (local[t.i])
	{
		if (local[t.i + 1] == *name && t.x != 1)
		{
			while (*val)
				tmp[t.j++] = *val++;
			t.i = t.i + ft_strlen(name) + 1;
			t.x = 1;
			continue ;
		}
		tmp[t.j++] = local[t.i++];
	}
	tmp[t.j] = 0;
	free(*s);
	*s = tmp;
}

static void	find_expan(char **s, t_ms *m)
{
	char	*local;
	char	*tmp;
	int		found;
	t_list	*e;

	e = m->expd;
	local = *s;
	found = 0;
	tmp = ft_substr(local, index_expn(local) + 1, next_isalnum(local));
	printf("[%s]\n", tmp);
	while (e)
	{
		if (ft_strncmp((char *)e->name, tmp, ft_strlen(tmp)) == 0 \
		&& ft_strlen((char *)e->name) == ft_strlen(tmp))
		{
			replace_expan(s, e->value, tmp);
			found = 1;
		}
		else if (ft_strncmp("?", tmp, 1) == 0)
			replace_expan(s, ft_itoa(m->error), tmp);
		e = e->next;
	}
	free(tmp);
	if (ft_is_expn(*s) == 1 && found == 1)
		find_expan(s, m);
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
