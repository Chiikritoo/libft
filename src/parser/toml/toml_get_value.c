/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toml_get_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:30:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/30 00:30:00 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function who finds a section by name
static t_toml_section	*toml_find_section(t_toml_doc *doc,
		const char *section_name)
{
	int	i;

	if (!doc || !section_name)
	{
		LOG(LOG_WARNING, "toml_find_section: invalid parameters");
		return (NULL);
	}
	LOG(LOG_DEBUG, "Looking for section: %s", section_name);
	i = 0;
	while (i < doc->section_count)
	{
		if (ft_strcmp(doc->sections[i]->name, section_name) == 0)
		{
			LOG(LOG_DEBUG, "Found section: %s", section_name);
			return (doc->sections[i]);
		}
		i++;
	}
	LOG(LOG_WARNING, "Section not found: %s", section_name);
	return (NULL);
}

// function who finds a key-value pair by key in a section
static t_toml_kv	*toml_find_kv(t_toml_section *section, const char *key)
{
	int	i;

	if (!section || !key)
	{
		LOG(LOG_WARNING, "toml_find_kv: invalid parameters");
		return (NULL);
	}
	LOG(LOG_DEBUG, "Looking for key '%s' in section '%s'", key, section->name);
	i = 0;
	while (i < section->count)
	{
		if (ft_strcmp(section->kv[i]->key, key) == 0)
		{
			LOG(LOG_DEBUG, "Found key: %s", key);
			return (section->kv[i]);
		}
		i++;
	}
	LOG(LOG_WARNING, "Key '%s' not found in section '%s'", key, section->name);
	return (NULL);
}

// function who gets a value from a nested table
static t_toml_value	*get_nested_value(t_toml_value *value,
		const char **path_parts, int part_count)
{
	t_toml_value	*current_value;
	t_toml_table	*current_table;
	int				i;

	if (!value || !path_parts || part_count <= 0)
		return (NULL);
	current_value = value;
	for (i = 0; i < part_count; i++)
	{
		if (current_value->type != TOML_TABLE)
		{
			LOG(LOG_WARNING, "Path part '%s' is not a table", path_parts[i]);
			return (NULL);
		}
		current_table = current_value->data.table;
		if (!current_table)
		{
			LOG(LOG_WARNING, "Table is NULL for path part '%s'", path_parts[i]);
			return (NULL);
		}
		current_value = toml_get_table_value(current_table, path_parts[i]);
		if (!current_value)
		{
			LOG(LOG_WARNING, "Key '%s' not found in table", path_parts[i]);
			return (NULL);
		}
	}
	return (current_value);
}

// function who validates and parses a path
static char	**validate_and_parse_path(const char *path, int *part_count)
{
	char	**parts;

	if (!path || !part_count)
	{
		LOG(LOG_WARNING, "validate_and_parse_path: invalid parameters");
		return (NULL);
	}
	parts = ft_split(path, '.');
	if (!parts || !parts[0])
	{
		LOG(LOG_ERROR, "Failed to split path: %s", path);
		ft_free_double_ptr((void ***)&parts);
		return (NULL);
	}
	*part_count = 0;
	while (parts[*part_count])
		(*part_count)++;
	if (*part_count < 2)
	{
		LOG(LOG_WARNING, "Invalid path format (need at least section.key): %s",
			path);
		ft_free_double_ptr((void ***)&parts);
		return (NULL);
	}
	return (parts);
}

// function who finds section and key from path parts
static t_toml_kv	*find_section_and_key(t_toml_doc *doc, char **parts)
{
	t_toml_section	*section;
	t_toml_kv		*kv;
	char			*section_name;
	char			*key_name;

	if (!doc || !parts || !parts[0] || !parts[1])
		return (NULL);
	section_name = parts[0];
	key_name = parts[1];
	section = toml_find_section(doc, section_name);
	if (!section)
	{
		LOG(LOG_WARNING, "Section '%s' not found", section_name);
		return (NULL);
	}
	kv = toml_find_kv(section, key_name);
	if (!kv)
	{
		LOG(LOG_WARNING, "Key '%s' not found in section '%s'", key_name,
			section_name);
		return (NULL);
	}
	return (kv);
}

// function who handles nested path resolution
static t_toml_value	*resolve_nested_path(t_toml_kv *kv, char **parts,
		int part_count)
{
	t_toml_value	*nested_value;

	if (!kv || !parts || part_count <= 2)
		return (&kv->value);
	nested_value = get_nested_value(&kv->value, (const char **)&parts[2],
			part_count - 2);
	return (nested_value);
}

// function who gets a value from a document (supports complex paths)
t_toml_value	*toml_get_value(t_toml_doc *doc, const char *path)
{
	char			**parts;
	t_toml_kv		*kv;
	t_toml_value	*result;
	int				part_count;

	if (!doc || !path)
	{
		LOG(LOG_WARNING, "toml_get_value: invalid parameters");
		return (NULL);
	}
	LOG(LOG_DEBUG, "Getting value for path: %s", path);
	parts = validate_and_parse_path(path, &part_count);
	if (!parts)
		return (NULL);
	kv = find_section_and_key(doc, parts);
	if (!kv)
	{
		ft_free_double_ptr((void ***)&parts);
		return (NULL);
	}
	result = resolve_nested_path(kv, parts, part_count);
	ft_free_double_ptr((void ***)&parts);
	if (result)
		LOG(LOG_DEBUG, "Successfully retrieved value for path: %s", path);
	return (result);
}
