/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toml_value_types.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 01:10:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/30 01:12:43 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

// function who detects if input is array format
bool	is_array_format(const char *str)
{
	size_t	len;

	if (!str)
		return (false);
	len = ft_strlen(str);
	return (len >= 2 && str[0] == '[' && str[len - 1] == ']');
}

// function who detects if input is table format
bool	is_table_format(const char *str)
{
	size_t	len;

	if (!str)
		return (false);
	len = ft_strlen(str);
	return (len >= 2 && str[0] == '{' && str[len - 1] == '}');
}

// function who detects if input is number format
bool	is_number_format(const char *str)
{
	if (!str || !str[0])
		return (false);
	return (ft_isdigit(str[0]) || 
		(str[0] == '-' && ft_isdigit(str[1])) || 
		(str[0] == '+' && ft_isdigit(str[1])));
}

// function who creates array value
t_toml_value	create_array_value(const char *str)
{
	t_toml_value	value;

	value.type = TOML_ARRAY;
	value.data.array = toml_parse_array(str);
	if (!value.data.array)
	{
		LOG(LOG_ERROR, "Failed to parse array: %s", str);
		value.type = TOML_STRING;
		value.data.str = NULL;
	}
	return (value);
}

// function who creates table value
t_toml_value	create_table_value(const char *str)
{
	t_toml_value	value;

	value.type = TOML_TABLE;
	value.data.table = toml_parse_table(str);
	if (!value.data.table)
	{
		LOG(LOG_ERROR, "Failed to parse table: %s", str);
		value.type = TOML_STRING;
		value.data.str = NULL;
	}
	return (value);
}

// function who creates number or string value
t_toml_value	create_number_or_string_value(const char *str)
{
	t_toml_value	value;

	value.type = TOML_STRING;
	value.data.str = NULL;
	
	if (!parse_number(str, &value))
		parse_string_value(str, &value);
	return (value);
}

// function who dispatches value parsing by type
t_toml_value	toml_dispatch_value_parsing(const char *str)
{
	t_toml_value	value;

	value.type = TOML_STRING;
	value.data.str = NULL;
	
	if (is_array_format(str))
		return (create_array_value(str));
	else if (is_table_format(str))
		return (create_table_value(str));
	else if (parse_boolean(str, &value))
		return (value);
	else if (is_toml_date(str))
	{
		parse_string_value(str, &value);
		return (value);
	}
	else if (is_number_format(str))
		return (create_number_or_string_value(str));
	else
	{
		parse_string_value(str, &value);
		return (value);
	}
} 
