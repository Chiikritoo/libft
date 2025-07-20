/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 03:05:45 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 03:09:49 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Calcule la puissance d'un entier
 * @param base La base
 * @param exponent L'exposant (doit être positif)
 * @return long long Le résultat de base^exponent
 * @note Retourne -1 si l'exposant est négatif
 */
long long	ft_pow(int base, int exponent)
{
	long long	result;

	if (exponent < 0)
		return (-1);
	if (exponent == 0)
		return (1);
	if (exponent == 1)
		return (base);
	
	result = 1;
	while (exponent > 0)
	{
		result *= base;
		if (result < 0) // Overflow
			return (-1);
		exponent--;
	}
	return (result);
} 

long long	safe_pow(t_libft *libft, int base, int exponent)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0);
	}
	return (ft_pow(base, exponent));
}
