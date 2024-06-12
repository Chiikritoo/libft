/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:00:11 by anchikri          #+#    #+#             */
/*   Updated: 2024/06/12 22:23:08 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/libft.h"

//	function who allocates memory for an array of nmemb elements of size bytes
//	and returns a pointer to the allocated memory. The memory is set to zero
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	size_t	len;

	if (!nmemb || !size)
		return (malloc(0));
	len = nmemb * size;
	if (len / size != nmemb)
		return (NULL);
	tab = malloc(len);
	if (!tab)
		return (NULL);
	ft_memset(tab, 0, len);
	return (tab);
}
