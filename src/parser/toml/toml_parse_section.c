/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toml_parse_section.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:30:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/15 10:30:00 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

// function who parses a TOML section name from a line
char	*toml_parse_section_name(const char *line)
{
	char	*trimmed;
	char	*section_name;
	size_t	len;

	if (!line)
		return (NULL);
	trimmed = ft_strtrim(line, " \t\n");
	if (!trimmed)
		return (NULL);
	if (trimmed[0] != '[' || trimmed[ft_strlen(trimmed) - 1] != ']')
	{
		free(trimmed);
		return (NULL);
	}
	// Extract section name (remove [ and ])
	len = ft_strlen(trimmed);
	if (len < 3) // [x] minimum
	{
		free(trimmed);
		return (NULL);
	}
	section_name = ft_substr(trimmed, 1, len - 2);
	section_name = ft_strtrim(section_name, " \t");
	free(trimmed);
	return (section_name);
}

// function who creates a new TOML section
t_toml_section	*toml_create_section(const char *name)
{
	t_toml_section	*section;

	if (!name)
		return (NULL);
	section = ft_calloc(1, sizeof(t_toml_section));
	if (!section)
		return (NULL);
	section->name = ft_strdup(name);
	section->kv = NULL;
	section->count = 0;
	return (section);
}

// function who adds a key-value pair to a section
int	toml_add_kv_to_section(t_toml_section *section, t_toml_kv *kv)
{
	t_toml_kv	**new_kv;

	if (!section || !kv)
		return (0);
	new_kv = ft_realloc(section->kv, 
		section->count * sizeof(t_toml_kv *), 
		(section->count + 1) * sizeof(t_toml_kv *));
	if (!new_kv)
		return (0);
	section->kv = new_kv;
	section->kv[section->count] = kv;
	section->count++;
	return (1);
}

// function who creates a new TOML array
t_toml_array	*toml_create_array(t_toml_type element_type)
{
	t_toml_array	*array;

	array = ft_calloc(1, sizeof(t_toml_array));
	if (!array)
		return (NULL);
	array->values = NULL;
	array->size = 0;
	array->element_type = element_type;
	return (array);
}

// function who adds a value to an array
int	toml_add_to_array(t_toml_array *array, t_toml_value value)
{
	t_toml_value	**new_values;

	if (!array)
		return (0);
	new_values = ft_realloc(array->values,
		array->size * sizeof(t_toml_value *),
		(array->size + 1) * sizeof(t_toml_value *));
	if (!new_values)
		return (0);
	array->values = new_values;
	array->values[array->size] = ft_calloc(1, sizeof(t_toml_value));
	if (!array->values[array->size])
		return (0);
	*array->values[array->size] = value;
	array->size++;
	return (1);
}

// function who gets a value from an array
t_toml_value	*toml_get_array_value(t_toml_array *array, size_t index)
{
	if (!array || index >= array->size)
		return (NULL);
	return (array->values[index]);
}

// function who parses an array from string
t_toml_array	*toml_parse_array(const char *str)
{
	t_toml_array	*array;
	char		*content;
	char		**elements;
	int			i;

	if (!str || ft_strlen(str) < 2)
		return (NULL);
	// Extract content between [ and ]
	content = ft_substr(str, 1, ft_strlen(str) - 2);
	if (!content)
		return (NULL);
	// Split by comma
	elements = ft_split(content, ',');
	free(content);
	if (!elements)
		return (NULL);
	// Create array
	array = toml_create_array(TOML_STRING); // Default type
	if (!array)
	{
		ft_free_double_ptr((void ***)&elements);
		return (NULL);
	}
	// Parse each element
	i = 0;
	while (elements[i])
	{
		t_toml_value value = toml_parse_value(elements[i]);
		toml_add_to_array(array, value);
		i++;
	}
	ft_free_double_ptr((void ***)&elements);
	return (array);
}

// function who creates a new TOML table
t_toml_table	*toml_create_table(const char *key)
{
	t_toml_table	*table;

	if (!key)
		return (NULL);
	table = ft_calloc(1, sizeof(t_toml_table));
	if (!table)
		return (NULL);
	table->key = ft_strdup(key);
	table->value = NULL;
	table->next = NULL;
	return (table);
}

// function who adds a key-value pair to a table
int	toml_add_to_table(t_toml_table *table, const char *key, t_toml_value value)
{
	t_toml_table	*new_entry;

	if (!table || !key)
		return (0);
	new_entry = ft_calloc(1, sizeof(t_toml_table));
	if (!new_entry)
		return (0);
	new_entry->key = ft_strdup(key);
	new_entry->value = ft_calloc(1, sizeof(t_toml_value));
	if (!new_entry->value)
	{
		free(new_entry->key);
		free(new_entry);
		return (0);
	}
	*new_entry->value = value;
	new_entry->next = table->next;
	table->next = new_entry;
	return (1);
}

// function who gets a value from a table
t_toml_value	*toml_get_table_value(t_toml_table *table, const char *key)
{
	t_toml_table	*current;

	if (!table || !key)
		return (NULL);
	current = table->next;
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

// function who parses a table from string
t_toml_table	*toml_parse_table(const char *str)
{
	t_toml_table	*table;
	char		*content;
	char		**pairs;
	int			i;

	if (!str || ft_strlen(str) < 2)
		return (NULL);
	// Extract content between { and }
	content = ft_substr(str, 1, ft_strlen(str) - 2);
	if (!content)
		return (NULL);
	// Split by comma
	pairs = ft_split(content, ',');
	free(content);
	if (!pairs)
		return (NULL);
	// Create table
	table = toml_create_table("root");
	if (!table)
	{
		ft_free_double_ptr((void ***)&pairs);
		return (NULL);
	}
	// Parse each key=value pair
	i = 0;
	while (pairs[i])
	{
		char		*equal_pos;
		char		*key;
		char		*value_str;

		equal_pos = ft_strchr(pairs[i], '=');
		if (equal_pos)
		{
			key = ft_substr(pairs[i], 0, equal_pos - pairs[i]);
			key = ft_strtrim(key, " \t");
			value_str = ft_strdup(equal_pos + 1);
			value_str = ft_strtrim(value_str, " \t");
			t_toml_value value = toml_parse_value(value_str);
			toml_add_to_table(table, key, value);
			free(key);
			free(value_str);
		}
		i++;
	}
	ft_free_double_ptr((void ***)&pairs);
	return (table);
} 
 