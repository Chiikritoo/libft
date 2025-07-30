/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toml_parse_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:30:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/30 02:04:54 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

// function who validates and parses a float number
bool	parse_float(const char *str, t_toml_value *value)
{
	double	num;

	num = ft_atof(str);
	if (num == 0.0 && str[0] != '0' && str[0] != '-' && str[0] != '+')
	{
		LOG(LOG_WARNING, "Invalid float format: %s", str);
		return (false);
	}
	value->type = TOML_FLOAT;
	value->data.f = num;
	LOG(LOG_DEBUG, "Parsed float: %f", num);
	return (true);
}

// function who validates and parses an integer
bool	parse_integer(const char *str, t_toml_value *value)
{
	int	int_num;

	if (ft_strlen(str) > 10)
	{
		LOG(LOG_WARNING, "Integer too large: %s", str);
		return (false);
	}
	int_num = ft_atoi(str);
	if (int_num == 0 && str[0] != '0' && str[0] != '-' && str[0] != '+')
	{
		LOG(LOG_WARNING, "Invalid integer format: %s", str);
		return (false);
	}
	value->type = TOML_INT;
	value->data.num = int_num;
	LOG(LOG_DEBUG, "Parsed integer: %d", int_num);
	return (true);
}

// function who validates and parses a number
bool	parse_number(const char *str, t_toml_value *value)
{
	if (!str || !value)
		return (false);
	if (ft_strchr(str, '.') || ft_strchr(str, 'e') || ft_strchr(str, 'E'))
		return (parse_float(str, value));
	else
		return (parse_integer(str, value));
}

// function who parses a boolean value
bool	parse_boolean(const char *str, t_toml_value *value)
{
	if (ft_strcmp(str, "true") == 0)
	{
		value->type = TOML_BOOL;
		value->data.b = true;
		LOG(LOG_DEBUG, "Parsed boolean: true");
		return (true);
	}
	else if (ft_strcmp(str, "false") == 0)
	{
		value->type = TOML_BOOL;
		value->data.b = false;
		LOG(LOG_DEBUG, "Parsed boolean: false");
		return (true);
	}
	return (false);
}

// function who parses a string value
bool	parse_string_value(const char *str, t_toml_value *value)
{
	value->type = TOML_STRING;
	value->data.str = parse_toml_string(str);
	if (!value->data.str)
	{
		LOG(LOG_ERROR, "Failed to parse string value: %s", str);
		value->type = TOML_STRING;
		value->data.str = NULL;
		return (false);
	}
	LOG(LOG_DEBUG, "Parsed string: %s", value->data.str);
	return (true);
}

// function who parses a TOML value
t_toml_value	toml_parse_value(const char *str)
{
	t_toml_value	value;
	char			*trimmed;

	value.type = TOML_STRING;
	value.data.str = NULL;
	if (!str)
	{
		LOG(LOG_WARNING, "toml_parse_value: input string is NULL");
		return (value);
	}
	trimmed = ft_strtrim(str, " \t");
	if (!trimmed)
	{
		LOG(LOG_ERROR, "Failed to trim string: %s", str);
		return (value);
	}
	LOG(LOG_DEBUG, "Parsing value: '%s'", trimmed);
	value = toml_dispatch_value_parsing(trimmed);
	free(trimmed);
	return (value);
}
