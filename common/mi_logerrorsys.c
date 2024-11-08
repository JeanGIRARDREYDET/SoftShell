/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_logerrorsys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:42:01 by jegirard          #+#    #+#             */
/*   Updated: 2024/11/08 18:42:05 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_logerrorsys(int no, char *msg, t_sys *mi_sys)
{
	if (msg)
	{
		write(STDERR_FILENO, msg, ft_strlen(msg));
		write(STDERR_FILENO, "\n", 1);
	}
	mi_sys->error = mi_errornew(no, msg);
}

void	mi_logerrorcmd(int no, char *msg, t_cmd *mi_cmd)
{
	if (msg)
	{
		write(STDERR_FILENO, msg, ft_strlen(msg));
		write(STDERR_FILENO, "\n", 1);
	}
	mi_cmd->error = mi_errornew(no, msg);
}
