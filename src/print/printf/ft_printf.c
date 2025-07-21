/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 08:19:42 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 11:15:59 by anchikri         ###   ########.fr       */
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

int	safe_printf(t_libft *libft, const char *s, ...)
{
	t_libft *safe_libft;
	int 	ret;
	va_list ap;

	if (!libft)
	{
		safe_libft = safe_libft_init();
		SET_ERROR(safe_libft->error_ctx, ERROR_MEMORY, ENOMEM,
			"libft is null");
		PRINT_ERROR(safe_libft->error_ctx);
		libft_destroy(safe_libft);
		return (-1);
	}
	va_start(ap, s);
	ret = ft_printf(s, ap);
	va_end(ap);
	return (ret);
}
