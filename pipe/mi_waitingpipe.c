/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_waitingpipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:37:40 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/06 15:15:37 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// dans cette fonction, on attend la fin de l'execution du deriers processus 
// lance
// pour le dernier a rendre la main ou aurai utilise 
// while (i < mi_sys->nb_pipe && wait (&status) != 32512)

void	mi_waitingpipe(t_sys *mi_sys)
{
	int			status;

	if (mi_sys->nb_error > 0)
		return ;
	if ((mi_sys->nb_pipe == 1 && (mi_sys->cmd->builtin || ! *mi_sys->cmd->args))
		|| mi_sys->nb_pipe == 0)
		return ;
	waitpid (mi_sys->max_id, &status, 0);
	mi_freeerror (mi_sys);
	mi_logerror (WEXITSTATUS(status), NULL, mi_sys);
}
