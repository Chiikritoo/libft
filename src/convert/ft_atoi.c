/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:25:38 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/19 22:23:04 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who converts the the string pointed by nptr to int
int	ft_atoi(const char *nptr)
{
	int	i;
	int	op;
	int	nb;

	i = 0;
	op = 1;
	nb = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			op = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		nb = (nb * 10) + nptr[i++] - '0';
	return (op * nb);
}
