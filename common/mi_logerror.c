/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_logerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:47:50 by jegirard          #+#    #+#             */
/*   Updated: 2024/09/23 14:47:55 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_logerror(int code_error, char *msg, t_error *mi_error)
{
	t_error		*error;

	perror(msg);
	error = ft_calloc(1, sizeof(t_error));
	error->code_error = code_error;
	error->msg = msg;
	error->next = NULL;
//	while (mi_error != NULL)
//		mi_error = mi_error->next;
	mi_error = error;
}

void	mi_logerrorlong(int code, char *m1, char *m2, char *m3, t_error *mi_err)
{
	mi_logerror(code, join_3(m1, m2, m3), mi_err);
}

int	mi_intlogerror(t_cmd *app, char *s, int code)
{
	perror(s);
	mi_logerror(code, s, &app->error);
	return (code);
}
