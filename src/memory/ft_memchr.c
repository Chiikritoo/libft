/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:03:04 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/29 17:25:53 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

//	function who scans the initial n bytes of the memory area pointed to by s
//	for the first instance of c
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if (str[i] == c)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}
