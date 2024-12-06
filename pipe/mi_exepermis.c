/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_exepermis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:43:26 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/06 17:43:50 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_exepermis(t_cmd *mi, t_sys *mi_sys)
{
	char	*error_msg;

	if (access(mi->args[0], X_OK) == 0)
		return ;
	error_msg = join_3("minishell: ", mi->args[0], ": Permission denied\n");
	mi_logerror(126, error_msg, mi_sys);
	free(error_msg);
	mi_sys->nb_error++;
}
