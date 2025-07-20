/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:28:38 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 02:28:33 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who compares the first n bytes of the memory areas s1 and s2
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}

int	safe_memcmp(t_libft *libft, const void *s1, const void *s2, size_t n)
{
	int	result;

	if (!libft)
		return (0);
	if (!s1 || !s2)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"s1 or s2 is null");
		PRINT_ERROR(libft->error_ctx);
		return (0);
	}
	result = ft_memcmp(s1, s2, n);
	return (result);
}
