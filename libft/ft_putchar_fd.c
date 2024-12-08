/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:41:04 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Description :
				Écrit le caractère ’c’ sur le descripteur de fichier donné.
Paramètres :
				c: Le caractère à écrire.
				fd: Le descripteur de fichier sur lequel écrire.
Retour :
				 Aucune
Autorisées :
				write
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
