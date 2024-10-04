/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_logpipeerror.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:47:50 by jegirard          #+#    #+#             */
/*   Updated: 2024/09/23 14:47:55 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_logpipeerror(int id, char *msg, t_error *mi_error)
{
	mi_error->num = id;
	mi_error->msg = msg;
}