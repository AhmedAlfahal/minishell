/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expantion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:06:22 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/17 02:19:49 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	add_2d_in_2d(t_ms *m, t_cmd *c, char **add)
{
	char	**tmp;
	int		j;
	int		k;
	int		l;

	tmp = malloc(sizeof(char *) * \
	(ft_strlen_2d(c->args) - 1 + ft_strlen_2d(add) + 1));
	j = 0;
	k = 0;
	l = 0;
	while (c->args[k])
	{
		if (j == m->i)
		{
			while (add[l])
				tmp[j++] = add[l++];
			k++;
			continue ;
		}
		tmp[j++] = c->args[k++];
	}
	tmp[j] = 0;
	free(c->args);
	c->args = tmp;
}

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

static void	call_again(t_ms *m, t_cmd *c, t_tmp *t, char **s)
{
	char	**tmp;
	char	*local;

	tmp = NULL;
	local = *s;
	if (ft_is_expn(local) == 2)
		ft_cut(&local, index_expn(local), index_expn(local) + 1);
	if (ft_is_expn(local) == 1 && t->x == 0)
	{
		if (index_expn(local) != next_isalnum(local))
		{
			ft_cut(&local, index_expn(local), next_isalnum(local) - 1);
			replace_expantion(m, c, &local, t->j);
		}
	}
	else if (ft_is_expn(local) == 1 && t->x == 1)
		replace_expantion(m, c, &local, t->j++);
	if (ft_is_expn(local) == 0 && t->x == 1)
	{
		tmp = ft_split(local, ' ');
		add_2d_in_2d(m, c, tmp);
		free(local);
		free(tmp);
	}
}

void	replace_expantion(t_ms *m, t_cmd *c, char **s, int ig)
{
	t_tmp	t;
	t_list	*e;

	ft_bzero(&t, sizeof(t_tmp));
	e = m->expd;
	t.s = *s;
	t.j = ig;
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
	call_again(m, c, &t, s);
}

void	clean_expantion(t_cmd *c, t_ms *m)
{
	m->i = 0;
	if (!c->args)
		return ;
	while (c->args[m->i])
	{
		if (ft_is_expn(c->args[m->i]) == 1)
		{
			replace_expantion(m, c, &c->args[m->i], 0);
			if (!c->args[m->i])
				break ;
		}
		m->i++;
	}
}
