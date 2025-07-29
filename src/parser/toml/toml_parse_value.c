/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toml_parse_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:30:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/29 14:43:12 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

// function who parses a TOML value (string, int, float, bool, array, table)
t_toml_value	toml_parse_value(const char *str)
{
	t_toml_value	value;
	char		*trimmed;

	if (!str)
	{
		value.type = TOML_STRING;
		value.data.str = NULL;
		return (value);
	}
	trimmed = ft_strtrim(str, " \t");
	if (!trimmed)
	{
		value.type = TOML_STRING;
		value.data.str = NULL;
		return (value);
	}
	// Check for array
	if (trimmed[0] == '[' && trimmed[ft_strlen(trimmed) - 1] == ']')
	{
		value.type = TOML_ARRAY;
		value.data.array = toml_parse_array(trimmed);
	}
	// Check for table
	else if (trimmed[0] == '{' && trimmed[ft_strlen(trimmed) - 1] == '}')
	{
		value.type = TOML_TABLE;
		value.data.table = toml_parse_table(trimmed);
	}
	// Check for boolean
	else if (ft_strcmp(trimmed, "true") == 0)
	{
		value.type = TOML_BOOL;
		value.data.b = true;
	}
	else if (ft_strcmp(trimmed, "false") == 0)
	{
		value.type = TOML_BOOL;
		value.data.b = false;
	}
	// Check for integer
	else if (ft_isdigit(trimmed[0]) || (trimmed[0] == '-' && ft_isdigit(trimmed[1])))
	{
		// Check if it's a float (contains dot)
		if (ft_strchr(trimmed, '.'))
		{
			value.type = TOML_FLOAT;
			value.data.f = ft_atof(trimmed);
		}
		else
		{
			value.type = TOML_INT;
			value.data.num = ft_atoi(trimmed);
		}
	}
	// Default to string
	else
	{
		value.type = TOML_STRING;
		// Remove quotes if present
		if (trimmed[0] == '"' && trimmed[ft_strlen(trimmed) - 1] == '"')
		{
			value.data.str = ft_substr(trimmed, 1, ft_strlen(trimmed) - 2);
		}
		else
		{
			value.data.str = ft_strdup(trimmed);
		}
		// Remove trailing newline if present
		if (value.data.str && ft_strlen(value.data.str) > 0)
		{
			size_t len = ft_strlen(value.data.str);
			if (value.data.str[len - 1] == '\n')
				value.data.str[len - 1] = '\0';
		}
	}
	free(trimmed);
	return (value);
} 
