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
	printf("-%c-%d\n", ln[i], ft_strin (TECHAP, ln[i]));
	printf("-%c-%d\n", ln[i], ft_strin (TECHAP, ln[i]));
	if (ft_strin(TECHAP, ln[i]))
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

void	s_lssyspipetiter(t_sys *sys, void (*f)(t_pipe *lst, t_sys *sys))
{
	t_pipe	*i_element;

	i_element = sys->pipe;
	while (i_element != NULL)
	{
		(*f)(i_element, sys);
		i_element = i_element->next;
	}
}

static void s_pipe_parsse(t_pipe *pipe)
{
	pipe->arg = ft_post_left_sep(pipe->full_cmd, WSPACE);
	pipe->cmd = ft_left_sep(pipe->full_cmd, WSPACE);
}

void	s_pos_passspace(char *ln, int *i)
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

void	s_expand_find(char **ln, int i, t_sys *sys)
{
	char	*find;
	char	*Retur;
	char	*Retur2;
	int		l;

	l = 1;
	while (ln[0][l +i] && ft_isalnum(ln[0][l +i]))
		l++;
	if (l > 1)
	{
		find = ft_substr(ln[0], i, l);
		Retur = s_getenv(find + 1, sys);
		free(find);
		Retur2 = ft_strsubreplace(ln[0] ,i, l, Retur);
		free(*ln);
		*ln = Retur2;
	}
}

void s_expand(char **ln, int i, t_sys *sys)
{
	char echap;

	echap = '\0';
	while (ln[0][i])
	{
		if (echap && ln[0][i] == '\'' && ft_strin(TECHAP, ln[0][i]))
				echap = ln[0][i];
		else if (ln[0][i] == echap)
				echap = '\0';
		else if (!echap && ln[0][i] == '$')
				s_expand_find(ln, i, sys);
		i++;
	}
}
void expand_interface (t_pipe *pipe, t_sys *sys) 
{
	printf("expand_interface\n");
	s_expand(&pipe->full_cmd, 0,sys);
	printf("expand_interface\n");
}

void s_pos_passstring(char *ln, int *i)
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

static void cnt_arg(char *ln, int *i, int *n)
{
	s_pos_passspace(ln, i);
	s_pos_passstring(ln, i);
	(*n)++;
	if (ln[*i])
		cnt_arg(ln,i,n);
}

static void s_pipe_arg_parsse(t_pipe *lst)
{
	int i;
	int s;
	int n;

	i = 0;
	n = 0;
	cnt_arg(lst->full_cmd, &i, &n);
	if (n > 0)
	{
		lst->args = ft_calloc(n + 1, sizeof (char *));
		if (lst->args == NULL)
			return ;
		n = 0;
		i = 0;
		while (lst->full_cmd[i])
		{
			s_pos_passspace(lst->full_cmd, &i);
			s = i;
			s_pos_passstring(lst->full_cmd, &i);
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
		
		s_lexingline (line, 0, &pipe);
		sys.pipe = &pipe;
		s_lssyspipetiter (&sys, &expand_interface);
		s_lspipetiter (&pipe, &s_pipe_parsse);
		s_lspipetiter (&pipe, &s_pipe_arg_parsse);


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
