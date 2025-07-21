/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 22:58:34 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 22:58:35 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Reste de la division flottante (modulo réel, comme fmod de la libc)
 * @param x Le numérateur
 * @param y Le dénominateur
 * @return Le reste x - n*y où n est l'entier le plus proche de x/y vers zéro
 */
double	ft_mod(double x, double y)
{
	if (isnan(x) || isnan(y) || y == 0.0)
		return (NAN);
	if (isinf(x) && isfinite(y))
		return (NAN);
	if (isfinite(x) && isinf(y))
		return (x);
	return (x - y * (double)((long long)(x / y)));
}

/**
 * @brief Sépare la partie entière et la partie fractionnaire d'un flottant
 * @param x Le nombre à séparer
 * @param iptr Pointeur vers la partie entière (écrite dedans)
 * @return La partie fractionnaire (x - *iptr)
 */
double	ft_modf(double x, double *iptr)
{
	if (isnan(x))
	{
		*iptr = NAN;
		return (NAN);
	}
	if (isinf(x))
	{
		*iptr = x;
		return (copysign(0.0, x));
	}
	*iptr = (double)(long long)x;
	return (x - *iptr);
}

double	safe_mod(t_libft *libft, double x, double y)
{
	t_libft	*safe_libft;

	if (!libft)
	{
		safe_libft = safe_libft_init();
		SET_ERROR(safe_libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		PRINT_ERROR(safe_libft->error_ctx);
		libft_destroy(safe_libft);
		return (0.0);
	}
	return (ft_mod(x, y));
}

double	safe_modf(t_libft *libft, double x, double *iptr)
{
	t_libft	*safe_libft;

	if (!libft)
	{
		safe_libft = safe_libft_init();
		SET_ERROR(safe_libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		PRINT_ERROR(safe_libft->error_ctx);
		libft_destroy(safe_libft);
		if (iptr)
			*iptr = 0.0;
		return (0.0);
	}
	return (ft_modf(x, iptr));
}
