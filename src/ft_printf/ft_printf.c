/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 08:19:42 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/13 03:26:43 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static void	ft_formats(va_list ap, char **str, char c)
{
	if (c == 'c')
		ft_putchar(str, va_arg(ap, int));
	else if (c == 's')
		ft_putstr(str, va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		ft_putnbr(str, va_arg(ap, int));
	else if (c == 'u')
		ft_putnbr(str, va_arg(ap, unsigned int));
	else if (c == 'x')
		ft_putnbr_base(str, va_arg(ap, unsigned int), "0123456789abcdef", 0);
	else if (c == 'X')
		ft_putnbr_base(str, va_arg(ap, unsigned int), "0123456789ABCDEF", 0);
	else if (c == 'p')
		ft_putnbr_base(str, va_arg(ap, unsigned long), "0123456789abcdef", 1);
	else if (c == '%')
		ft_putchar(str, '%');
}

int	ft_printf(const char *s, ...)
{
	int		len;
	char	*str;
	va_list	ap;

	str = ft_strdup("");
	if (!str)
		return (-1);
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
			ft_formats(ap, &str, *(++s));
		else
			ft_putchar(&str, *s);
		s++;
	}
	va_end(ap);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
