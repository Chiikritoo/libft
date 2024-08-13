/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 08:19:42 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/13 03:42:15 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static void	ft_dformats(va_list ap, char **str, char c)
{
	if (c == 'c')
		ft_dputchar(str, va_arg(ap, int));
	else if (c == 's')
		ft_dputstr(str, va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		ft_dputnbr(str, va_arg(ap, int));
	else if (c == 'u')
		ft_dputnbr(str, va_arg(ap, unsigned int));
	else if (c == 'x')
		ft_dputnbr_base(str, va_arg(ap, unsigned int), "0123456789abcdef", 0);
	else if (c == 'X')
		ft_dputnbr_base(str, va_arg(ap, unsigned int), "0123456789ABCDEF", 0);
	else if (c == 'p')
		ft_dputnbr_base(str, va_arg(ap, unsigned long), "0123456789abcdef", 1);
	else if (c == '%')
		ft_dputchar(str, '%');
}

int	ft_dprintf(int fd, const char *s, ...)
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
			ft_dformats(ap, &str, *(++s));
		else
			ft_dputchar(&str, *s);
		s++;
	}
	va_end(ap);
	len = write(fd, str, ft_strlen(str));
	free(str);
	return (len);
}
