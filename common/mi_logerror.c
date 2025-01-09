/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_logerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
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

void	mi_logerror(int code_error, char *msg, t_sys *mi_sys)
{
	t_error	*error;

	if (code_error != 0)
		mi_sys->nb_error++;
	if (msg != NULL)
	{
		write(STDERR_FILENO, msg, ft_strlen(msg));
		write(STDERR_FILENO, "\n", 1);
	}
	if (mi_sys->error == NULL)
		mi_sys->error = mi_errornew(code_error, msg);
	else if (code_error == 0)
		return ;
	else
	{
		error = mi_sys->error;
		while (error != NULL && error->next != NULL)
			error = error->next;
		error->next = mi_errornew(code_error, msg);
	}
}

int	mi_intlogerror(t_sys *mi_sys, char *s, int code)
{
	perror(s);
	mi_logerror(code, s, mi_sys);
	return (code);
}
void	mi_logerror2(int code_error, char *msg1, char *msg2, t_sys *mi_sys)
{
	char	*msg;

	msg	= ft_strjoin(msg1, msg2);
	mi_logerror(code_error, msg, mi_sys);
	free(msg);
}
