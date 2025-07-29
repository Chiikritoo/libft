/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toml_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:30:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/15 10:30:00 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function who frees a TOML value
void	toml_free_value(t_toml_value *value)
{
	if (!value)
		return ;
	if (value->type == TOML_STRING && value->data.str)
		free(value->data.str);
	else if (value->type == TOML_ARRAY && value->data.array)
		toml_free_array(value->data.array);
	else if (value->type == TOML_TABLE && value->data.table)
		toml_free_table(value->data.table);
}

// function who frees a TOML key-value pair
void	toml_free_kv(t_toml_kv *kv)
{
	if (!kv)
		return ;
	if (kv->key)
		free(kv->key);
	toml_free_value(&kv->value);
	free(kv);
}

// function who frees a TOML section
void	toml_free_section(t_toml_section *section)
{
	int	i;

	if (!section)
		return ;
	if (section->name)
		free(section->name);
	if (section->kv)
	{
		i = 0;
		while (i < section->count)
		{
			toml_free_kv(section->kv[i]);
			i++;
		}
		free(section->kv);
	}
	free(section);
}

// function who frees a complete TOML document
void	toml_free_doc(t_toml_doc *doc)
{
	int	i;

	if (!doc)
		return ;
	if (doc->sections)
	{
		i = 0;
		while (i < doc->section_count)
		{
			toml_free_section(doc->sections[i]);
			i++;
		}
		free(doc->sections);
	}
	free(doc);
}

// function who frees a TOML array
void	toml_free_array(t_toml_array *array)
{
	size_t	i;

	if (!array)
		return ;
	if (array->values)
	{
		i = 0;
		while (i < array->size)
		{
			toml_free_value(array->values[i]);
			free(array->values[i]);
			i++;
		}
		free(array->values);
	}
	free(array);
}

// function who frees a TOML table
void	toml_free_table(t_toml_table *table)
{
	t_toml_table	*current;
	t_toml_table	*next;

	if (!table)
		return ;
	if (table->key)
		free(table->key);
	if (table->value)
	{
		toml_free_value(table->value);
		free(table->value);
	}
	current = table->next;
	while (current)
	{
		next = current->next;
		if (current->key)
			free(current->key);
		if (current->value)
		{
			toml_free_value(current->value);
			free(current->value);
		}
		free(current);
		current = next;
	}
	free(table);
} 
 