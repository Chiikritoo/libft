/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lcm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 13:47:21 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 13:58:29 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Calcule le PPCM (Plus Petit Multiple Commun)
 * @param a Premier entier
 * @param b Deuxième entier
 * @return long long Le PPCM
 * @note Retourne -1 en cas d'overflow
 */
long long	ft_lcm(int a, int b)
{
	long long	pgcd;
	long long	result;

	if (a == 0 || b == 0)
		return (0);
	pgcd = ft_pgcd(a, b);
	result = ((long long)ft_abs(a) * (long long)ft_abs(b)) / pgcd;
	if (result < 0)
		return (-1);
	return (result);
}

long long	safe_lcm(t_libft *libft, int a, int b)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0);
	}
	return (ft_lcm(a, b));
}
