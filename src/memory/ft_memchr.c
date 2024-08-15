/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:03:04 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 15:30:35 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/memory.h"

//	function who scans the initial n bytes of the memory area pointed to by s
//	for the first instance of c
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*s1;

	i = 0;
	s1 = (const char *)s;
	while (i < n)
	{
		if (s1[i] == (char)c)
			return ((void *) &((const char *)s)[i]);
		i++;
	}
	return (NULL);
}
