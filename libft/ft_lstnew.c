/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
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
				Alloue (avec malloc(3)) et renvoie un nouvel élément.
				La variable membre ’content’ est initialisée à l’aide de la 
				valeur du paramètre ’content’.
				La variable ’next’ est initialisée à NULL.
Name :
				ft_lstnew
Prototype :
				t_list *ft_lstnew(void *content);
Paramètres :
				content: Le contenu du nouvel élément.
Retour :
				Le nouvel élément
Externes :
				malloc

*/

t_list	*ft_lstnew(void *content)
{
	t_list	*new_element;

	new_element = ft_calloc(1, sizeof (t_list));
	if (!new_element)
		return (NULL);
	new_element->content = content;
	new_element->next = NULL;
	return (new_element);
}
