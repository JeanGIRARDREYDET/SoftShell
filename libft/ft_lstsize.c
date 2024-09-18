/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:07:41 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/28 13:07:45 by jegirard         ###   ########.fr       */
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
