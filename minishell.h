/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:09:10 by doferet           #+#    #+#             */
/*   Updated: 2024/09/06 10:18:30 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <dirent.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <string.h>
# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_sys
{
	int		duplexe_canal[2];
	int		fdd[2][2];
	int		pid;
	int		status;
	int		here_doc;
	char	*pwd;
	char	*path;
	char	*shlvl;
	char	**cmd_args;
	char	**env;
	int		env_len;
	char	*exe[5];
	char	*cmd;
	int		error[2];
}	t_sys;

void	builtin_cd(char *key, t_sys *s_sys);
void	builtin_echo(char *key, t_sys *s_sys);
void	builtin_env(t_sys *sys);
void	builtin_exit(t_sys *sys);
void	builtin_export(char *key, t_sys *s_sys);
void	builtin_pwd(t_sys *sys);
void	builtin_unset(char *line, t_sys *sys);

void	common_initialization(char **env, t_sys *sys);

void	ft_arrclose(char **arr);

int		ft_atoi(const char *str);

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size);

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);

char	*ft_left_sep(char *src, const char c);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_lstsize(t_list *lst);

void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);

char	*ft_post_left_sep(char *src, const char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

char	**ft_split(char const *s, char c);
size_t	ft_strchr_pos(const char *source, int find);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
int		ft_strin(const char *s, const char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

size_t	ft_tablen(char const **str);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif
