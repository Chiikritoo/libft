/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:15:39 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/29 17:25:48 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

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
