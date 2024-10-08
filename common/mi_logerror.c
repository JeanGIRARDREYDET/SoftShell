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
	perror(msg);
	while (mi_error->next != NULL)
		mi_error = mi_error->next;
	if (mi_error->msg == NULL)
		mi_error->next = ft_calloc(1, sizeof(t_error));
	else
		mi_error = ft_calloc(1, sizeof(t_error));
	if (mi_error->next == NULL)
		return ;
	mi_error->code_error = code_error;
	mi_error->msg = msg;
}
void	mi_logerrorlong(int code, char *m1, char *m2, char *m3, t_error *mi_err)
{
	mi_logerror(code, join_3(m1, m2, m3), mi_err);
}
int	mi_perror(t_pipe *app, char *s, int code)
{
	perror(s);
	mi_logerror(code, s, &app->error);
	free(s);
	return (code);
}
