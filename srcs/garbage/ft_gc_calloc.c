/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_calloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:31:56 by anchikri          #+#    #+#             */
/*   Updated: 2024/06/12 22:23:08 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/libft.h"

void	*ft_gc_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(nmemb, size);
	if (!ptr)
		return (NULL);
	return (ptr);
}
