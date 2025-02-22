/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 08:19:42 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/22 01:15:44 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

int	buffer_init(t_buffer *buffer)
{
	if (!buffer)
		return (-1);
	buffer->capacity = BUFFER_SIZE;
	buffer->length = 0;
	return (0);
}

// function who writes the string and the arguments to the standard output
int	ft_printf(const char *s, ...)
{
	t_buffer	buf;
	va_list		ap;
	int			len;

	if (buffer_init(&buf) == -1)
		return (-1);
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%' && *(s + 1))
			handle_format(&ap, &buf, *(++s));
		else
			append_char(&buf, *s);
		s++;
	}
	va_end(ap);
	len = write(1, buf.data, buf.length);
	return (len);
}
