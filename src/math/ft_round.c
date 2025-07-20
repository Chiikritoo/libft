/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:00:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 16:48:47 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Arrondit un nombre double au plus proche entier
 * @param x Le nombre à arrondir
 * @return double L'entier le plus proche
 * @note Si la partie décimale est >= 0.5, arrondit vers le haut
 *       Si la partie décimale est < 0.5, arrondit vers le bas
 */
double	ft_round(double x)
{
	double	integer_part;
	double	fractional_part;

	if (x == 0.0)
		return (0.0);
	if (x < 0.0)
		return (-ft_round(-x));
	integer_part = (double)(long long)x;
	fractional_part = x - integer_part;
	if (fractional_part >= 0.5)
		return (integer_part + 1.0);
	return (integer_part);
}

/**
 * @brief Arrondit un nombre float au plus proche entier
 * @param x Le nombre à arrondir
 * @return float L'entier le plus proche
 * @note Si la partie décimale est >= 0.5, arrondit vers le haut
 *       Si la partie décimale est < 0.5, arrondit vers le bas
 */
float	ft_roundf(float x)
{
	float	integer_part;
	float	fractional_part;

	if (x == 0.0f)
		return (0.0f);
	if (x < 0.0f)
		return (-ft_roundf(-x));
	integer_part = (float)(long long)x;
	fractional_part = x - integer_part;
	if (fractional_part >= 0.5f)
		return (integer_part + 1.0f);
	return (integer_part);
}

/**
 * @brief Arrondit un nombre double au plus proche entier de façon sécurisée
 * @param libft Pointeur vers la structure libft (pour la gestion d'erreur)
 * @param x Le nombre à arrondir
 * @return double L'entier le plus proche, ou 0.0 si libft est NULL
 */
double	safe_round(t_libft *libft, double x)
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
	return (ft_round(x));
}

/**
 * @brief Arrondit un nombre float au plus proche entier de façon sécurisée
 * @param libft Pointeur vers la structure libft (pour la gestion d'erreur)
 * @param x Le nombre à arrondir
 * @return float L'entier le plus proche, ou 0.0f si libft est NULL
 */
float	safe_roundf(t_libft *libft, float x)
{
	t_libft	*safe_libft;

	if (!libft)
	{
		safe_libft = safe_libft_init();
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		PRINT_ERROR(safe_libft->error_ctx);
		libft_destroy(safe_libft);
		return (0.0f);
	}
	return (ft_roundf(x));
}
