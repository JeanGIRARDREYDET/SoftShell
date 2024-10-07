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
