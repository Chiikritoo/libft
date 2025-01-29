/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:50:44 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/29 17:25:53 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

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
