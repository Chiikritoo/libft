/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 03:06:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 18:03:41 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Calcule la racine carrée d'un entier
 * @param n L'entier (doit être positif)
 * @return int La racine carrée entière
 * @note Retourne -1 si n est négatif
 */
int	ft_sqrt(int n)
{
	int	i;

	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);
	i = 1;
	while (i <= n / 2)
	{
		if (i * i == n)
			return (i);
		if (i * i > n)
			return (i - 1);
		i++;
	}
	return (n / 2);
}

/**
 * @brief Calcule la racine carrée avec précision
 * @param n Le nombre (doit être positif)
 * @param precision La précision (nombre de décimales)
 * @return double La racine carrée avec précision
 * @note Retourne -1.0 si n est négatif
 */
double	ft_psqrt(double n, int precision)
{
	double	x;
	double	guess;

	if (n < 0)
		return (-1.0);
	if (n == 0)
		return (0.0);
	guess = n / 2.0;
	while (precision > 0)
	{
		if (guess == 0)
			break ;
		x = guess;
		guess = (x + n / x) / 2.0;
		precision--;
	}
	return (guess);
}

int	safe_sqrt(t_libft *libft, int n)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0);
	}
	return (ft_sqrt(n));
}

double	safe_sqrt_precise(t_libft *libft, double n, int precision)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0);
	}
	return (ft_psqrt(n, precision));
}
