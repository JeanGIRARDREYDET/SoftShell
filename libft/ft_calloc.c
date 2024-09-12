/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:26:05 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/07 09:26:09 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Description :
			La fonction calloc() alloue de la mémoire pour un tableau de nmemb
			éléments de taille taille octets chacun et renvoie un pointeur sur
			la mémoire allouée. La zone mémoire est initialisée à 0.
			Si nmemb ou taille vaut 0, calloc() renvoie alors une valeur de
			pointeur unique qui pourra être passée ultérieurement à free() avec
			succès.

			Si la multiplication de nmemb par taille provoque un dépassement
			d'entier, calloc() renvoie une erreur. Par contre, aucun dépassement
			d'entier ne serait détecté lors de l'appel suivant à malloc(), avec
			pour conséquence l'allocation d'un bloc de mémoire incorrectement
			dimensionné : malloc(nmemb * taille);
Prototype :
			void	*ft_calloc(size_t nmemb, size_t size)

Paramètres :
			size_t nmemb :
			size_t size :

Retour :
			renvoient un pointeur vers la mémoire allouée qui est correctement
			alignée pour n'importe quel type dont la taille correspondra à la
			taille demandée ou sera inférieure à cette dernière. Si elles 
			échouent, elles renvoient NULL et définissent errno pour indiquer
			l'erreur. Essayer d'allouer plus que PTRDIFF_MAX octets est 
			considéré comme une erreur, car un objet de cette taille pourrait
			provoquer un dépassement lors d'une soustraction de pointeur
			ultérieure.

Autorisées :
			malloc(nmemb * size);
*/

#include "../minishell.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	char	*p2;
	size_t	malloc_size;

	malloc_size = nmemb * size;
	if (size != 0)
		if (malloc_size / size != nmemb)
			return (NULL);
	p = (void *)malloc(malloc_size);
	if (! (p))
		return (NULL);
	p2 = (char *)p;
	while (0 < malloc_size--)
		p2[malloc_size] = 0 ;
	return (p);
}
