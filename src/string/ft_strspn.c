/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:45:00 by anchikri          #+#    #+#             */
/*   Updated: 2024/07/21 22:45:00 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;

	i = 0;
	if (!s || !accept)
		return (0);
	while (s[i] && ft_strchr(accept, s[i]))
		i++;
	return (i);
}

size_t	safe_strspn(t_libft *libft, const char *s, const char *accept)
{
	size_t		result;
	t_error_ctx	*error_ctx;

	if (!libft)
	{
		error_ctx = error_ctx_init();
		SET_ERROR(error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"safe_strspn: invalid input");
		PRINT_ERROR(error_ctx);
		return (0);
	}
	if (!s || !accept)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"safe_strspn: invalid input");
		PRINT_ERROR(libft->error_ctx);
		return (0);
	}
	result = ft_strspn(s, accept);
	return (result);
}
