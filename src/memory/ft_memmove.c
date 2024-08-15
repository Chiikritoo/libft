/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:45:38 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 15:30:35 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/memory.h"

//	function who copies n bytes from memory area src to memory area dest
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp;

	temp = ((unsigned char *)src);
	if (dest > src)
		while (n--)
			((unsigned char *) dest)[n] = temp[n];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
