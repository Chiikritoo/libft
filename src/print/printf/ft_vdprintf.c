/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:54:18 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/23 22:55:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function who writes the string and the arguments to the file descriptor 'fd'
// using a va_list instead of variadic arguments
int	ft_vdprintf(int fd, const char *s, va_list ap)
{
	int			len;
	t_buffer	buf;
	va_list		ap_copy;

	if (buffer_init(&buf) == -1)
		return (-1);
	va_copy(ap_copy, ap);
	while (*s)
	{
		if (*s == '%' && *(s + 1))
			handle_format(&ap_copy, &buf, *(++s));
		else
			append_char(&buf, *s);
		s++;
	}
	va_end(ap_copy);
	len = write(fd, buf.data, buf.length);
	return (len);
}


