/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:45:38 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 02:27:51 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

//	function who copies n bytes from memory area src to memory area dest
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp;

	temp = ((unsigned char *)src);
	if (dest > src)
		while (n--)
			((unsigned char *) dest)[n] = temp[n];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

void	*safe_memmove(t_libft *libft, void *dest, const void *src, size_t n)
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
	result = ft_memmove(dest, src, n);
	return (result);
}
