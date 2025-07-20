/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:41:37 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 02:12:23 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who compares the first 'n' characters of the strings 's1' and 's2'
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	safe_strncmp(t_libft *libft, const char *s1, const char *s2, size_t n)
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
	result = ft_strncmp(s1, s2, n);
	return (result);
}
