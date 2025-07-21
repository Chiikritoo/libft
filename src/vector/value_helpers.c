/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:42:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 23:42:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_value	value_create(e_type type, t_any data)
{
	t_value	value;

	value.type = type;
	value.owned = false;
	value.as = data;
	return (value);
}

t_value	value_char(char c)
{
	t_value	value;

	value.type = TYPE_CHAR;
	value.owned = false;
	value.as.c = c;
	return (value);
}

t_value	value_string(char *str)
{
	t_value	value;

	value.type = TYPE_STRING;
	value.owned = false;
	value.as.str = str;
	return (value);
}

t_value	value_int(int i)
{
	t_value	value;

	value.type = TYPE_INT;
	value.owned = false;
	value.as.i = i;
	return (value);
}

t_value	value_float(float f)
{
	t_value	value;

	value.type = TYPE_FLOAT;
	value.owned = false;
	value.as.f = f;
	return (value);
}

t_value	value_double(double d)
{
	t_value	value;

	value.type = TYPE_DOUBLE;
	value.owned = false;
	value.as.d = d;
	return (value);
}

t_value	value_bool(bool b)
{
	t_value	value;

	value.type = TYPE_BOOL;
	value.owned = false;
	value.as.b = b;
	return (value);
}

t_value	value_ptr(void *p)
{
	t_value	value;

	value.type = TYPE_PTR;
	value.owned = false;
	value.as.p = p;
	return (value);
} 
