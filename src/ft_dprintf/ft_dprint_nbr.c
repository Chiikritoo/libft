/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprint_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:42:49 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/13 03:28:06 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_dputnbr(char **str, int nb)
{
	if (nb < 0)
	{
		ft_putchar(str, '-');
		nb *= -1;
	}
	if (nb >= 9)
		ft_putnbr(str, nb / 10);
	ft_putchar(str, (nb % 10) + '0');
}

void	ft_dputnbr_base(char **str, unsigned long nb, char *hex, int ptr)
{
	if (ptr == 1)
	{
		ft_dputstr(str, "0x");
		ptr = 0;
	}
	if (nb >= 16)
		ft_dputnbr_base(str, nb / 16, hex, ptr);
	ft_dputchar(str, hex[nb % 16]);
}

void	ft_dputnbr_hex(char **str, unsigned long nb, char *hex)
{
	if (nb >= 16)
		ft_putnbr_hex(str, nb / 16, hex);
	ft_putchar(str, hex[nb % 16]);
}
