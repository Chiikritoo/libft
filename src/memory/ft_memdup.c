/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:50:44 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/16 02:07:55 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/memory.h"

// function who duplicates the memory of 'src' with the size 'size'
void	*ft_memdup(void const *src, size_t size)
{
	void	*dst;

	dst = ft_calloc(size, sizeof(char));
	if (!dst)
		return (NULL);
	ft_memcpy(dst, src, size);
	return (dst);
}
