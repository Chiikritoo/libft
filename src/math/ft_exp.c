/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 00:00:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 22:59:01 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static double	ft_exp_taylor(double r)
{
	double	sum;
	double	term;
	int		n;

	sum = 1.0;
	term = 1.0;
	n = 1;
	while (n <= 20)
	{
		term = term * r / n;
		sum = sum + term;
		n++;
	}
	return (sum);
}

static float	ft_expf_taylor(float r)
{
	float	sum;
	float	term;
	int		n;

	sum = 1.0f;
	term = 1.0f;
	n = 1;
	while (n <= 12)
	{
		term = term * r / n;
		sum = sum + term;
		n++;
	}
	return (sum);
}

static double	ft_exp2_int(int k)
{
	double	res;
	int		i;

	res = 1.0;
	if (k > 0)
	{
		i = 0;
		while (i < k)
		{
			res = res * 2.0;
			i++;
		}
	}
	else if (k < 0)
	{
		i = 0;
		while (i > k)
		{
			res = res * 0.5;
			i--;
		}
	}
	return (res);
}

static float	ft_exp2f_int(int k)
{
	float	res;
	int		i;

	res = 1.0f;
	if (k > 0)
	{
		i = 0;
		while (i < k)
		{
			res = res * 2.0f;
			i++;
		}
	}
	else if (k < 0)
	{
		i = 0;
		while (i > k)
		{
			res = res * 0.5f;
			i--;
		}
	}
	return (res);
}

/**
 * @brief Calcule l'exponentielle exp(x) (100% maison,
	aucune dépendance externe)
 * @param x L'exposant
 * @return double exp(x)
 */
double	ft_exp(double x)
{
	int		k;
	double	r;
	double	res;

	if (x != x)
		return (x);
	if (x > 709.0)
		return (1.0 / 0.0);
	if (x < -745.0)
		return (0.0);
	k = (int)(x / LN2);
	r = x - k * LN2;
	res = ft_exp2_int(k) * ft_exp_taylor(r);
	return (res);
}

/**
 * @brief Calcule l'exponentielle expf(x) (100% maison,
	aucune dépendance externe, version float)
 * @param x L'exposant
 * @return float expf(x)
 */
float	ft_expf(float x)
{
	int		k;
	float	r;
	float	res;

	if (x != x)
		return (x);
	if (x > 88.0f)
		return (1.0f / 0.0f);
	if (x < -103.0f)
		return (0.0f);
	k = (int)(x / LN2F);
	r = x - k * LN2F;
	res = ft_exp2f_int(k) * ft_expf_taylor(r);
	return (res);
}

/**
 * @brief Version sécurisée de ft_exp avec gestion d'erreur
 * @param libft Le contexte libft
 * @param x L'exposant
 * @return double exp(x), ou 0.0 si libft NULL
 */
double	safe_exp(t_libft *libft, double x)
{
	t_error_ctx	*error_ctx;

	if (!libft)
	{
		error_ctx = error_ctx_init();
		SET_ERROR(error_ctx, ERROR_INVALID_PARAM, EINVAL, "libft is NULL");
		PRINT_ERROR(error_ctx);
		error_ctx_destroy(error_ctx);
		return (0.0);
	}
	return (ft_exp(x));
}

/**
 * @brief Version sécurisée de ft_expf avec gestion d'erreur
 * @param libft Le contexte libft
 * @param x L'exposant
 * @return float expf(x), ou 0.0f si libft NULL
 */
float	safe_expf(t_libft *libft, float x)
{
	t_error_ctx	*error_ctx;

	if (!libft)
	{
		error_ctx = error_ctx_init();
		SET_ERROR(error_ctx, ERROR_INVALID_PARAM, EINVAL, "libft is NULL");
		PRINT_ERROR(error_ctx);
		error_ctx_destroy(error_ctx);
		return (0.0f);
	}
	return (ft_expf(x));
}
