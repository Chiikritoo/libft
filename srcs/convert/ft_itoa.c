/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:49:29 by anchikri          #+#    #+#             */
/*   Updated: 2024/06/12 22:23:08 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/libft.h"

static int	ft_len_itoa(int n)
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

char	*ft_itoa(int n)
{
	int		is_negative;
	char	*tab;

	is_negative = 0;
	if (n <= 0)
	{
		is_negative = 1;
		n *= -1;
	}
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tab = ft_calloc(ft_len_itoa(n) + is_negative + 1, sizeof(char));
	if (!tab)
		return (NULL);
	while (n)
	{
		tab[ft_len_itoa(n) + is_negative - 1] = (n % 10) + 48;
		n /= 10;
	}
	if (is_negative)
		tab[0] = '-';
	return (tab);
}
