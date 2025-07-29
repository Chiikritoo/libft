/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toml_section_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 01:25:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/30 01:21:42 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

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
	if (!section || !kv)
		return (0);
	
	section->kv = ft_realloc(section->kv,
		section->count * sizeof(t_toml_kv *),
		(section->count + 1) * sizeof(t_toml_kv *));
	if (!section->kv)
		return (0);
	
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
	if (!array)
		return (0);
	
	array->values = ft_realloc(array->values,
		array->size * sizeof(t_toml_value *),
		(array->size + 1) * sizeof(t_toml_value *));
	if (!array->values)
		return (0);
	
	array->values[array->size] = ft_calloc(1, sizeof(t_toml_value));
	if (!array->values[array->size])
		return (0);
	
	*(array->values[array->size]) = value;
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
	*(new_entry->value) = value;
	new_entry->next = table->next;
	table->next = new_entry;
	return (1);
} 
