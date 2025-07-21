/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 08:19:42 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 22:56:12 by anchikri         ###   ########.fr       */
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

int	safe_dprintf(t_libft *libft, int fd, const char *s, ...)
{
	t_libft	*safe_libft;
	int		ret;
	va_list	ap;

	if (!libft)
	{
		safe_libft = safe_libft_init();
		SET_ERROR(safe_libft->error_ctx, ERROR_MEMORY, ENOMEM, "libft is null");
		PRINT_ERROR(safe_libft->error_ctx);
		libft_destroy(safe_libft);
		return (-1);
	}
	va_start(ap, s);
	ret = ft_dprintf(fd, s, ap);
	va_end(ap);
	return (ret);
}
