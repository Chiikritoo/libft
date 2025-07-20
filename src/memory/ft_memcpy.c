/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:32:39 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 02:27:40 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

//	function who copies n bytes from memory area src to memory area dest
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

void	*safe_memcpy(t_libft *libft, void *dest, const void *src, size_t n)
{
	void	*result;

	if (!libft)
		return (NULL);
	if (!dest || !src)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"dest or src is null");
		PRINT_ERROR(libft->error_ctx);
		return (NULL);
	}
	result = ft_memcpy(dest, src, n);
	return (result);
}
