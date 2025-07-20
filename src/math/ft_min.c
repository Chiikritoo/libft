/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 03:05:15 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 03:07:54 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Retourne le minimum entre deux entiers
 * @param a Premier entier
 * @param b Deuxième entier
 * @return int Le plus petit des deux entiers
 */
int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

/**
 * @brief Retourne le minimum entre deux long long
 * @param a Premier long long
 * @param b Deuxième long long
 * @return long long Le plus petit des deux
 */
long long	ft_min_ll(long long a, long long b)
{
	if (a < b)
		return (a);
	return (b);
}

int	safe_min(t_libft *libft, int a, int b)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0);
	}
	return (ft_min(a, b));
}

long long	safe_min_ll(t_libft *libft, long long a, long long b)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0);
	}
	return (ft_min_ll(a, b));
}
