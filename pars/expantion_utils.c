/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expantion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:06:22 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/15 03:43:29 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	replace_expan(char **s, char *val, char *name, int *done)
{
	char	*local;
	char	*tmp;
	t_tmp	t;

	local = *s;
	tmp = malloc(ft_strlen(local) - ft_strlen(name) + ft_strlen(val) + 1);
	ft_bzero(&t, sizeof(t_tmp));
	while (local[t.i])
	{
		if (local[t.i + 1] == *name && t.x != 1 && local[t.i] == '$')
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
	*done = 1;
}

static void	call_again(t_ms *m, int change, char **s, int ig)
{
	if (ft_is_expn(*s) == 2)
		ft_cut(s, index_expn(*s), index_expn(*s) + 1);
	if (ft_is_expn(*s) == 1 && change == 0)
	{
		ft_cut(s, index_expn(*s), next_isalnum(*s) - 1);
		replace_expantion(s, m, ig);
	}
	else if (ft_is_expn(*s) == 1 && change == 1)
		replace_expantion(s, m, ig++);
}

void	replace_expantion(char **s, t_ms *m, int ig)
{
	t_tmp	t;
	t_list	*e;

	ft_bzero(&t, sizeof(t_tmp));
	e = m->expd;
	t.s = *s;
	t.tmp = ft_substr(t.s, index_expn(t.s) + 1, next_isalnum(t.s));
	while (e)
	{
		if (ft_strncmp((char *)e->name, t.tmp, ft_strlen(t.tmp)) == 0 \
		&& ft_strlen((char *)e->name) == ft_strlen(t.tmp))
			replace_expan(s, e->value, t.tmp, &t.x);
		else if (ft_strncmp("?", t.tmp, 1) == 0 && ft_strlen(t.tmp) == 1)
		{
			t.malloced = ft_itoa(m->error_code);
			replace_expan(s, t.malloced, t.tmp, &t.x);
			free(t.malloced);
		}
		e = e->next;
	}
	free(t.tmp);
	call_again(m, t.x, s, ig);
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
			replace_expantion(&c->args[i], m, 0);
		i++;
	}
}
