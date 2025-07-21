/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 03:06:15 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 11:11:38 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

long long	ft_factorial(int n)
{
	long long	result;

	if (n < 0)
		return (-1);
	if (n > 20)
		return (-1);
	if (n == 0 || n == 1)
		return (1);
	result = 1;
	while (n > 1)
	{
		result *= n;
		if (result < 0)
			return (-1);
		n--;
	}
	return (result);
}

double	ft_dfactorial(int n)
{
	double	result;

	if (n < 0)
		return (1.0);
	if (n > 170)
		return (1.0);
	if (n == 0 || n == 1)
		return (1.0);
	result = 1.0;
	while (n > 1)
	{
		result *= n;
		n--;
	}
	return (result);
}

long long	safe_factorial(t_libft *libft, int n)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0);
	}
	return (ft_factorial(n));
}

double	safe_dfactorial(t_libft *libft, int n)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0);
	}
	return (ft_dfactorial(n));
}
