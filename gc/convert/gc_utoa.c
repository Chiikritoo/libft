/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:28:32 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 02:21:52 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who converts the unsigned integer 'n' to a string
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
