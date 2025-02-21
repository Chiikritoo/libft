/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 08:19:42 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/21 23:12:36 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

// function who writes the string and the arguments to the standard output
int	ft_printf(const char *s, ...)
{
	int		len;
	char	*str;
	va_list	ap;

	str = ft_calloc(1, sizeof(char));
	if (!str)
		return (-1);
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%' && *(s + 1))
			handle_format(ap, &str, *(++s));
		else
			append_char(&str, *s);
		s++;
	}
	va_end(ap);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
