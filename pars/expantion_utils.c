/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expantion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:06:22 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/14 09:50:20 by aalfahal         ###   ########.fr       */
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
	*done = 1;
}

static void	find_expan(char **s, t_ms *m, int ig)
{
	t_tmp	t;
	t_list	*e;

	ft_bzero(&t, sizeof(t_tmp));
	e = m->expd;
	t.s = *s;
	t.tmp = ft_substr(t.s, index_expn(t.s, ig) + 1, next_isalnum(t.s, ig));
	printf("[%d]	[%d]\n", index_expn(t.s, ig) + 1, next_isalnum(t.s, ig));
	printf("[%s]\n", t.tmp);
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
	printf("[%s]	[%d]\n", *s, ft_is_expn(*s));
	if (ft_is_expn(*s) == 1 && t.x == 0)
	{
		ft_cut(s, index_expn(t.s, ig), next_isalnum(t.s, ig) - 1);
		find_expan(s, m, ig);
	}
	else if (ft_is_expn(*s) == 1 && t.x == 1)
	{
		printf("HELLLO\n");
		find_expan(s, m, ig++);
	}
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
		{
			find_expan(&c->args[i], m, 0);
		}
		i++;
	}
}
