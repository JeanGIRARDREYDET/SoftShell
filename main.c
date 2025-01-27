/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2025/01/17 16:09:47 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mi_checkmsargument(int argc, char **argv)
{
	if (argc > 1)
	{
		write (2, "Error: minishell does not take arguments. Try: ", 47);
		write (2, argv[0], ft_strlen(argv[0]));
		write (2, "\n", 1);
		exit(0);
	}
}

void	mi_checksyntax(char *line, t_sys *mi_sys)
{
	//mi_sys->code_error = 0;
	if (ft_strrchr(line, '|') != NULL && (ft_strrchr(line, '|') == line 
		|| *(ft_strrchr(line, '|') + 1) == '\0' 
		|| *(ft_strrchr(line, '|') + 1) == '|'))
        mi_logerror(2, "syntax error near unexpected token `|'", mi_sys);
    else if (ft_strrchr(line, '>') != NULL && (ft_strrchr(line, '>') == line 
		|| *(ft_strrchr(line, '>') + 1) == '\0' 
		|| *(ft_strrchr(line, '>') + 1) == '>'))
        mi_logerror(2, "syntax error near unexpected token `>'", mi_sys);
    else if (ft_strrchr(line, '<') != NULL && (ft_strrchr(line, '<') == line 
		|| *(ft_strrchr(line, '<') + 1) == '\0' 
		|| *(ft_strrchr(line, '<') + 1) == '<'))
        mi_logerror(2, "syntax error near unexpected token `<'", mi_sys);
}

void	mi_analyse(char *line, t_sys *mi_sys)
{
	if (g_signal == SIGINT)
		mi_sys->code_error = 130;
	// if (g_signal == SIGQUIT)
	// 	mi_sys->code_error = 131;
	mi_lexingline(line, mi_sys);
	mi_checksyntax(line, mi_sys);
	if (mi_sys->error)
		return ;
	mi_cmditer(mi_sys, &mi_cmdsplitcmd);
	mi_syscmditer(mi_sys, &mi_cmdparsse);
	//mi_sysrediter(mi_sys, OUTPUT, &mi_createdoc);
	//if (mi_sys->error)
	//	return ;
	mi_sysrediter(mi_sys, HEREDOC, &mi_heredoc);
	mi_cmditer(mi_sys, &mi_checkbuiltin);
	mi_syscmditer(mi_sys, &mi_checkpathaccess);
	mi_syscmditer(mi_sys, &mi_execone);
	mi_syscmditer(mi_sys, &mi_waitingcmdipe);
}

int	main(int argc, char **argv, char **env)
{
	char			*line;
	t_sys			mi_sys;

	mi_checkmsargument(argc, argv);
	mi_sysinitialization(env, &mi_sys);
	init_signal();
	while (1)
	{
		line = readline("SoftShell>");
		if (!line)
			mi_freecmdsysexit(1, 26, &mi_sys);
		else if (*line == '\0')
		{
			free(line);
			continue ;
		}
		add_history(line);
		while (*line != '\0' && ft_strrchr(WSPACE, *line) != NULL)
			line++;
		if (g_signal == SIGINT)
			mi_sys.code_error = 130;
		mi_analyse(line, &mi_sys);
		mi_waitingpipe(&mi_sys);
		mi_freecmd(&mi_sys);
		free(line);
		g_signal = 0;
	}
}
