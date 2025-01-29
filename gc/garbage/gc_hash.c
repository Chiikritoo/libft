/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:10:37 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/29 17:25:42 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

unsigned int	gc_hash(void *ptr)
{
	unsigned long	addr;

	if (!ptr)
		return (0);
	addr = (unsigned long)ptr;
	addr ^= (addr >> 16);
	return (addr % HASH_SIZE);
}
