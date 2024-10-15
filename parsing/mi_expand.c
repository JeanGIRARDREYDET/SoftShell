/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:47:44 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/15 02:51:15 by jegirard         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../minishell.h"

char	*find_expand(char *line)
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
	return (ft_substr(line, c1, c2 - c1));
}

void	mi_expand_find(char **full_cmd, int i, t_sys *sys)
{
	char	*search;
	char	*find;
	char	*replace;
	int		len;

	len = 1;
	while (full_cmd[0][len +i] && ft_isalnum(full_cmd[0][len +i]))
		len++;
	if (len > 1)
	{
		search = ft_substr(full_cmd[0], i, len);
		find = mi_getenv(search + 1, sys);
		free(search);
		if (find)
		{
			replace = ft_strsubreplace(full_cmd[0], i, len, find);
			free(*full_cmd);
			*full_cmd = replace;
		}
	}
}

void	mi_expand(char **full_cmd, int i, t_sys *mi_sys)
{
	char	echap;

	if (!full_cmd || !*full_cmd)
		return ;
	echap = '\0';
	while (full_cmd && full_cmd[0][i])
	{
		printf("full_cmd = %c\n", (*full_cmd)[i]);
		if (echap == '\0' && ft_strin(TECHAP, full_cmd[0][i]))
			echap = full_cmd[0][i];
		else if (full_cmd[0][i] == echap)
			echap = '\0';
		if (echap!='\'' && full_cmd[0][i] == '$')
			mi_expand_find(full_cmd, i, mi_sys);
		i++;
	}
}

void	mi_expand_interface (t_cmd *mi_cmd, t_sys *mi_sys)
{
	mi_expand(&mi_cmd->full_cmd, 0, mi_sys);
}
