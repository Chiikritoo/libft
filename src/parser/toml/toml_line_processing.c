/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toml_line_processing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 01:20:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/08/02 18:56:07 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function who finalizes current table in array section
static bool	finalize_array_table(t_toml_section *section)
{
	t_toml_kv	**table_kv;
	int			i;

	if (!section || !section->is_array || section->count == 0)
		return (true);
	
	// Copy current kv pairs to create a new table
	table_kv = ft_calloc(section->count, sizeof(t_toml_kv *));
	if (!table_kv)
		return (false);
	
	i = 0;
	while (i < section->count)
	{
		table_kv[i] = section->kv[i];
		i++;
	}
	
	// Add the table to the array
	if (!toml_add_table_to_array_section(section, table_kv, section->count))
	{
		free(table_kv);
		return (false);
	}
	
	// Reset current kv pairs for next table
	free(section->kv);
	section->kv = NULL;
	section->count = 0;
	
	return (true);
}
// function who checks if a line should be skipped
bool	should_skip_line(const char *clean_line)
{
	if (!clean_line || ft_strlen(clean_line) == 0)
		return (true);
	return (clean_line[0] == '#');
}

// function who checks if a line is a section header
bool	is_section_line(const char *clean_line)
{
	size_t	len;

	if (!clean_line)
		return (false);
	len = ft_strlen(clean_line);
	return (len >= 3 && clean_line[0] == '[' && clean_line[len - 1] == ']');
}

// function who checks if a line is a key-value pair
bool	is_kv_line(const char *clean_line)
{
	if (!clean_line)
		return (false);
	return (ft_strchr(clean_line, '=') != NULL);
}

// function who processes a section line
t_toml_section	*process_section_line(t_toml_doc *doc, const char *line,
		int line_num)
{
	char			*section_name;
	t_toml_section	*section;

	section_name = toml_parse_section_name(line);
	if (!section_name)
	{
		LOG(LOG_WARNING, "Invalid section format at line %d: %s", line_num,
			line);
		return (NULL);
	}
	
	// Check if it's an array of tables [[name]]
	char *trimmed_line = ft_strtrim(line, " \t");
	bool is_array_of_tables = (ft_strlen(trimmed_line) >= 4 && 
		trimmed_line[0] == '[' && trimmed_line[1] == '[' && 
		trimmed_line[ft_strlen(trimmed_line) - 1] == ']' && 
		trimmed_line[ft_strlen(trimmed_line) - 2] == ']');
	free(trimmed_line);
	
	if (is_array_of_tables)
	{
		if (!handle_array_of_tables_section(doc, section_name))
		{
			LOG(LOG_ERROR, "Failed to handle array of tables '%s' at line %d", 
				section_name, line_num);
			free(section_name);
			return (NULL);
		}
		section = toml_get_section(doc, section_name);
		if (section && section->is_array)
		{
			// Finalize previous table in this array
			if (!finalize_array_table(section))
			{
				LOG(LOG_ERROR, "Failed to finalize array table at line %d", line_num);
				free(section_name);
				return (NULL);
			}
		}
		LOG(LOG_DEBUG, "Processing array of tables '%s' at line %d", 
			section_name, line_num);
	}
	else
	{
		section = toml_create_section(section_name);
		if (!section)
		{
			LOG(LOG_ERROR, "Failed to create section '%s' at line %d", 
				section_name, line_num);
			free(section_name);
			return (NULL);
		}
		if (!add_section_to_doc(doc, section))
		{
			LOG(LOG_ERROR, "Failed to add section '%s' to document", section_name);
			toml_free_section(section);
			free(section_name);
			return (NULL);
		}
		LOG(LOG_DEBUG, "Created regular section '%s' at line %d", 
			section_name, line_num);
	}
	
	free(section_name);
	return (section);
}

// function who processes a key-value line
bool	process_kv_line(t_toml_section *current_section, const char *line,
		int line_num)
{
	t_toml_kv	*kv;

	if (!current_section)
	{
		LOG(LOG_WARNING, "Key-value pair outside section at line %d: %s",
			line_num, line);
		return (false);
	}
	kv = toml_parse_line(line);
	if (!kv)
	{
		LOG(LOG_WARNING, "Failed to parse key-value pair at line %d: %s",
			line_num, line);
		return (false);
	}
	current_section->kv = ft_realloc(current_section->kv, current_section->count
			* sizeof(t_toml_kv *), (current_section->count + 1)
			* sizeof(t_toml_kv *));
	if (!current_section->kv)
	{
		LOG(LOG_ERROR, "Failed to allocate memory for key-value pairs");
		toml_free_kv(kv);
		return (false);
	}
	current_section->kv[current_section->count] = kv;
	current_section->count++;
	LOG(LOG_DEBUG, "Added key-value pair '%s' to section '%s' at line %d",
		kv->key, current_section->name, line_num);
	return (true);
}

// function who processes all lines in the file
void	process_all_lines(t_toml_doc *doc, char **lines)
{
	t_toml_section	*current_section;
	int				i;

	current_section = doc->sections[0];
	i = 0;
	while (lines[i])
	{
		current_section = process_single_line(doc, current_section, lines[i], i
				+ 1);
		i++;
	}
	
	// Finalize any remaining array table
	if (current_section && current_section->is_array)
	{
		finalize_array_table(current_section);
	}
}
