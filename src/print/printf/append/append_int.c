/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:57:44 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/22 01:14:16 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/libft.h"

// function who appends the integer 'n' to the string 'str'
void	append_int(t_buffer *buf, int n)
{
	char	nb_str[12];
	int		i;
	long	nb;

	if (!buf)
		return ;
	nb = n;
	if (n < 0)
		nb = -(long)n;
	i = 11;
	nb_str[i] = '\0';
	if (nb == 0)
		nb_str[--i] = '0';
	while (nb > 0)
	{
		nb_str[--i] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		nb_str[--i] = '-';
	append_str(buf, &nb_str[i]);
}
