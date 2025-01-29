/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:25:38 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/29 17:25:23 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who converts the the string pointed by nptr to int
int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		nb = (nb * 10) + nptr[i++] - '0';
	return (sign * nb);
}
