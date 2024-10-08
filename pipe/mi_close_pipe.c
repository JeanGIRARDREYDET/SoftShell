/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_close_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:37:18 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/08 11:37:20 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_close_pipe(t_app *app, int nb)
{
	nb++;
	while (nb--)
	{
		if (app->fdd[nb][0] != -1)
			close(app->fdd[nb][0]);
		if (app->fdd[nb][1] != -1)
			close(app->fdd[nb][1]);
	}
}
