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
		fprintf(stderr, "Cannot get current working directory path\n" );
		if (errno == ERANGE)
		{
			fprintf (stderr, "Buffer size is too small.\n");
		}
		exit (EXIT_FAILURE);
	}
}
