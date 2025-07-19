/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:30:53 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/19 22:17:53 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who checks for a whitespace character
int	ft_isspace(int c)
{
	if (c == 32 || c == 9 || c == 10 || c == 11 || c == 12 || c == 13)
		return (1);
	return (0);
}

// safe version with error handling
int	safe_isspace(t_libft *libft, int c)
{
	int	result;

	if (!libft)
		return (0);
	result = ft_isspace(c);
	if (result == 0)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"character '%c' is not a whitespace", c);
		PRINT_ERROR(libft->error_ctx);
	}
	return (result);
}
