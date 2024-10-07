/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_child_out.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:07:44 by jegirard          #+#    #+#             */
/*   Updated: 2024/07/24 12:07:48 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

int	ft_exec_child_out(t_app *app, char **argv, int ind, char **env)
{
	if (app->pid == 0)
		return (0);
	app->pid = fork();
	if (app->pid == -1)
		return (ft_perror (app, "fork out failed", 1, 1));
	if (app->pid != 0)
		return (0);
	if (dup2(app->fdd[1][0], STDIN_FILENO) == -1)
		return (1);
	close (app->fdd[1][1]);
	if (dup2(app->fdd[0][1], STDOUT_FILENO) == -1)
		return (1);
	close_pipe (app, 1);
	if (app->exe[ind] != NULL)
		ft_exec_cmd(app, argv, ind, env);
	free_pipe (app);
	exit (EXIT_FAILURE);
	return (1);
}
