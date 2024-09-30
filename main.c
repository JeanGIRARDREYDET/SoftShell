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
char *find_command(char *line)
{
	int	i;
	int	c1;
	int	c2;

	i = 0;
	while (line[i] < 33)
		i++;
	c1= i;	
	while (line[i] > 32)
		i++;
	c2 = i;
	while (line[i] < 33)
		i++;
	return (ft_substr(line,c1,(c2-c1)));
}

char *find_expand(char *line)
{
	int	i;
	int	c1;
	int	c2;
	// 34 39
	i = 0;
	while (line[i] != '\0')
	{
		while (line[i] != '$')
		{
			i++;
			c1 = i;
		}
		while (line[i] > 32)
		{
			i++;
			c2 = i;
		}
		while (line[i] < 33)
			i++;
	}
	return (ft_substr(line,c1,(c2-c1)));
} 

void	s_log_pipe_error(int id, char *msg, t_error *s_error)
{
	s_error->num = id;
	s_error->msg = msg;
}

void	enleverspacedeavnt(char *ln)
{
	while (ln[0] < 33 && ln[0] != '\0')
	{
		ln++;
//		i = 0;
	}
}

int	s_pos_passcote( char *ln, int i, t_error *s_error)
{
	while (ln[i] && ln[i] != '\'' && ln[i] != '"' && ln[i] != 0 && ln[i] != '|')
		i++;
	if (ft_strchr (TECHAP, ln[i]))
	{
		i = i + 2 + ft_pos_left_char ((ln + i + 1), &ln[i]);
		if (ln[i] == '\0')
			s_log_pipe_error(130, "erreur de quot", s_error);
		else
			i++;
	}
	return (i);
}



void s_lexingline(char *ln, int i, t_pipe *cmd_pipe)
{	
	t_pipe		*new_pipe;

	i = s_pos_passcote(ln, i, &cmd_pipe->error);
	while (ln[i] && ft_strchr(WSPACE, ln[i]))
		i++;
	if (ln[i] == '\0')
	{
		cmd_pipe->full_cmd = ft_strtrim_param(ln, 0, i, WSPACE);
		cmd_pipe->next = NULL;
		return ;
	}
	else if (ln[i] == '|')
	{
		new_pipe = ft_calloc(1, sizeof (t_pipe));
		if (!new_pipe)
			return ;
		cmd_pipe->full_cmd = ft_strtrim_param(ln, 0, i -1, WSPACE);
		cmd_pipe->next = new_pipe;
		s_lexingline (ln + (++i), 0, new_pipe);
	}
	else
	{
		s_lexingline (ln, ++i, cmd_pipe);
	}
}

void	s_lspipetiter(t_pipe *lst, void (*f)(t_pipe *lst))
{
	t_pipe	*i_element;

	i_element = lst;
	while (i_element != NULL)
	{
		(*f)(i_element);
		i_element = i_element->next;
	}
}

static void s_pipe_parsse(t_pipe *lst)
{
	lst->arg = ft_post_left_sep(lst->full_cmd, WSPACE);
	lst->cmd = ft_left_sep(lst->full_cmd, WSPACE);
}


void s_pos_passspace(char *ln, int *i)
{
	while (ln[*i] && ft_strchr(WSPACE, ln[*i]))
		(*i)++;
}

static void s_pipe_arg_parsse(t_pipe *lst)
{
	int i;
	int n;
	char *tmp;
	
	i = 0;
	n = 0;
	s_pos_passspace(lst->arg, &i);

	printf("-%d-\n", i);
	if(lst->arg[i])
	{
		
		while (lst->arg[i] && !ft_strchr(WSPACE, lst->arg[i]))
		{
			i++;
		}
		//lst->args
		tmp = ft_calloc(n + 1, sizeof (char *));
		if (!lst->args)
			return ;
		i = 0;
		n = 0;
		//while (lst->arg[i] && !ft_strchr(WSPACE, lst->arg[i]))
		while (tmp[n]  && !ft_strchr(WSPACE, lst->arg[i]))
		{
			//lst->args
			tmps[n] = ft_post_left_sep(lst->arg + i, WSPACE);
			//i = i + ft_strlen(lst->args[n]);
			tmp[n] = ft_strtrim_param(tmp[n], 0, ft_strlen(tmp[n]), WSPACE);
			n++;
		}
	}

}


int	main(int ac, char **argv, char **env)
{
	char	*line;
	int		l_len;
	t_sys	s_sys;
	t_pipe	s_pipe;

	if (ac > 1)
	{
		printf("Error: minishell does not take arguments. Try: ./%s\n", argv[0]);
		exit(0);
	}
	common_initialization(env, &s_sys);
	while (1)
	{	
		line = readline("minishell> ");
		l_len = ft_strlen(line);
		s_lexingline (line, 0, &s_pipe);
		s_lspipetiter (&s_pipe, &s_pipe_parsse);
		s_lspipetiter (&s_pipe, &s_pipe_arg_parsse);
		printf("-%s-\n", ft_strchr (TECHAP, '\0'));
		if ( ft_strchr (TECHAP, '\0'))
			printf("A\n");
		if (ft_strncmp(line, "exit", 5) == 0 && ft_strlen(line) == 4)
		{
			printf("exit\n");
			exit(0);
		}
		else if (ft_strncmp(line, "env", 4) == 0)
			builtin_env(&s_sys);
		else if (ft_strncmp(line, "env", 4) == 0)
			builtin_env(&s_sys);
		else if (ft_strncmp(line, "pwd", 4) == 0)
			builtin_pwd();
		else if (ft_strncmp(line, "echo", 4) == 0 && (l_len==4 || (l_len >4  && (line[4]) < 33 ) ))	
			builtin_echo(ft_post_left_sep(line, WSPACE));
		else if (ft_strncmp(line, "cd", 2) == 0 && (l_len==2 || (l_len >2  && (line[2]) < 33 ) ))
			builtin_cd(ft_post_left_sep(line, WSPACE), &s_sys);
		else if (ft_strncmp(line, "unset", 5) == 0)
			s_unset(ft_post_left_sep(line, WSPACE), &s_sys);
		else if (ft_strncmp(line, "export", 6) == 0)
			builtin_export(ft_post_left_sep(line, WSPACE), &s_sys);
		// else if (ft_strncmp(line, "echo", 5) == 0)
		// 	builtin_echo();
		add_history(line);
	}
}
