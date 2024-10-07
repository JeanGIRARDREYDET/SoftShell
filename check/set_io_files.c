/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_io_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:47:30 by jegirard          #+#    #+#             */
/*   Updated: 2024/08/03 21:47:33 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

int	set_io_files(t_app *s, int argc, char **argv)
{
	int	error;

	error = 0;
	s->fdd[0][0] = open(argv[1], O_RDONLY);
	if (s->fdd[0][0] == -1)
	{
		ft_perror(s, argv[1], 1, 0);
		ft_perror(s, strerror(errno), 1, 0);
		close(s->fdd[0][1]);
		error = 0;
	}
	s->fdd[0][1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (s->fdd[0][1] == -1)
	{
		ft_perror(s, argv[argc - 1], 1, 1);
		ft_perror(s, strerror(errno), 1, 1);
		error = 0;
	}
	return (error);
}
