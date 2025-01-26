/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:31:05 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_expand(char **full_cmd, int i, t_sys *mi_sys)
{
	char	echap;

	if (!full_cmd || !*full_cmd)
		return ;
	echap = '\0';
	while (full_cmd && full_cmd[0][i] != '\0')
	{
		if (echap == '\0' && ft_strin(TECHAP, full_cmd[0][i]))
			echap = full_cmd[0][i];
		else if (full_cmd[0][i] == echap)
			echap = '\0';
		if (echap != '\'' && full_cmd[0][i] == '$')
			mi_expand_find(full_cmd, i, mi_sys);
		if (ft_strin(TECHAP, full_cmd[0][i])
				&& (full_cmd[0][i] == echap || echap == '\0'))
			mi_expandrepalceone(full_cmd, i);
		else
			i++;
	}
}

void	mi_expand_interface(t_cmd *mi_cmd, t_sys *mi_sys)
{
	mi_expand(&mi_cmd->full, 0, mi_sys);
}
