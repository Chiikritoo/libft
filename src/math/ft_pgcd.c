/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pgcd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 03:06:30 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 13:57:54 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Calcule le PGCD (Plus Grand Diviseur Commun)
 * @param a Premier entier
 * @param b Deuxième entier
 * @return int Le PGCD
 */
int	ft_pgcd(int a, int b)
{
	int	temp;

	a = ft_abs(a);
	b = ft_abs(b);
	
	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return (a);
}

int	safe_pgcd(t_libft *libft, int a, int b)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0);
	}
	return (ft_pgcd(a, b));
}
