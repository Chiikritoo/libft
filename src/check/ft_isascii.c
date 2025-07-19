/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:30:53 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/19 22:18:10 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who checks for an ASCII character
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// safe version with error handling
int	safe_isascii(t_libft *libft, int c)
{
	int	result;

	if (!libft)
		return (0);
	result = ft_isascii(c);
	if (result == 0)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"character '%c' is not ASCII", c);
		PRINT_ERROR(libft->error_ctx);
	}
	return (result);
}
