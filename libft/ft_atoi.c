/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:14:00 by jegirard          #+#    #+#             */
/*   Updated: 2024/02/08 16:14:44 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_atoi(const char *str)
{
	int	signe;
	int	valeur;

	signe = 1;
	valeur = 0 ;
	while ((8 < *str && *str < 14) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe = -signe;
		str++;
	}
	while (('0' <= *str && *str <= '9'))
	{
		valeur = valeur * 10 + (*str - '0');
		str++;
	}
	if (!str)
		return (0);
	return (signe * valeur);
}
