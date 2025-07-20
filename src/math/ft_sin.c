/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:23:19 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 15:37:14 by anchikri         ###   ########.fr       */
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
		return (-reduce_angle(x - M_PI));
	if (x > M_PI / 2.0)
		return (reduce_angle(M_PI - x));
	return (x);
}

static float	reduce_anglef(float x)
{
	while (x > 2.0f * M_PI)
		x -= 2.0f * M_PI;
	while (x < 0.0f)
		x += 2.0f * M_PI;
	if (x > M_PI)
		return (-reduce_anglef(x - M_PI));
	if (x > M_PI / 2.0f)
		return (reduce_anglef(M_PI - x));
	return (x);
}

double	ft_sin(double x)
{
	double	result;
	double	x_squared;
	double	term;
	int		i;

	if (x == 0.0)
		return (0.0);
	if (x < 0.0)
		return (-ft_sin(-x));
	x = reduce_angle(x);
	result = x;
	x_squared = x * x;
	term = x;
	i = 1;
	while (i < 6)
	{
		term = -term * x_squared / ((2 * i) * (2 * i + 1));
		result += term;
		i++;
	}
	return (result);
}

float	ft_sinf(float x)
{
	float	result;
	float	x_squared;
	float	term;
	int		i;

	if (x == 0.0f)
		return (0.0f);
	if (x < 0.0f)
		return (-ft_sinf(-x));
	x = reduce_anglef(x);
	result = x;
	x_squared = x * x;
	term = x;
	i = 1;
	while (i < 6)
	{
		term = -term * x_squared / ((2 * i) * (2 * i + 1));
		result += term;
		i++;
	}
	return (result);
}

double	safe_sin(t_libft *libft, double x)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0.0);
	}
	return (ft_sin(x));
}

float	safe_sinf(t_libft *libft, float x)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0.0f);
	}
	return (ft_sinf(x));
}
