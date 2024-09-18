/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:08:13 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/28 13:08:18 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Function :
				ft_lstlast
Prototype :
				t_list *ft_lstlast(t_list *lst);
Paramètres :
				lst: Le début de la liste.
Retour :
				Dernier élément de la liste
Description :
				Dernier élément de la liste
 */

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*element;

	if (lst == NULL)
		return (NULL);
	element = lst;
	while (element->next != NULL)
		element = element->next;
	return (element);
}
