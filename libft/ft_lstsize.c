/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:41:04 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Function :
				ft_lstsize
Prototype :
				int ft_lstsize(t_list *lst);
Paramètres :
				lst: Le début de la liste.
Retour :
				Taille de la liste
Description :
				Compte le nombre d’éléments de la liste.
 */

int	ft_lstsize(t_list *lst)
{
	int		list_size;
	t_list	*element;

	list_size = 0;
	if (lst == NULL)
		return (0);
	element = lst;
	while (element != NULL)
	{
		element = element->next;
		list_size++;
	}
	return (list_size);
}
