/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 03:05:30 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:01:51 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Retourne la valeur absolue d'un entier
 * @param n L'entier
 * @return int La valeur absolue
 */
int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

/**
 * @brief Retourne la valeur absolue d'un long long
 * @param n Le long long
 * @return long long La valeur absolue
 */
long long	ft_abs_ll(long long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	safe_abs(t_libft *libft, int n)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0);
	}
	return (ft_abs(n));
}

long long	safe_abs_ll(t_libft *libft, long long n)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0);
	}
	return (ft_abs_ll(n));
}
