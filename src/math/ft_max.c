/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 03:05:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 22:59:21 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Retourne le maximum entre deux entiers
 * @param a Premier entier
 * @param b Deuxième entier
 * @return int Le plus grand des deux entiers
 */
int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/**
 * @brief Retourne le maximum entre deux long long
 * @param a Premier long long
 * @param b Deuxième long long
 * @return long long Le plus grand des deux
 */
long long	ft_max_ll(long long a, long long b)
{
	if (a > b)
		return (a);
	return (b);
}

/**
 * @brief Retourne le maximum entre deux entiers de façon sécurisée
 * @param libft Pointeur vers la structure libft (pour la gestion d'erreur)
 * @param a Premier entier
 * @param b Deuxième entier
 * @return int Le plus grand des deux entiers, ou 0 si libft est NULL
 */
int	safe_max(t_libft *libft, int a, int b)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0);
	}
	return (ft_max(a, b));
}

/**
 * @brief Retourne le maximum entre deux long long de façon sécurisée
 * @param libft Pointeur vers la structure libft (pour la gestion d'erreur)
 * @param a Premier long long
 * @param b Deuxième long long
 * @return long long Le plus grand des deux, ou 0 si libft est NULL
 */
long long	safe_max_ll(t_libft *libft, long long a, long long b)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0);
	}
	return (ft_max_ll(a, b));
}
