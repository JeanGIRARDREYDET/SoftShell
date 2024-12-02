/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:29:03 by jegirard          #+#    #+#             */
/*   Updated: 2024/11/29 16:41:15 by jegirard         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"
#include <stdint.h>

void	mi_checkline(char *line, t_sys *mi_sys)
{
	if (ft_findword("exit", line))
		builtin_exit(mi_sys);
}

void	mi_checkmsargument(int argc, char **argv)
{
	if (argc > 1)
	{
		printf("Error: minishell does not take arguments. Try: ./%s\n",
			argv[0]);
		exit(0);
	}
}

static int	ft_putnbr_base(char *file, unsigned long n, char *bs, int len, unsigned long lb)
{
	file[1] = '1';
	if (len == 0)
		
	if (n >= lb)
		len = (ft_putnbr_base(file, n / lb, bs, len, lb));

	write (1, &bs[n % lb], 1);
	file[len+24] = *(&bs[n % lb]);
	return (++len);
}


void	mi_heredoc(t_red *red, t_sys *mi_sys)
{	
	char	*line;
	char 	*tmp;
	char 	*tmp2;
	char 	*file;

	file = ft_strdup("/tmp/minidhell_heredoc_012345");
	
	uintptr_t address_as_uintptr = (uintptr_t)red;

    // Cast the address of the pointer to a long
	ft_putnbr_base(file, address_as_uintptr, B62, 0, 61);
	tmp = ft_strdup("");
	dprintf(2,"\n%p\n", tmp);

	while (1)
	{
		line = readline(">");
		if (ft_findword(red->file_name, line))
			break;
		tmp2 = ft_strdup(tmp);
		tmp = join_3(tmp,"\n",line);
		free(tmp2);
	}
	mi_sys->nb_herdoc++;
}
int	main(int argc, char **argv, char **env)
{
	char	*line;
	t_sys	mi_sys;

	mi_checkmsargument(argc, argv);
	mi_sysinitialization(env, &mi_sys);
	while (1)
	{
		signal(SIGINT, &signal_handle_sigint);
		line = readline("minishell> ");
		if (line && *line == '\0')
			continue ;
		else if (line)
			add_history(line);
		else if (!line)
			builtin_exit(&mi_sys);
		while (*line != '\0' && ft_strrchr(WSPACE, *line) != NULL)
			line++;
		mi_checkline(line, &mi_sys);
		mi_lexingline(line, &mi_sys);
		mi_syscmditer(&mi_sys, &mi_expand_interface);
		mi_cmditer(mi_sys.cmd, &mi_cmdsplitcmd);
		mi_syscmditer(&mi_sys, &mi_cmdparsse);
		mi_sysrediter(&mi_sys, HEREDOC, &mi_heredoc);
		mi_cmditer(mi_sys.cmd, &mi_checkbuiltin);
		mi_syscmditer(&mi_sys, &mi_checkpathaccess);
		mi_syscmditer(&mi_sys, &mi_execone);
		mi_waitingpipe(&mi_sys);
		mi_freecmd(&mi_sys);
		//  mi_cmditer (&mi_cmd, &mi_cmdherdoc);
	}
}
