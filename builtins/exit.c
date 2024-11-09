/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit .c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:01:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/14 11:01:41 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_exit(t_sys *mi_sys)
{
	mi_freecmd(mi_sys->cmd, mi_sys);
	mi_sys = NULL;
	exit(EXIT_SUCCESS);
}
