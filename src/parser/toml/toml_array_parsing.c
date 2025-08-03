/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toml_array_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 01:15:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/08/02 18:06:51 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function who determines the element type from array content
static t_toml_type	determine_array_type(char **elements)
{
	t_toml_value	first_value;
	t_toml_type		result_type;
	char			*trimmed;

	if (!elements || !elements[0])
		return (TOML_STRING);
	trimmed = ft_strtrim(elements[0], " \t");
	if (!trimmed)
		return (TOML_STRING);
	first_value = toml_parse_value(trimmed);
	free(trimmed);
	result_type = first_value.type;
	toml_free_value(&first_value);
	return (result_type);
}

// function who handles type mismatch in array elements
static t_toml_value	handle_type_mismatch(t_toml_value parsed_value,
		t_toml_type expected_type)
{
	t_toml_value	converted_value;
	char			*str_representation;

	if (parsed_value.type == expected_type)
		return (parsed_value);
	LOG(LOG_WARNING, "Array element type mismatch: expected %d, got %d",
		expected_type, parsed_value.type);
	str_representation = toml_value_to_string(&parsed_value);
	if (!str_representation)
	{
		converted_value.type = TOML_STRING;
		converted_value.data.str = ft_strdup("(error)");
		return (converted_value);
	}
	converted_value.type = TOML_STRING;
	converted_value.data.str = str_representation;
	return (converted_value);
}

// function who adds an element to an array
static bool	add_array_element(t_toml_array *array, char *trimmed)
{
	t_toml_value	parsed_value;
	t_toml_value	final_value;

	if (!array || !trimmed)
		return (false);
	parsed_value = toml_parse_value(trimmed);
	final_value = handle_type_mismatch(parsed_value, array->element_type);
	array->values = ft_realloc(array->values, sizeof(t_toml_value *)
			* array->size, sizeof(t_toml_value *) * (array->size + 1));
	if (!array->values)
	{
		LOG(LOG_ERROR, "Failed to reallocate array values");
		toml_free_value(&final_value);
		return (false);
	}
	array->values[array->size] = ft_calloc(1, sizeof(t_toml_value));
	if (!array->values[array->size])
	{
		LOG(LOG_ERROR, "Failed to allocate value");
		toml_free_value(&final_value);
		return (false);
	}
	*(array->values[array->size]) = final_value;
	array->size++;
	LOG(LOG_DEBUG, "Added element to array, count now: %zu", array->size);
	return (true);
}

// function who processes array elements
static bool	process_array_elements(t_toml_array *array, char **elements)
{
	int		i;
	char	*trimmed;

	if (!array || !elements)
		return (false);
	i = 0;
	while (elements[i])
	{
		trimmed = ft_strtrim(elements[i], " \t");
		if (trimmed && ft_strlen(trimmed) > 0)
		{
			if (!add_array_element(array, trimmed))
			{
				free(trimmed);
				return (false);
			}
		}
		free(trimmed);
		i++;
	}
	return (true);
}

// function who validates and extracts array content
static char	*validate_and_extract_array_content(const char *str)
{
	char	*content;
	char	*trimmed;
	size_t	len;

	if (!str || ft_strlen(str) < 2)
	{
		LOG(LOG_WARNING, "Invalid array format (too short): %s",
			str ? str : "(null)");
		return (NULL);
	}
	len = ft_strlen(str);
	if (str[0] != '[' || str[len - 1] != ']')
	{
		LOG(LOG_WARNING, "Invalid array format (missing brackets): %s", str);
		return (NULL);
	}
	content = ft_substr(str, 1, len - 2);
	if (!content)
	{
		LOG(LOG_ERROR, "Failed to extract array content from: %s", str);
		return (NULL);
	}
	trimmed = ft_strtrim(content, " \t");
	free(content);
	return (trimmed);
}

// function who creates empty array
static t_toml_array	*create_empty_array(void)
{
	t_toml_array	*array;

	array = ft_calloc(1, sizeof(t_toml_array));
	if (!array)
		return (NULL);
	array->element_type = TOML_STRING;
	array->size = 0;
	array->values = NULL;
	return (array);
}

// function who parses a TOML array from a string
t_toml_array	*toml_parse_array(const char *str)
{
	t_toml_array	*array;
	char			*content;
	char			**elements;

	LOG(LOG_DEBUG, "Parsing array: %s", str ? str : "(null)");
	content = validate_and_extract_array_content(str);
	if (!content)
		return (NULL);
	if (ft_strlen(content) == 0)
	{
		free(content);
		return (create_empty_array());
	}
	elements = ft_split_array_elements(content);
	free(content);
	if (!elements)
		return (NULL);
	array = create_empty_array();
	if (!array)
	{
		ft_free_double_ptr((void ***)&elements);
		return (NULL);
	}
	array->element_type = determine_array_type(elements);
	if (!process_array_elements(array, elements))
	{
		ft_free_double_ptr((void ***)&elements);
		toml_free_array(array);
		return (NULL);
	}
	ft_free_double_ptr((void ***)&elements);
	LOG(LOG_DEBUG, "Successfully parsed array with %zu elements", array->size);
	return (array);
}
