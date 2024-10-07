/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values_to_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:10:15 by jegirard          #+#    #+#             */
/*   Updated: 2024/03/12 09:10:39 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

int	is_curent_path(char *e)
{
	return (e[0] == 'P' && e[1] == 'W' && e[2] == 'D' && e[3] == '=');
}

int	set_path( t_app *app, char ***e)
{
	int		i;
	char	*path_curent;
	char	*paths;
	char	*pathfinal;

	if (!*e || !*e[0])
		return (1);
	i = 0;
	paths = NULL;
	path_curent = NULL;
	while ((*e)[i])
	{
		if (ft_strnstr ((*e)[i], "PATH=", 5) != 0)
			paths = (*e)[i] + 5;
		if (is_curent_path ((*e)[i]))
			path_curent = (*e)[i] + 4;
		i++;
	}
	pathfinal = join_3 (path_curent, ":", paths);
	app->paths = ft_split (pathfinal, ':');
	free(pathfinal);
	return (1);
}

int	set_values_path_to_pipe(t_app *app, char *cmd, int cnt, int ind)
{
	int		i;
	char	*path_cmd;

	i = -1;
	if (access(cmd, F_OK) == 0)
	{
		app->exe[cnt] = ft_strdup(cmd);
		return (0);
	}
	while (app->paths && app->paths[++i])
	{
		path_cmd = join_3(app->paths[i], "/", cmd);
		if (path_cmd == NULL)
			return (1);
		if (access(path_cmd, F_OK) == 0)
		{
			app->exe[cnt] = ft_strdup(path_cmd);
			free(path_cmd);
			return (0);
		}
		free(path_cmd);
	}
	app->exe[cnt] = NULL;
	return (ft_perror_m (app, ft_strjoin("command not found ", cmd), 127, ind));
}

int	set_cmt_to_pipe(t_app *app, char **argv, int cnt, int ind)
{
	char	*cmd2;
	char	*cmd;
	int		ret;

	ret = 0;
	cmd = ft_strtrim(argv[cnt + 2], " ");
	if (ft_strlen(cmd) == 0)
	{
		ft_perror(app, " command not found ", 127, ind);
		free (cmd);
		return (127);
	}
	if (! ft_strin(cmd, ' '))
		cmd2 = ft_strdup(cmd);
	else
		cmd2 = ft_substr(cmd, 0, ft_strchrpos(cmd, ' '));
	free(cmd);
	ret = set_values_path_to_pipe(app, cmd2, cnt, ind);
	free(cmd2);
	return (ret);
}

int	set_values_to_pipe(t_app *app, char **argv, int cnt)
{
	int	c;

	while (cnt--)
	{
		c = set_cmt_to_pipe(app, argv, cnt, cnt);
		if (c != 0)
		{
			continue ;
		}
		c = access(app->exe[cnt], X_OK);
		if (c != 0)
		{
			ft_perror(app, " Permission denied ", 126, cnt);
			free(app->exe[cnt]);
			app->exe[cnt] = NULL;
		}
	}
	return (0);
}
