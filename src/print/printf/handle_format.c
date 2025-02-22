/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:56:13 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/22 01:13:58 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	buffer_flush(t_buffer *buf)
{
	if (!buf || !buf->length)
		return ;
	write(1, buf->data, buf->length);
	buf->length = 0;
}

// function who handles the format specifier 
// 'c', 's', 'd', 'i', 'u', 'x', 'X', 'p', '%'
void	handle_format(va_list *ap, t_buffer *buf, char c)
{
	if (!buf)
		return ;
	if (c == 'c')
		append_char(buf, va_arg(*ap, int));
	else if (c == 's')
		append_str(buf, va_arg(*ap, char *));
	else if (c == 'd' || c == 'i')
		append_int(buf, va_arg(*ap, int));
	else if (c == 'u')
		append_uint(buf, va_arg(*ap, unsigned int));
	else if (c == 'x')
		append_base(buf, va_arg(*ap, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		append_base(buf, va_arg(*ap, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		append_ptr(buf, va_arg(*ap, void *));
	else if (c == '%')
		append_char(buf, '%');
}
