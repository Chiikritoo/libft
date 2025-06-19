/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:10:37 by anchikri          #+#    #+#             */
/*   Updated: 2025/06/19 11:29:52 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who hashes the pointer with the capacity
unsigned int	gc_hash(void *ptr, size_t capacity)
{
	unsigned long	addr;

	if (!ptr)
		return (0);
	addr = (unsigned long)ptr;
	addr ^= (addr >> 16);
	return (addr % capacity);
}
