/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:03:04 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 02:28:20 by anchikri         ###   ########.fr       */
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

void	*safe_memchr(t_libft *libft, const void *s, int c, size_t n)
{
	void	*result;

	if (!libft)
		return (NULL);
	if (!s)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"memory area is null");
		PRINT_ERROR(libft->error_ctx);
		return (NULL);
	}
	result = ft_memchr(s, c, n);
	if (!result)
	{
		SET_ERROR(libft->error_ctx, ERROR_LOGIC, EINVAL,
			"character '%c' not found in memory area", c);
		PRINT_ERROR(libft->error_ctx);
	}
	return (result);
}
