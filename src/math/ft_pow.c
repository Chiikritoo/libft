/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 03:05:45 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 15:47:01 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

double	ft_pow(double x, double y)
{
	double	result;
	int		exponent;

	if (y == 0.0)
		return (1.0);
	if (x == 0.0)
		return (0.0);
	if (x == 1.0)
		return (1.0);
	if (y == 1.0)
		return (x);
	if (y < 0.0)
		return (1.0 / ft_pow(x, -y));
	if (y != (int)y)
	{
		if (x <= 0.0)
			return (-1.0);
		return (exp(y * log(x)));
	}
	exponent = (int)y;
	result = 1.0;
	while (exponent > 0)
	{
		result *= x;
		exponent--;
	}
	return (result);
}

float	ft_powf(float x, float y)
{
	float	result;
	int		exponent;

	if (y == 0.0f)
		return (1.0f);
	if (x == 0.0f)
		return (0.0f);
	if (x == 1.0f)
		return (1.0f);
	if (y == 1.0f)
		return (x);
	if (y < 0.0f)
		return (1.0f / ft_powf(x, -y));
	if (y != (int)y)
	{
		if (x <= 0.0f)
			return (-1.0f);
		return (expf(y * logf(x)));
	}
	exponent = (int)y;
	result = 1.0f;
	while (exponent > 0)
	{
		result *= x;
		exponent--;
	}
	return (result);
}

double	safe_pow(t_libft *libft, double x, double y)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0.0);
	}
	return (ft_pow(x, y));
}

float	safe_powf(t_libft *libft, float x, float y)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0.0f);
	}
	return (ft_powf(x, y));
}
