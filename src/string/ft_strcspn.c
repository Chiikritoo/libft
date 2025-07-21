/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:55:00 by anchikri          #+#    #+#             */
/*   Updated: 2024/07/21 22:55:00 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t ft_strcspn(const char *s, const char *reject)
{
	size_t i = 0;

	if (!s || !reject)
		return 0;
	while (s[i] && !ft_strchr(reject, s[i]))
		i++;
	return (i);
}

size_t safe_strcspn(t_libft *libft, const char *s, const char *reject)
{
	size_t		result;
	t_error_ctx *error_ctx;
	if (!libft)
	{
		error_ctx = error_ctx_init();
		SET_ERROR(error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"safe_strcspn: invalid input");
		PRINT_ERROR(error_ctx);
		error_ctx_destroy(error_ctx);
		return (0);
	}
	if (!s || !reject)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"safe_strcspn: invalid input");
		PRINT_ERROR(libft->error_ctx);
		return (0);
	}
	result = ft_strcspn(s, reject);
	return (result);
} 
