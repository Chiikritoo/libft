/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:50:44 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/29 13:16:50 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who duplicates the memory of 'src' with the size 'size'
void	*ft_memdup(const void *src, size_t size)
{
	void	*dst;

	dst = ft_calloc(size, sizeof(char));
	if (!dst)
		return (NULL);
	ft_memcpy(dst, src, size);
	return (dst);
}
