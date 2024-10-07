/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_child_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:07:28 by jegirard          #+#    #+#             */
/*   Updated: 2024/07/24 12:07:31 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

int	ft_exec_child_in(t_app *app, char **argv, int ind, char **env)
{
	if (app->pid == 0)
		return (0);
	app->pid = fork();
	if (app->pid == -1)
		return (ft_perror(app, "fork failed in :", 3, 0));
	if (app->pid != 0)
		return (0);
	if (dup2(app->fdd[1][1], STDOUT_FILENO) == -1)
		return (1);
	close (app->fdd[1][0]);
	if (dup2(app->fdd[0][0], STDIN_FILENO) == -1)
		return (1);
	close_pipe (app, 1);
	if (app->exe[ind] != NULL)
		ft_exec_cmd(app, argv, ind, env);
	free_pipe (app);
	exit (EXIT_FAILURE);
	return (errno);
}
