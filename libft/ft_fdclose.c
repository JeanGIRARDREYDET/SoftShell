/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdclose.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_fdclose(int fd)
{
	if (fd != -1)
		close (fd);
}

void	ft_fdarrclose(int *fd_arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (fd_arr[i] != -1)
			close(fd_arr[i]);
		i++;
	}
}
