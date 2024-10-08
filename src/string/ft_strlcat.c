/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:15:39 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/16 02:14:55 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/string.h"

// function who concatenates the strings 'dst' and 'src'
// with the size 'size'
size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;

	if (!dst && !size)
		return (0);
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (len_dst >= size)
		return (size + len_src);
	if (len_src < size - len_dst)
		ft_strlcpy(dst + len_dst, src, len_src + 1);
	else
		ft_strlcpy(dst + len_dst, src, size - len_dst);
	return (len_dst + len_src);
}
