/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:47:44 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/04 15:47:56 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char    *find_expand(char *line)
{
	int	i;
	int	c1;
	int	c2;

	i = 0;
	while (line[i] != '\0')
	{
		while (line[i] != '$')
		{
			i++;
			c1 = i;
		}
		while (line[i] > 32)
		{
			i++;
			c2 = i;
		}
		while (line[i] < 33)
			i++;
	}
	return (ft_substr(line,c1,(c2-c1)));
}

void	mi_expand_find(char **ln, int i, t_sys *sys)
{
	char	*search;
	char	*find;
	char	*replace;
	int		len;

	len = 1;
	while (ln[0][len +i] && ft_isalnum(ln[0][len +i]))
		len++;
	if (len > 1)
	{
		search = ft_substr(ln[0], i, len);
		find = s_getenv(search + 1, sys);
		free(search);
		if (find)
		{
			replace = ft_strsubreplace(ln[0] ,i, len, find);
			free(*ln);
			*ln = replace;
		}
	}
}

void mi_expand(char **ln, int i, t_sys *sys)
{
	char echap;

	echap = '\0';
	while (ln[0][i])
	{
		if (echap == '\0' && ft_strin(TECHAP, ln[0][i]))
				echap = ln[0][i];
		else if (ln[0][i] == echap)
				echap = '\0';
		if (echap!='\'' && ln[0][i] == '$')
				mi_expand_find(ln, i, sys);
		i++;
	}
}

void mi_expand_interface (t_pipe *pipe, t_sys *mi_sys)
{
	mi_expand(&pipe->full_cmd, 0,mi_sys);
}