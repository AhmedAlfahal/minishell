/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:49:43 by hmohamed          #+#    #+#             */
/*   Updated: 2023/04/16 03:00:23 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*open_hdoc(t_rdr *hdoc, int i)
{
	char	*s;
	char	*str;
	char	*temp;

	str = NULL;
	if (hdoc[i].rdr_type == herdock)
	{
		while (1)
		{
			s = readline("> ");
			if (ft_strncmp(hdoc[i].file_name,
					s, ft_strlen(hdoc[i].file_name)) == 0 && ft_strncmp
				(hdoc[i].file_name, s, ft_strlen(s)) == 0)
				break ;
			temp = str;
			str = ft_strjoin4(temp, s, '\n');
			if (temp)
				free(temp);
		}
		temp = str;
		str = ft_strjoin(temp, "\n");
		if (temp)
			free(temp);
	}
	return (str);
}

char	*get_hd(t_cmd *hdoc, int k)
{
	char	*hd;
	char	*hdc;
	int		i;

	i = 0;
	hd = NULL;
	while (i < hdoc[k].c_rdr)
	{
		if (hdoc[k].rdr[i].rdr_type == herdock)
		{
			if (hd)
				free(hd);
			hd = open_hdoc(hdoc[k].rdr, i);
		}
		i++;
	}
	if (hdoc[k].args[0])
	{
		hdc = hd;
		hd = ft_strjoin4(hdoc[k].args[0], hdc, ' ');
		free(hdc);
	}
	return (hd);
}
