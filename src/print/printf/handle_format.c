/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:56:13 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/16 02:10:23 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/print.h"

// function who handles the format specifier 
// 'c', 's', 'd', 'i', 'u', 'x', 'X', 'p', '%'
void	handle_format(va_list ap, char **str, char c)
{
	if (c == 'c')
		append_char(str, va_arg(ap, int));
	else if (c == 's')
		append_str(str, va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		append_int(str, va_arg(ap, int));
	else if (c == 'u')
		append_uint(str, va_arg(ap, unsigned int));
	else if (c == 'x')
		append_base(str, va_arg(ap, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		append_base(str, va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		append_ptr(str, va_arg(ap, unsigned long));
	else if (c == '%')
		append_char(str, '%');
}
