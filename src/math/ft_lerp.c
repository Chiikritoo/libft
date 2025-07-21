/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lerp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:45:03 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:02:33 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Interpolation linéaire pure entre a et b selon t (extrapolation autorisée)
 * @param a Valeur de départ
 * @param b Valeur d'arrivée
 * @param t Facteur d'interpolation
 * @return double Valeur interpolée (NaN si a, b ou t est NaN/inf)
 */
double	ft_lerp(double a, double b, double t)
{
	if (isnan(a) || isnan(b) || isnan(t))
		return (NAN);
	if (isinf(a) || isinf(b) || isinf(t))
		return (NAN);
	return (a + (b - a) * t);
}

/**

 * @brief Interpolation linéaire clampée entre a et b selon t (t clampé dans [0,1])
 * @param a Valeur de départ
 * @param b Valeur d'arrivée
 * @param t Facteur d'interpolation
 * @return double Valeur interpolée (NaN si a, b ou t est NaN/inf)
 */
double	ft_clerp(double a, double b, double t)
{
	if (isnan(a) || isnan(b) || isnan(t))
		return (NAN);
	if (isinf(a) || isinf(b) || isinf(t))
		return (NAN);
	t = ft_clamp(t, 0.0, 1.0);
	return (a + (b - a) * t);
}

double	safe_lerp(t_libft *libft, double a, double b, double t)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0.0);
	}
	return (ft_lerp(a, b, t));
}

double	safe_clerp(t_libft *libft, double a, double b, double t)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0.0);
	}
	return (ft_clerp(a, b, t));
}
