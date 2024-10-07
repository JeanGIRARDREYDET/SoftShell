/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 08:18:24 by jegirard          #+#    #+#             */
/*   Updated: 2024/07/24 08:18:29 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

int	ft_perror_m(t_app *app, char *s, int code_error, int ind)
{
	perror(s);
	free(s);
	if (app->error[ind] == 0)
		app->error[ind] = code_error;
	return (code_error);
}

int	ft_perror(t_app *app, char *s, int code_error, int ind)
{
	perror(s);
	if (app->error[ind] == 0)
		app->error[ind] = code_error;
	return (code_error);
}
