/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:07:11 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 18:07:34 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Force une valeur à rester dans l'intervalle [min, max]
 * @param value La valeur à borner
 * @param min La borne inférieure
 * @param max La borne supérieure
 * @return int La valeur bornée
 */
int	ft_clamp(int value, int min, int max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

/**
 * @brief Version sécurisée de ft_clamp avec gestion d'erreur
 * @param libft Le contexte libft
 * @param value La valeur à borner
 * @param min La borne inférieure
 * @param max La borne supérieure
 * @return int La valeur bornée, ou 0 si libft est NULL
 */
int	safe_clamp(t_libft *libft, int value, int min, int max)
{
	if (!libft)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"libft is NULL");
		return (0);
	}
	return (ft_clamp(value, min, max));
}
