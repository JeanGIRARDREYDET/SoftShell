/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_redis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:26:27 by jegirard          #+#    #+#             */
/*   Updated: 2024/11/27 17:26:40 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	mi_redis(t_cmd *mi_cmd, int type)
{
	while (mi_cmd->red)
	{
		if (mi_cmd->red->redir_type == type)
			return (true);
		mi_cmd->red = mi_cmd->red->next;
	}
	return (false);
}
