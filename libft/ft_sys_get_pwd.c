/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sys_get_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:45:24 by jegirard          #+#    #+#             */
/*   Updated: 2024/09/20 11:45:54 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_sys_get_pwd(char **buf)
{
	*buf = getcwd(NULL, 0);
	if (*buf == NULL)
	{
		write(STDERR_FILENO, "Cannot get current working directory path\n", 43);
		if (errno == ERANGE)
		{
			write (STDERR_FILENO, "Buffer size is too small.\n", 26);
		}
		exit (EXIT_FAILURE);
	}
}
