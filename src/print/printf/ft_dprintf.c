/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 08:19:42 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/16 02:09:54 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/print.h"

// function who writes the string and the arguments to the file descriptor 'fd'
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
			handle_format(ap, &str, *(++s));
		else
			append_char(&str, *s);
		s++;
	}
	va_end(ap);
	len = write(fd, str, ft_strlen(str));
	free(str);
	return (len);
}
