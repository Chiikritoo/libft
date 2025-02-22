/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:57:35 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/22 01:14:16 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/libft.h"

// function who appends the string 's' to the string 'str'
void	append_str(t_buffer *buf, char *s)
{
	size_t	len;
	size_t	to_copy;

	if (!buf)
		return ;
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	while (len)
	{
		if (buf->length == buf->capacity)
			buffer_flush(buf);
		to_copy = buf->capacity - buf->length;
		if (to_copy > len)
			to_copy = len;
		ft_memcpy(buf->data + buf->length, s, to_copy);
		buf->length += to_copy;
		s += to_copy;
		len -= to_copy;
	}
}
