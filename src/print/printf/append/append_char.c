/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:57:02 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/22 01:14:16 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/libft.h"

// function who appends the character 'c' to the string 'str'
void	append_char(t_buffer *buf, char c)
{
	if (!buf)
		return ;
	if (buf->length == buf->capacity)
		buffer_flush(buf);
	buf->data[buf->length++] = c;
}
