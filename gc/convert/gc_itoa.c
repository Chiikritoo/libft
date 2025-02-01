/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:49:29 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/01 00:17:58 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who converts the integer 'n' to a string
char	*gc_itoa(t_gc_ctx *ctx, int n)
{
	int		len;
	long	nb;
	char	*tab;

	nb = n;
	len = len_int(nb);
	tab = gc_calloc(ctx, len + 1, sizeof(char));
	if (!tab)
		return (NULL);
	if (nb < 0)
	{
		tab[0] = '-';
		nb *= -1;
	}
	while (len > 0 && tab[len - 1] != '-')
	{
		len--;
		tab[len] = (nb % 10) + 48;
		nb /= 10;
	}
	return (tab);
}
