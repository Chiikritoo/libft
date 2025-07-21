/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:55:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 22:56:20 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

static void	vappend_char(t_buffer *buf, char c, size_t max_size)
{
	if (!buf || buf->length >= max_size)
		return ;
	buf->data[buf->length] = c;
	buf->length++;
}

static void	vappend_str(t_buffer *buf, char *s, size_t max_size)
{
	size_t	len;
	size_t	to_copy;

	if (!buf || !s)
		return ;
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	while (len && buf->length < max_size)
	{
		to_copy = max_size - buf->length;
		if (to_copy > len)
			to_copy = len;
		ft_memcpy(buf->data + buf->length, s, to_copy);
		buf->length += to_copy;
		s += to_copy;
		len -= to_copy;
	}
}

static void	vappend_int(t_buffer *buf, int n, size_t max_size)
{
	char	nb_str[12];
	int		i;
	long	nb;

	if (!buf)
		return ;
	nb = n;
	if (n < 0)
		nb = -(long)n;
	i = 11;
	nb_str[i] = '\0';
	if (nb == 0)
		nb_str[--i] = '0';
	while (nb > 0)
	{
		nb_str[--i] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		nb_str[--i] = '-';
	vappend_str(buf, &nb_str[i], max_size);
}

static void	vappend_uint(t_buffer *buf, unsigned int n, size_t max_size)
{
	char	*nb_str;

	if (!buf)
		return ;
	nb_str = ft_utoa(n);
	if (!nb_str)
		return ;
	vappend_str(buf, nb_str, max_size);
	free(nb_str);
}

static void	vappend_base(t_buffer *buf, unsigned long long n, char *base,
		size_t max_size)
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
	vappend_str(buf, &nb_str[i + 1], max_size);
}

static void	vappend_ptr(t_buffer *buf, void *ptr, size_t max_size)
{
	if (!buf)
		return ;
	if (!ptr)
		vappend_str(buf, "0x0", max_size);
	else
	{
		vappend_str(buf, "0x", max_size);
		vappend_base(buf, (unsigned long)ptr, "0123456789abcdef", max_size);
	}
}

static void	vhandle_format(va_list ap, t_buffer *buf, char c, size_t max_size)
{
	if (!buf)
		return ;
	if (c == 'c')
		vappend_char(buf, va_arg(ap, int), max_size);
	else if (c == 's')
		vappend_str(buf, va_arg(ap, char *), max_size);
	else if (c == 'd' || c == 'i')
		vappend_int(buf, va_arg(ap, int), max_size);
	else if (c == 'u')
		vappend_uint(buf, va_arg(ap, unsigned int), max_size);
	else if (c == 'x')
		vappend_base(buf, va_arg(ap, unsigned int), "0123456789abcdef",
			max_size);
	else if (c == 'X')
		vappend_base(buf, va_arg(ap, unsigned int), "0123456789ABCDEF",
			max_size);
	else if (c == 'p')
		vappend_ptr(buf, va_arg(ap, void *), max_size);
	else if (c == '%')
		vappend_char(buf, '%', max_size);
}

int	ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	t_buffer	buf;
	size_t		max_size;

	if (!format || buffer_init(&buf) == -1)
		return (-1);
	if (str && size > 0)
		max_size = size - 1;
	else
		max_size = INT_MAX;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
			vhandle_format(ap, &buf, *(++format), max_size);
		else
			vappend_char(&buf, *format, max_size);
		format++;
	}
	if (str && size > 0)
	{
		ft_memcpy(str, buf.data, buf.length);
		str[buf.length] = '\0';
	}
	return (buf.length);
}
