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
	return (ft_substr(line, c1, (c2- c1)));
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

void	mi_log_pipe_error(int id, char *msg, t_error *mi_error)
{
	mi_error->num = id;
	mi_error->msg = msg;
}

void	enleverspacedeavnt(char *ln)
{
	while (ln[0] < 33 && ln[0] != '\0')
	{
		ln++;
//		i = 0;
	}
}

int	mi_pos_passcote( char *ln, int i, t_error *mi_error)
{
	char	echap;

	while (ln[i] && ln[i] != '\'' && ln[i] != '"' && ln[i] != 0 && ln[i] != '|')
		i++;
	printf("-%c-%d\n", ln[i], ft_strin (TECHAP, ln[i]));
	printf("-%c-%d\n", ln[i], ft_strin (TECHAP, ln[i]));
	if (ft_strin(TECHAP, ln[i]))
	{
		echap = ln[i];
		i++;
		i += ft_pos_left_char ((ln + i), echap);
		if (ln[i] == echap)
			i++;
		else
			mi_log_pipe_error(130, "erreur de quot", mi_error);
	}
	return (i);
}

t_pipe *mi_create_pipe(void)
{
	t_pipe	*pipe;

	pipe = ft_calloc(1, sizeof (t_pipe));
	if (!pipe)
		return (NULL);
	pipe->pid = 0;
	pipe->full_cmd = NULL;
	pipe->cmd = NULL;
	pipe->arg = NULL;
	pipe->args = NULL;
	pipe->error.num = 0;
	pipe->error.msg = NULL;
	pipe->duplexe_canal[0] = 0;
	pipe->duplexe_canal[1] = 0;
	pipe->fdd[0][0] = 0;
	pipe->fdd[0][1] = 0;
	pipe->fdd[1][0] = 0;
	pipe->fdd[1][1] = 0;
	pipe->file = NULL;
	pipe->next = NULL;
	return (pipe);
}

void mi_lexingline(char *ln, int i, t_pipe *cmd_pipe)
{	
	t_pipe		*new_pipe;

	i = mi_pos_passcote(ln, i, &cmd_pipe->error);
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
		mi_lexingline (ln + (++i), 0, new_pipe);
	}
	else
	{
		mi_lexingline (ln, ++i, cmd_pipe);
	}
}

void	mi_lspipetiter(t_pipe *lst, void (*f)(t_pipe *lst))
{
	t_pipe	*i_element;

	i_element = lst;
	while (i_element != NULL)
	{
		(*f)(i_element);
		i_element = i_element->next;
	}
}

void	mi_lssyspipetiter(t_sys *sys, void (*f)(t_pipe *lst, t_sys *sys))
{
	t_pipe	*mi_pipe;

	mi_pipe = sys->pipe;
	while (mi_pipe != NULL)
	{
		(*f)(mi_pipe, sys);
		mi_pipe = mi_pipe->next;
	}
}

static void mi_pipe_parsse(t_pipe *pipe)
{
	pipe->arg = ft_post_left_sep(pipe->full_cmd, WSPACE);
	pipe->cmd = ft_left_sep(pipe->full_cmd, WSPACE);
}

void	ft_pos_passspace(char *ln, int *i)
{
	while (ln[*i] && ft_strchr(WSPACE, ln[*i]))
		(*i)++;
}

void	ft_strrollleft(char *str)
{
	int			i;
	char		c;

	i = 0;
	c = str[0];
	if (!str[0] || !str[1])
		return ;
	while (str[i +1])
	{
		str[i] = str[i + 1];
		i++;
	}
	str[i] = c;
}

char	*ft_strsubreplace(char *str, int start, int len, char *replace)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = ft_calloc(ft_strlen(str) + ft_strlen(replace) - len + 1, sizeof(char));
	while (i < start)
	{
		new[i] = str[i];
		i++;
	}
	while (replace[j])
	{
		new[i] = replace[j];
		i++;
		j++;
	}
	j = start + len;
	while (str[j])
	{
		new[i] = str[j];
		i++;
		j++;
	}
	return (new);
}

void	mi_expand_find(char **ln, int i, t_sys *sys)
{
	char	*search;
	char	*find;
	char	*replace;
	int		len;

	len = 1;
	while (ln[0][len +i] && ft_isalnum(ln[0][len +i]))
		len++;
	if (len > 1)
	{
		search = ft_substr(ln[0], i, len);
		find = s_getenv(search + 1, sys);
		free(search);
		replace = ft_strsubreplace(ln[0] ,i, len, find);
		free(*ln);
		*ln = replace;
	}
}

void mi_expand(char **ln, int i, t_sys *sys)
{
	char echap;

	echap = '\0';
	while (ln[0][i])
	{
		if (echap && ln[0][i] == '\'' && ft_strin(TECHAP, ln[0][i]))
				echap = ln[0][i];
		else if (ln[0][i] == echap)
				echap = '\0';
		if (echap!='\'' && ln[0][i] == '$')
				mi_expand_find(ln, i, sys);
		i++;
	}
}

void mi_expand_interface (t_pipe *pipe, t_sys *mi_sys) 
{
	mi_expand(&pipe->full_cmd, 0,mi_sys);
}

void ft_pos_passstring(char *ln, int *i)
{
	char echap;

	echap = '\0';
	while (ln[*i] && (!ft_strchr(WSPACE, ln[*i] ) || echap!= '\0'))
	{
		if ((echap == '\0') && ft_strchr(TECHAP, ln[*i]))
			echap = ft_strchr(TECHAP, ln[*i])[0];
		else if (ln[*i] == echap)
			echap = '\0';
		(*i)++;
	}

}

	static void ft_cnt_arg(char *ln, int *i, int *n)
{
	ft_pos_passspace(ln, i);
	ft_pos_passstring(ln, i);
	(*n)++;
	if (ln[*i])
		ft_cnt_arg(ln,i,n);
}

static void mi_pipe_arg_parsse(t_pipe *lst)
{
	int i;
	int s;
	int n;

	i = 0;
	n = 0;
	ft_cnt_arg(lst->full_cmd, &i, &n);
	if (n > 0)
	{
		lst->args = ft_calloc(n + 1, sizeof (char *));
		if (lst->args == NULL)
			return ;
		n = 0;
		i = 0;
		while (lst->full_cmd[i])
		{
			ft_pos_passspace(lst->full_cmd, &i);
			s = i;
			ft_pos_passstring(lst->full_cmd, &i);
			lst->args[n] = ft_substr(lst->full_cmd, s, i -s);
			n++;
		}
	}
}

int	main(int ac, char **argv, char **env)
{
	char	*line;
	int		l_len;
	t_sys	sys;
	t_pipe	pipe;

	if (ac > 1)
	{
		printf("Error: minishell does not take arguments. Try: ./%s\n", argv[0]);
		exit(0);
	}
	common_initialization(env, &sys);
	while (1)
	{	
		line = readline("minishell> ");
		l_len = ft_strlen(line);
		
		pipe = *mi_create_pipe();
		mi_lexingline (line, 0, &pipe);
		sys.pipe = &pipe;
		mi_lssyspipetiter (&sys, &mi_expand_interface);
		mi_lspipetiter (&pipe, &mi_pipe_parsse);
		mi_lspipetiter (&pipe, &mi_pipe_arg_parsse);
		if (ft_strncmp(line, "exit", 5) == 0 && ft_strlen(line) == 4)
		{
			printf("exit\n");
			exit(0);
		}
		else if (ft_strncmp(line, "env", 4) == 0)
			builtin_env(&sys);
		else if (ft_strncmp(line, "env", 4) == 0)
			builtin_env(&sys);
		else if (ft_strncmp(line, "pwd", 4) == 0)
			builtin_pwd();
		else if (ft_strncmp(line, "echo", 4) == 0 && (l_len==4 || (l_len >4  && (line[4]) < 33 ) ))	
			builtin_echo(ft_post_left_sep(line, WSPACE));
		else if (ft_strncmp(line, "cd", 2) == 0 && (l_len==2 || (l_len >2  && (line[2]) < 33 ) ))
			builtin_cd(ft_post_left_sep(line, WSPACE), &sys);
		else if (ft_strncmp(line, "unset", 5) == 0)
			s_unset(ft_post_left_sep(line, WSPACE), &sys);
		else if (ft_strncmp(line, "export", 6) == 0)
			builtin_export(ft_post_left_sep(line, WSPACE), &sys);
		// else if (ft_strncmp(line, "echo", 5) == 0)
		// 	builtin_echo();
		add_history(line);
	}
}
