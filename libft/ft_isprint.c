/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:25:38 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/07 09:25:45 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Description :	checks for any printable character including space.

Name :			

Prototype : 	

Paramètres :

Retour :		
*/

int	ft_isprint(int c)
{
	return (32 <= c && c <= 126);
}
