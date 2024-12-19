/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_cmd_parsse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_createcmdargs(t_cmd *mi_cmd, t_sys *mi_sys)

{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (mi_cmd->split && mi_cmd->split[i])
	{
		if (mi_cmd->split[i + 1] && (mi_cmd->split[i][0] == '<'
			|| mi_cmd->split[i][0] == '>'))
			mi_parseredirtocken(&i, &n, mi_cmd, mi_sys);
		i++;
	}
	mi_cmd->args = ft_calloc(i - (2 * n) + 2, sizeof(char *));
}

void	mi_cmdparsse(t_cmd *mi_cmd, t_sys *mi_sys)
{
	int	i;
	int	n;

	if (mi_cmd->full == NULL)
		return ;
	mi_createcmdargs(mi_cmd, mi_sys);
	i = 0;
	n = 0;
	while (mi_cmd->split && mi_cmd->split[i])
	{
		if (mi_cmd->split[i + 1] && (mi_cmd->split[i][0] == '<'
			|| mi_cmd->split[i][0] == '>'))
			i++;
		else
		{
			mi_cmd->args[n] = ft_strdup(mi_cmd->split[i]);
			n++;
		}
		i++;
	}
}
