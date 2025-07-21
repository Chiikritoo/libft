/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:30:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:01:05 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Calcule l'arc tangente d'un nombre
 * @param x Le nombre (domaine : ]-∞, +∞[)
 * @return double L'angle en radians dans ]-π/2, π/2[
 */
double	ft_atan(double x)
{
	double	result;
	double	term;
	int		i;
	int		sign;

	if (x == 0.0)
		return (0.0);
	if (x == 1.0)
		return (M_PI / 4.0);
	if (x == -1.0)
		return (-M_PI / 4.0);
	if (x < 0.0)
		return (-ft_atan(-x));
	if (x > 1.0)
		return (M_PI / 2.0 - ft_atan(1.0 / x));
	result = 0.0;
	sign = 1;
	i = 0;
	while (i < 20)
	{
		term = sign * ft_pow(x, 2 * i + 1) / (2 * i + 1);
		result += term;
		sign = -sign;
		i++;
	}
	return (result);
}

/**
 * @brief Calcule l'arc tangente d'un nombre (version float)
 * @param x Le nombre (domaine : ]-∞, +∞[)
 * @return float L'angle en radians dans ]-π/2, π/2[
 */
float	ft_atanf(float x)
{
	float	result;
	float	term;
	int		i;
	int		sign;

	if (x == 0.0f)
		return (0.0f);
	if (x == 1.0f)
		return (M_PI / 4.0f);
	if (x == -1.0f)
		return (-M_PI / 4.0f);
	if (x < 0.0f)
		return (-ft_atanf(-x));
	if (x > 1.0f)
		return (M_PI / 2.0f - ft_atanf(1.0f / x));
	result = 0.0f;
	sign = 1;
	i = 0;
	while (i < 20)
	{
		term = sign * ft_powf(x, 2 * i + 1) / (2 * i + 1);
		result += term;
		sign = -sign;
		i++;
	}
	return (result);
}

/**
 * @brief Calcule l'arc tangente de y/x avec gestion des quadrants
 * @param y Coordonnée y
 * @param x Coordonnée x
 * @return double L'angle en radians dans [-π, π]
 */
double	ft_atan2(double y, double x)
{
	if (x == 0.0 && y == 0.0)
		return (0.0);
	if (x == 0.0)
	{
		if (y > 0.0)
			return (M_PI / 2.0);
		else
			return (-M_PI / 2.0);
	}
	if (x > 0.0)
		return (ft_atan(y / x));
	if (x < 0.0)
	{
		if (y >= 0.0)
			return (ft_atan(y / x) + M_PI);
		else
			return (ft_atan(y / x) - M_PI);
	}
	return (0.0);
}

/**
 * @brief Calcule l'arc tangente de y/x avec gestion des quadrants (float)
 * @param y Coordonnée y
 * @param x Coordonnée x
 * @return float L'angle en radians dans [-π, π]
 */
float	ft_atan2f(float y, float x)
{
	if (x == 0.0f && y == 0.0f)
		return (0.0f);
	if (x == 0.0f)
	{
		if (y > 0.0f)
			return (M_PI / 2.0f);
		else
			return (-M_PI / 2.0f);
	}
	if (x > 0.0f)
		return (ft_atanf(y / x));
	if (x < 0.0f)
	{
		if (y >= 0.0f)
			return (ft_atanf(y / x) + M_PI);
		else
			return (ft_atanf(y / x) - M_PI);
	}
	return (0.0f);
}

/**
 * @brief Version sécurisée de ft_atan avec gestion d'erreurs
 * @param libft Le contexte libft
 * @param x Le nombre
 * @return double L'angle en radians
 */
double	safe_atan(t_libft *libft, double x)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0.0);
	}
	return (ft_atan(x));
}

/**
 * @brief Version sécurisée de ft_atanf avec gestion d'erreurs
 * @param libft Le contexte libft
 * @param x Le nombre
 * @return float L'angle en radians
 */
float	safe_atanf(t_libft *libft, float x)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0.0f);
	}
	return (ft_atanf(x));
}

/**
 * @brief Version sécurisée de ft_atan2 avec gestion d'erreurs
 * @param libft Le contexte libft
 * @param y Coordonnée y
 * @param x Coordonnée x
 * @return double L'angle en radians
 */
double	safe_atan2(t_libft *libft, double y, double x)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0.0);
	}
	return (ft_atan2(y, x));
}

/**
 * @brief Version sécurisée de ft_atan2f avec gestion d'erreurs
 * @param libft Le contexte libft
 * @param y Coordonnée y
 * @param x Coordonnée x
 * @return float L'angle en radians
 */
float	safe_atan2f(t_libft *libft, float y, float x)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0.0f);
	}
	return (ft_atan2f(y, x));
}
