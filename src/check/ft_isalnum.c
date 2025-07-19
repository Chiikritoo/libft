/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:30:53 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/19 22:17:12 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who checks for an alphanumeric character
int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	return (0);
}

// safe version with error handling
int	safe_isalnum(t_libft *libft, int c)
{
	int	result;

	if (!libft)
		return (0);
	result = ft_isalnum(c);
	if (result == 0)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"Character '%c' is not alphanumeric", c);
		PRINT_ERROR(libft->error_ctx);
	}
	return (result);
}
