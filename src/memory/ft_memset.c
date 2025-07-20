/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:14:04 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 02:28:01 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

//	function fills the first n bytes of the memory area pointed by s 
//	with the constant byte c
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *) s)[i++] = c;
	return (s);
}

void	*safe_memset(t_libft *libft, void *s, int c, size_t n)
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
	result = ft_memset(s, c, n);
	return (result);
}
