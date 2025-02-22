/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 08:19:42 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/22 01:15:39 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

// function who writes the string and the arguments to the file descriptor 'fd'
int	ft_dprintf(int fd, const char *s, ...)
{
	int			len;
	t_buffer	buf;
	va_list		ap;

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
	len = write(fd, buf.data, buf.length);
	return (len);
}
