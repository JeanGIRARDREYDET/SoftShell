/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
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
