/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gcd_lcm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 03:06:30 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 03:09:37 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Calcule le PGCD (Plus Grand Diviseur Commun)
 * @param a Premier entier
 * @param b Deuxième entier
 * @return int Le PGCD
 */
int	ft_gcd(int a, int b)
{
	int	temp;

	a = ft_abs(a);
	b = ft_abs(b);
	
	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return (a);
}

/**
 * @brief Calcule le PPCM (Plus Petit Multiple Commun)
 * @param a Premier entier
 * @param b Deuxième entier
 * @return long long Le PPCM
 * @note Retourne -1 en cas d'overflow
 */
long long	ft_lcm(int a, int b)
{
	long long	gcd;
	long long	result;

	if (a == 0 || b == 0)
		return (0);
	
	gcd = ft_gcd(a, b);
	result = ((long long)ft_abs(a) * (long long)ft_abs(b)) / gcd;
	
	if (result < 0) // Overflow
		return (-1);
	return (result);
}

int	safe_gcd(t_libft *libft, int a, int b)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0);
	}
	return (ft_gcd(a, b));
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
