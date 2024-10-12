/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:08:01 by doferet           #+#    #+#             */
/*   Updated: 2024/09/10 14:56:19 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_status;
void	mi_pipe_acc(t_pipe *mi_pipe, t_sys *mi_sys)
{
	char		*cmd;

	if (access(mi_pipe->cmd, F_OK) == 0)
		return;
	cmd = join_3(mi_getenv("PWD", mi_sys), "/", "mi_pipe->cmd");
//	if (access(mi_pipe->cmd, F_OK) == 0)
//		return;
	mi_sys->nb_error++;
}


void	mi_pipe_exec(t_pipe *mi_pipe, t_sys *mi_sys)
{


	printf("debut mi_exec \n\t\t%s\t\t%s\n", mi_pipe->cmd, mi_pipe->cmd);



		mi_pipe_acc(mi_pipe,mi_sys);
		//mi_exefind(pipe, mi_sys);
		printf("fin mi_exec\n");


//			if (!mi_pipe->next && pipe(mi_pipe->fdd) == -1)
//				mi_logerror(126, "pipe", &mi_pipe->error);
//		mi_execone(mi_pipe, mi_sys);

	
	mi_sys->nb_error++;
}



int	main(int ac, char **argv, char **env)
{
	char	*line;
	t_sys	mi_sys;
	t_pipe	mi_pipe;

	if (ac > 1)
	{
		printf("Error: minishell does not take arguments. Try: ./%s\n", argv[0]);
		exit(0);
	}
	mi_sysinitialization(env, &mi_sys);
	while (1)
	{
		line = readline("minishell> ");
		if (*line =='\0')
			continue;
		mi_sys.nb_pipe = 0;
		mi_pipe = *mi_createpipe(&mi_sys);
		mi_lexingline (line, 0, &mi_pipe, &mi_sys);
		mi_sys.pipe = &mi_pipe;
		mi_syspipeiter (&mi_sys, &mi_expand_interface);
		mi_pipeiter (&mi_pipe, &mi_pipeparsse);
		mi_pipeiter (&mi_pipe, &mi_pipeargparsse);
//		mi_pipeiter (&mi_pipe, &mi_pipeherdoc);
		mi_syspipeiter (&mi_sys, &mi_pipe_exec);
//		mi_exec(&mi_pipe, &mi_sys);
		add_history(line);
	}
}
