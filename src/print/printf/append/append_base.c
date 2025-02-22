/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:57:58 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/22 01:14:27 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/libft.h"

// function who appends the string 'nb_str' to the string 'str'
void	append_base(t_buffer *buf, unsigned long long n, char *base)
{
	int		base_len;
	int		i;
	char	nb_str[21];

	base_len = ft_strlen(base);
	if (!buf || !base || base_len < 2)
		return ;
	i = 20;
	nb_str[i--] = '\0';
	if (n == 0)
		nb_str[i--] = '0';
	while (n)
	{
		nb_str[i--] = base[n % base_len];
		n /= base_len;
	}
	append_str(buf, &nb_str[i + 1]);
}
