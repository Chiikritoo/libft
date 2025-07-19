/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:08:30 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/19 22:29:30 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who calculates the length of the string 's'
ssize_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

ssize_t	safe_strlen(t_libft *libft, const char *s)
{
	ssize_t	result;

	if (!libft)
		return (-1);
	result = ft_strlen(s);
	if (result == -1)
	{
		SET_ERROR(libft->error_ctx, ERROR_LOGIC, EINVAL,
			"string is null");
		PRINT_ERROR(libft->error_ctx);
	}
	return (result);
}
