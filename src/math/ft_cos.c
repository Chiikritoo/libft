/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:23:19 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 16:32:41 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static double	reduce_angle(double x)
{
	while (x > 2.0 * M_PI)
		x -= 2.0 * M_PI;
	while (x < 0.0)
		x += 2.0 * M_PI;
	if (x > M_PI)
		return ((2.0 * M_PI) - x);
	return (x);
}

static float	reduce_anglef(float x)
{
	while (x > 2.0f * M_PI)
		x -= 2.0f * M_PI;
	while (x < 0.0f)
		x += 2.0f * M_PI;
	if (x > M_PI)
		return ((2.0f * M_PI) - x);
	return (x);
}

double	ft_cos(double x)
{
	double	result;
	double	x_squared;
	double	term;
	int		i;

	if (x == 0.0)
		return (1.0);
	if (x < 0.0)
		return (ft_cos(-x));
	x = reduce_angle(x);
	result = 1.0;
	x_squared = x * x;
	term = 1.0;
	i = 1;
	while (i < 12)
	{
		term = -term * x_squared / ((2 * i - 1) * (2 * i));
		result += term;
		i++;
	}
	return (result);
}

float	ft_cosf(float x)
{
	float	result;
	float	x_squared;
	float	term;
	int		i;

	if (x == 0.0f)
		return (1.0f);
	if (x < 0.0f)
		return (ft_cosf(-x));
	x = reduce_anglef(x);
	result = 1.0f;
	x_squared = x * x;
	term = 1.0f;
	i = 1;
	while (i < 12)
	{
		term = -term * x_squared / ((2 * i - 1) * (2 * i));
		result += term;
		i++;
	}
	return (result);
}

double	safe_cos(t_libft *libft, double x)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0.0);
	}
	return (ft_cos(x));
}

float	safe_cosf(t_libft *libft, float x)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0.0f);
	}
	return (ft_cosf(x));
}
