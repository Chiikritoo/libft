/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:58:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/21 23:44:05 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/libft.h"

// function who appends the unsigned integer 'n' to the string 'str'
void	append_uint(t_buffer *buf, unsigned int n)
{
	char	*nb_str;

	if (!buf)
		return ;
	nb_str = ft_utoa(n);
	if (!nb_str)
		return ;
	append_str(buf, nb_str);
	free(nb_str);
}
