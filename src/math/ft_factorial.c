/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 03:06:15 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 03:09:00 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Calcule le factoriel d'un entier
 * @param n L'entier (doit être positif et <= 20)
 * @return long long Le factoriel
 * @note Retourne -1 si n est négatif ou trop grand
 */
long long	ft_factorial(int n)
{
	long long	result;

	if (n < 0)
		return (-1);
	if (n > 20) // Pour éviter l'overflow
		return (-1);
	if (n == 0 || n == 1)
		return (1);
	
	result = 1;
	while (n > 1)
	{
		result *= n;
		if (result < 0) // Overflow
			return (-1);
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
