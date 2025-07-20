/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_acos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:30:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 15:26:16 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Calcule l'arc cosinus d'un nombre
 * @param x Le nombre (doit être dans [-1, 1])
 * @return double L'angle en radians dans [0, π]
 * @note Retourne NaN si x est hors du domaine
 */
double	ft_acos(double x)
{
	double	result;
	double	term;
	int		i;

	if (x < -1.0 || x > 1.0)
		return (0.0 / 0.0);
	if (x == 0.0)
		return (M_PI / 2.0);
	if (x == 1.0)
		return (0.0);
	if (x == -1.0)
		return (M_PI);
	if (x < 0.0)
		return (M_PI - ft_acos(-x));
	if (x > 0.5)
		return (M_PI / 2.0 - ft_asin(x));
	result = M_PI / 2.0;
	i = 0;
	while (i < 15)
	{
		term = ft_dfactorial(2 * i) * ft_pow(x, 2 * i + 1);
		term /= ft_pow(4, i) * ft_dfactorial(i) * ft_dfactorial(i) * (2 * i + 1);
		result -= term;
		i++;
	}
	return (result);
}

/**
 * @brief Calcule l'arc cosinus d'un nombre (version float)
 * @param x Le nombre (doit être dans [-1, 1])
 * @return float L'angle en radians dans [0, π]
 * @note Retourne NaN si x est hors du domaine
 */
float	ft_acosf(float x)
{
	float	result;
	float	term;
	int		i;

	if (x < -1.0f || x > 1.0f)
		return (0.0f / 0.0f);
	if (x == 0.0f)
		return (M_PI / 2.0f);
	if (x == 1.0f)
		return (0.0f);
	if (x == -1.0f)
		return (M_PI);
	if (x < 0.0f)
		return (M_PI - ft_acosf(-x));
	if (x > 0.5f)
		return (M_PI / 2.0f - ft_asinf(x));
	result = M_PI / 2.0f;
	i = 0;
	while (i < 15)
	{
		term = ft_dfactorial(2 * i) * ft_powf(x, 2 * i + 1);
		term /= ft_powf(4, i) * ft_dfactorial(i) * ft_dfactorial(i) * (2 * i + 1);
		result -= term;
		i++;
	}
	return (result);
}

/**
 * @brief Version sécurisée de ft_acos avec gestion d'erreurs
 * @param libft Le contexte libft
 * @param x Le nombre
 * @return double L'angle en radians
 */
double	safe_acos(t_libft *libft, double x)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0.0);
	}
	if (x < -1.0 || x > 1.0)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EDOM,
			"acos: domain error, x must be in [-1, 1]");
		return (0.0 / 0.0);
	}
	return (ft_acos(x));
}

/**
 * @brief Version sécurisée de ft_acosf avec gestion d'erreurs
 * @param libft Le contexte libft
 * @param x Le nombre
 * @return float L'angle en radians
 */
float	safe_acosf(t_libft *libft, float x)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0.0f);
	}
	if (x < -1.0f || x > 1.0f)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EDOM,
			"acosf: domain error, x must be in [-1, 1]");
		return (0.0f / 0.0f);
	}
	return (ft_acosf(x));
} 
