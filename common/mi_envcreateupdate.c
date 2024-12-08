/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_envcreateupdate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	s_env_create_value(char *line, t_sys *mi_sys)
{
	char		**ienv;
	int			i;

	mi_sys->len_env += 2;
	ienv = (char **)ft_calloc(mi_sys->len_env, sizeof(char *));
	if (ienv == NULL)
	{
		mi_logerror(126, "Cannot allocate memory", mi_sys);
		mi_sys->exit_status = EXIT_FAILURE;
	}
	i = -1;
	while (mi_sys->env[++i])
		ienv[i] = ft_strdup(mi_sys->env[i]);
	if (ienv != NULL && ienv[i] == NULL)
		ienv[i] = line;
	free (mi_sys->env);
	mi_sys->env = ienv;
}

void	s_env_create_update_value(char *key, t_sys *mi_sys)
{
	int			pos;
	char		*msg;

	if (!key || key[0] == '=')
	{
		msg = join_3("export: `", key, "' not a valid identifier");
		mi_logerror(1, msg, mi_sys);
		free(msg);
		mi_sys->exit_status = EXIT_FAILURE;
		return ;
	}
	pos = ft_get_confpos(key, '=', mi_sys->env);
	if (pos == -1)
		s_env_create_value (ft_strdup(key), mi_sys);
	else
	{
		free(mi_sys->env[pos]);
		mi_sys->env[pos] = key;
	}
	mi_sys->exit_status = EXIT_SUCCESS;
}

void	s_env_create_update_key_value(char *key, char *value, t_sys *mi_sys)
{
	char			*str_pwd;

	str_pwd = join_3(key, "=", value);
	s_env_create_update_value (str_pwd, mi_sys);
}

int	mi_export_values(char **key, t_sys *mi_sys)
{
	int			i;

	i = 1;
	while (key[i] != NULL)
		s_env_create_update_value(key[i++], mi_sys);
	return (mi_sys->exit_status);
}
