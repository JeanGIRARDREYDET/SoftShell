/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:47:44 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/15 02:51:15 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	mi_expand_find_error(char **full_cmd, int i, int len, t_sys *mi_sys)
{
	char	*code_error;
	char	*replace;

	code_error = ft_itoa(mi_sys->error->code_error);
	replace = ft_strsubreplace(full_cmd[0], i, len + 1, code_error);
	free(*full_cmd);
	free(code_error);
	*full_cmd = replace;
}

void	mi_expand_find_env(char **full_cmd, int i, int len, t_sys *mi_sys)
{
	char	*search;
	char	*find;
	char	*replace;

	search = ft_substr(full_cmd[0], i, len);
	find = mi_getenv(search + 1, mi_sys);
	free(search);
	if (!find)
		return ;
	replace = ft_strsubreplace(full_cmd[0], i, len, find);
	free(*full_cmd);
	*full_cmd = replace;
}

void	mi_expand_find(char **full_cmd, int i, t_sys *mi_sys)
{
	int		len;

	len = 1;
	while (full_cmd[0][len + i] && ft_isalnum(full_cmd[0][len + i]))
		len++;
	if (len == 1 && full_cmd[0][i + 1] == '?')
		mi_expand_find_error(full_cmd, i, len, mi_sys);
	if (len > 1)
		mi_expand_find_env(full_cmd, i, len, mi_sys);
}

void	mi_expand(char **full_cmd, int i, t_sys *mi_sys)
{
	char	echap;

	if (!full_cmd || !*full_cmd)
		return ;
	echap = '\0';
	while (full_cmd && full_cmd[0][i])
	{
		if (echap == '\0' && ft_strin(TECHAP, full_cmd[0][i]))
			echap = full_cmd[0][i];
		else if (full_cmd[0][i] == echap)
			echap = '\0';
		if (echap != '\'' && full_cmd[0][i] == '$')
			mi_expand_find(full_cmd, i, mi_sys);
		i++;
	}
}

void	mi_expand_interface(t_cmd *mi_cmd, t_sys *mi_sys)
{
	mi_expand(&mi_cmd->full_cmd, 0, mi_sys);
	ft_subchar(mi_cmd->full_cmd, '\"');
}
