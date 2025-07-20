/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:53:20 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 02:36:18 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who compares the strings 's1' and 's2'
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	safe_strcmp(t_libft *libft, const char *s1, const char *s2)
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
	result = ft_strcmp(s1, s2);
	return (result);
}
