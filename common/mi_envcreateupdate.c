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

	ienv = (char **)ft_calloc(mi_sys->len_env + 2, sizeof(char *));
	if (ienv == NULL)
	{
		mi_logerror(126, "Cannot allocate memory", mi_sys);
		mi_sys->exit_status = EXIT_FAILURE;
	}
	i = 0;
	while (i <= mi_sys->len_env)
	{
		ienv[i] = ft_strdup(mi_sys->env[i]);
		free(mi_sys->env[i]);
		i++;
	}
	ienv[i] = ft_strdup(line);
	mi_sys->len_env = i;
	free (mi_sys->env);
	mi_sys->env = ienv;
}

void	s_env_create_update_value(char *keys_values, t_sys *mi_sys)
{
	int			pos;
	char		*msg;

	if (!keys_values || keys_values[0] == '=')
	{
		msg = join_3("export: `", keys_values, "' not a valid identifier");
		mi_logerror(1, msg, mi_sys);
		free(msg);
		mi_sys->exit_status = EXIT_FAILURE;
		return ;
	}
	pos = ft_get_confpos(keys_values, mi_sys);
	if (pos == -1)
		s_env_create_value (keys_values, mi_sys);
	else
	{
		free(mi_sys->env[pos]);
		mi_sys->env[pos] = ft_strdup(keys_values);
	}
	mi_sys->exit_status = EXIT_SUCCESS;
}

void	s_env_create_update_key_value(char *key, char *value, t_sys *mi_sys)
{
	char			*str_pwd;

	str_pwd = join_3(key, "=", value);
	s_env_create_update_value (str_pwd, mi_sys);
}

int	mi_export_values(char **keys_values, t_sys *mi_sys)
{
	int			i;

	i = 1;
	while (keys_values[i] != NULL)
		s_env_create_update_value(keys_values[i++], mi_sys);
	return (mi_sys->exit_status);
}
