/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:28:32 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 02:07:19 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	len_uint(unsigned int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*gc_utoa(t_gc_ctx *ctx, unsigned int n)
{
	int		len;
	char	*tab;

	len = len_uint(n);
	tab = gc_calloc(ctx, len + 1, sizeof(char));
	if (!tab)
		return (NULL);
	while (len > 0)
	{
		len--;
		tab[len] = (n % 10) + 48;
		n /= 10;
	}
	return (tab);
}
