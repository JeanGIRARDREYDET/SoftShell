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

t_error	*mi_errornew(int code_error, char *msg)
{
	t_error	*error;

	error = ft_calloc(1, sizeof(t_error));
	if (error == NULL)
		return (NULL);
	error->code_error = code_error;
	error->msg = msg;
	error->next = NULL;
	return (error);
}

void	mi_logerror(int code_error, char *msg, t_error *error)
{

	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	while (error->next != NULL)
		error = error->next;
	error->code_error = code_error;
	error->msg = msg;
	error->next = NULL;	
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
