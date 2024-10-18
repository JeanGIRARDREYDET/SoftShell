/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_execone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:50:42 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/04 19:50:46 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_exefind(t_cmd *mi_cmd, t_sys *mi_sys)
{
	char		*cmd;
	char		**paths;
	int			i;
	char		*error_msg;

	i = 0;
	if (access(mi_cmd->cmd, F_OK) == 0)
		return ;
	i = 0;
	cmd = join_3(mi_getenv("PWD", mi_sys), "/", mi_cmd->cmd);
	if (access(mi_cmd->cmd, F_OK) == 0)
		return ;
	paths = ft_split (mi_getenv("PATH", mi_sys), ':');
	while (paths && paths[++i])
	{
		cmd = join_3(paths[i], "/", mi_cmd->cmd);
		if (access(cmd, F_OK) == 0)
		{
			mi_cmd->cmd = cmd;
			free(paths);
			return ;
		}
		free(cmd);
	}
	error_msg = join_3 ("minishell: ", mi_cmd->cmd, ": command not found\n");
	mi_logerror(126, error_msg, &mi_cmd->error);
	free(cmd);
	free(paths);
	return ;
}

void	mi_exepermis(t_cmd *pi, t_sys *mi_sys)
{
	if (access(pi->cmd, X_OK) == 0)
		return ;
	mi_logerrorlong(126, "mi: ", pi->cmd, ": Permission denied", &pi->error);
	mi_sys->nb_error++;
}
// https://www.mbillaud.fr/notes/pipeline.html
// l0
int	mi_execchild(t_cmd *mi_cmd, t_sys *mi_sys)
{
//	printf("mi_execchild\n");
	if (mi_cmd->next != NULL)
	{
//		printf("pipe\n");
		if (pipe(mi_cmd->fd) == -1)
			return (mi_intlogerror (mi_cmd, "pipe out failed", 1));
	}
	mi_cmd->id = fork();
//	dprintf(2, "<mi_execchild no='%d' id='%d' cmd='%s'>\n", mi_cmd->no, mi_cmd->id , mi_cmd->cmd);
	if (mi_cmd->id == -1)
		return (mi_intlogerror (mi_cmd, "fork out failed", 1));
//	dprintf(2, "72/n");
	if (mi_cmd->id == 0)
	{
		if (mi_cmd->no != 0)
		{
//			dprintf(2, "	sec+	fd ='%d'\n", mi_cmd->fd[0]);
			if (dup2(mi_sys->fd_in, STDIN_FILENO) == -1)
				return (1);
			close (mi_sys->fd_in);
//			dprintf(2, "	sec+ end	fd ='%d'\n", mi_cmd->fd[0]);
		}
//		dprintf(2, "96/n");
		if (mi_cmd->next != NULL)
		{
//			dprintf(2, "	-last	fd ='%d'\n", mi_cmd->fd[1]);
			if (dup2(mi_cmd->fd[1], STDOUT_FILENO) == -1)
				return (1);
//			dprintf(2, "	-last close	fd ='%d'\n", mi_cmd->fd[1]);
			close (mi_cmd->fd[0]);
			close (mi_cmd->fd[1]);
//			dprintf(2, "	-last end	fd ='%d'\n", mi_cmd->fd[1]);
		}
		if (mi_cmd->cmd != NULL)
			mi_execcmd(mi_cmd, mi_sys);
		exit (EXIT_FAILURE);
	}
	if (mi_cmd->no != 0)
		close (mi_sys->fd_in);
//	dprintf(2, "	- 109 close	fd ='%d'\n", mi_sys->fd_in);
	if (mi_cmd->next != NULL)
	{
//		dprintf(2, "	-close	fd ='%d'\n", mi_sys->fd_in);
		close (mi_cmd->fd[1]);
		mi_sys->fd_in = mi_cmd->fd[0];
//		dprintf(2, "	-close	fd ='%d'\n", mi_sys->fd_in);
	}
//	dprintf(2, "</mi_execchild no='%d' id='%d' cmd='%s'>\n", mi_cmd->no, mi_cmd->id, mi_cmd->cmd);
	//	mi_freecmd (mi_cmd);
	//	exit (EXIT_FAILURE);
	return (0);
}

	/*
if (mi_cmd->id != 0)
	{

	waitpid(mi_cmd->id, &mi_cmd->status, 0);
		if (WIFEXITED(mi_cmd->status))
			mi_cmd->status = WEXITSTATUS(mi_cmd->status);
		if (mi_cmd->status == 0)
			return (0);

		return (1);
	}

	*/	


	/*
	
	if (mi_cmd->no != 0)
	{
//		dprintf(2, "\t78 id = %d\n", mi_cmd->id);
		if (dup2(mi_cmd->fdd[1], STDOUT_FILENO) == -1)
			return (1);
		close (mi_cmd->fdd);
	}
	if (mi_cmd->next != NULL)
	{
//		dprintf(2, "\t end id = %d\n", mi_cmd->id);
		if (dup2(mi_cmd->fdd[1], STDIN_FILENO) == -1)
			return (1);
		close (mi_cmd->fdd[0]);
	}
	else
	{
//		dprintf(2, "\t92  id = %d\n", mi_cmd->id);
		if (dup2(mi_cmd->fdd[0], STDIN_FILENO) == -1)
			return (1);
		close (mi_cmd->fdd[0]);
		if (dup2(mi_cmd->fdd[1], STDOUT_FILENO) == -1)
			return (1);
		close (mi_cmd->fdd[1]);
	}
	if (mi_cmd->cmd != NULL)
	{
		close(mi_cmd->fdd[0]);
		close(mi_cmd->fdd[1]);
	//	if (mi_cmd->redirection != NULL)
	//		mi_redirection(mi_cmd);
		if (mi_cmd->cmd != NULL)
		{
			mi_expand_interface(mi_cmd, mi_sys);
			mi_execone(mi_cmd, mi_sys);
		}

	}
		mi_execcmd(mi_cmd, mi_sys);
	
	*/
	
	//dprintf(1, "%s\n", mi_cmd->cmd);
	//mi_freecmd (mi_cmd);
//	dprintf(2, "</&; id='%d' cmd='%s'>\n", mi_cmd->id , mi_cmd->cmd);
	//exit (EXIT_FAILURE);
//	return (1);
//}

void	mi_execone(t_cmd *mi_cmd, t_sys *mi_sys)
{
	if (ft_strncmp(mi_cmd->cmd, "exit", 5) == 0)
	{
		printf("exit\n");
		exit(0);
	}
	else if (ft_strncmp(mi_cmd->cmd, "env", 4) == 0)
		builtin_env(mi_sys);
	else if (ft_strncmp(mi_cmd->cmd, "env", 4) == 0)
		builtin_env(mi_sys);
	else if (ft_strncmp(mi_cmd->cmd, "pwd", 4) == 0)
		builtin_pwd();
	else if (ft_strncmp(mi_cmd->cmd, "echo", 4) == 0)
		builtin_echo(ft_post_left_sep(mi_cmd->cmd, WSPACE));
	else if (ft_strncmp(mi_cmd->cmd, "cd", 2) == 0)
		builtin_cd(ft_post_left_sep(mi_cmd->cmd, WSPACE), mi_sys);
	else if (ft_strncmp(mi_cmd->cmd, "unset", 5) == 0)
		builtin_unset(mi_cmd->args[0], mi_sys);
	else if (ft_strncmp(mi_cmd->cmd, "export", 6) == 0)
		builtin_export(ft_post_left_sep(mi_cmd->cmd, WSPACE), mi_sys);
	else
		mi_cmd->builtin = false;
	if (mi_cmd->builtin == false)
	{
		mi_exefind(mi_cmd, mi_sys);
		if (mi_cmd->cmd)
			mi_exepermis(mi_cmd, mi_sys);
		if (mi_cmd->cmd)
			mi_execchild(mi_cmd, mi_sys);
	}
}
