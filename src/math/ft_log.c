/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 00:00:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 22:57:43 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static double	taylor_log1p(double t)
{
	double	res;
	double	term;
	int		n;

	res = 0.0;
	term = t;
	n = 1;
	while (n <= 20)
	{
		if (n % 2)
			res += term / n;
		else
			res -= term / n;
		term *= t;
		n++;
	}
	return (res);
}

static float	taylor_log1pf(float t)
{
	float	res;
	float	term;
	int		n;

	res = 0.0f;
	term = t;
	n = 1;
	while (n <= 12)
	{
		if (n % 2)
			res += term / n;
		else
			res -= term / n;
		term *= t;
		n++;
	}
	return (res);
}

// Décomposition binaire maison (IEEE 754 double)
static void	ft_decompose_double(double x, double *mant, int *expo)
{
	unsigned long long	bits;
	int					exp_raw;

	bits = *(unsigned long long *)&x;
	exp_raw = (int)((bits >> 52) & 0x7FF);
	if (exp_raw == 0)
	{
		*expo = -1022;
		*mant = (double)(bits & 0xFFFFFFFFFFFFFull) / (1ULL << 52);
	}
	else
	{
		*expo = exp_raw - 1023;
		*mant = 1.0 + (double)(bits & 0xFFFFFFFFFFFFFull) / (1ULL << 52);
	}
}

// Décomposition binaire maison (IEEE 754 float)
static void	ft_decompose_float(float x, float *mant, int *expo)
{
	unsigned int	bits;
	int				exp_raw;

	bits = *(unsigned int *)&x;
	exp_raw = (int)((bits >> 23) & 0xFF);
	if (exp_raw == 0)
	{
		*expo = -126;
		*mant = (float)(bits & 0x7FFFFF) / (1U << 23);
	}
	else
	{
		*expo = exp_raw - 127;
		*mant = 1.0f + (float)(bits & 0x7FFFFF) / (1U << 23);
	}
}

/**
 * @brief Calcule le logarithme népérien (ln) d'un nombre positif (100% maison,
	aucune dépendance externe)
 * @param x Le nombre (doit être strictement positif)
 * @return double Le logarithme naturel de x, ou (NAN) si x <= 0
 */
double	ft_log(double x)
{
	double	m;
	int		k;
	double	t;
	double	ln_m;

	if (x != x)
		return (x);
	if (x == 0.0)
		return (-1.0 / 0.0);
	if (x < 0.0)
		return (0.0 / 0.0);
	if (x + 1.0 == x)
		return (1.0 / 0.0);
	ft_decompose_double(x, &m, &k);
	if (m < 0.7071067811865476)
	{
		m = m * 2.0;
		k = k - 1;
	}
	t = m - 1.0;
	ln_m = taylor_log1p(t);
	return (k * LN2 + ln_m);
}

/**
 * @brief Calcule le logarithme népérien (ln) d'un nombre positif (100% maison,
	aucune dépendance externe, version float)
 * @param x Le nombre (doit être strictement positif)
 * @return float Le logarithme naturel de x, ou (NAN) si x <= 0
 */
float	ft_logf(float x)
{
	float	m;
	int		k;
	float	t;
	float	ln_m;

	if (x != x)
		return (x);
	if (x == 0.0f)
		return (-1.0f / 0.0f);
	if (x < 0.0f)
		return (0.0f / 0.0f);
	if (x + 1.0f == x)
		return (1.0f / 0.0f);
	ft_decompose_float(x, &m, &k);
	if (m < 0.70710678f)
	{
		m = m * 2.0f;
		k = k - 1;
	}
	t = m - 1.0f;
	ln_m = taylor_log1pf(t);
	return (k * LN2F + ln_m);
}

/**
 * @brief Version sécurisée de ft_log avec gestion d'erreur
 * @param libft Le contexte libft
 * @param x Le nombre
 * @return double Le logarithme naturel de x, ou (NAN) si x <= 0 ou libft NULL
 */
double	safe_log(t_libft *libft, double x)
{
	t_error_ctx	*error_ctx;

	if (!libft)
	{
		error_ctx = error_ctx_init();
		SET_ERROR(error_ctx, ERROR_INVALID_PARAM, EINVAL, "libft is NULL");
		PRINT_ERROR(error_ctx);
		error_ctx_destroy(error_ctx);
		return (0.0 / 0.0);
	}
	if (x < 0.0)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EDOM,
			"log: domain error, x must be > 0");
		return (0.0 / 0.0);
	}
	if (x == 0.0)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EDOM,
			"log: domain error, x == 0");
		return (-1.0 / 0.0);
	}
	return (ft_log(x));
}

/**
 * @brief Version sécurisée de ft_logf avec gestion d'erreur
 * @param libft Le contexte libft
 * @param x Le nombre
 * @return float Le logarithme naturel de x, ou (NAN) si x <= 0 ou libft NULL
 */
float	safe_logf(t_libft *libft, float x)
{
	t_error_ctx	*error_ctx;

	if (!libft)
	{
		error_ctx = error_ctx_init();
		SET_ERROR(error_ctx, ERROR_INVALID_PARAM, EINVAL, "libft is NULL");
		PRINT_ERROR(error_ctx);
		error_ctx_destroy(error_ctx);
		return (0.0f / 0.0f);
	}
	if (x < 0.0f)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EDOM,
			"logf: domain error, x must be > 0");
		return (0.0f / 0.0f);
	}
	if (x == 0.0f)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EDOM,
			"logf: domain error, x == 0");
		return (-1.0f / 0.0f);
	}
	return (ft_logf(x));
}
