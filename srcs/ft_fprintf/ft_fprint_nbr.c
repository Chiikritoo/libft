/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprint_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:42:49 by anchikri          #+#    #+#             */
/*   Updated: 2024/06/12 22:23:08 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/libft.h"

void	ft_fputnbr(char **str, int nb)
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

void	ft_fputnbr_base(char **str, unsigned long nb, char *hex, int ptr)
{
	if (ptr == 1)
	{
		ft_fputstr(str, "0x");
		ptr = 0;
	}
	if (nb >= 16)
		ft_fputnbr_base(str, nb / 16, hex, ptr);
	ft_fputchar(str, hex[nb % 16]);
}

void	ft_fputnbr_hex(char **str, unsigned long nb, char *hex)
{
	if (nb >= 16)
		ft_putnbr_hex(str, nb / 16, hex);
	ft_putchar(str, hex[nb % 16]);
}
