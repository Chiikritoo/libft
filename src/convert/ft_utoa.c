/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:28:32 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/19 22:24:26 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who calculates the length of an unsigned integer
int	len_uint(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

// function who converts an unsigned integer to a string
char	*ft_utoa(unsigned int n)
{
	int		len;
	char	*tab;

	len = len_uint(n);
	tab = ft_calloc(len + 1, sizeof(char));
	if (!tab)
		return (NULL);
	while (len > 0)
	{
		len--;
		tab[len] = (n % 10) + 48;
		n /= 10;
	}
	return (tab);
}

char	*safe_utoa(t_libft *libft, unsigned int n)
{
	char	*result;

	if (!libft)
		return (NULL);
	result = ft_utoa(n);
	if (!result)
	{
		SET_ERROR(libft->error_ctx, ERROR_MEMORY, ENOMEM,
			"ft_utoa() failed for unsigned integer '%u'", n);
		PRINT_ERROR(libft->error_ctx);
	}
	return (result);
}
