/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toml_line_processing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 01:20:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/30 02:08:43 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	section = toml_create_section(section_name);
	if (!section)
	{
		LOG(LOG_ERROR, "Failed to create section '%s' at line %d", section_name,
			line_num);
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
	LOG(LOG_DEBUG, "Created section '%s' at line %d", section_name, line_num);
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
}
