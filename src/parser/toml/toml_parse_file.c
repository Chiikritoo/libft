/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toml_parse_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:30:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/15 10:30:00 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

// function who parses a complete TOML file
t_toml_doc	*toml_parse_file(const char *filename)
{
	t_toml_doc		*doc;
	char		**lines;
	int			i;
	char		*section_name;
	t_toml_section	*current_section;
	t_toml_kv		*kv;

	if (!filename)
		return (NULL);
	lines = ft_get_file(filename);
	if (!lines)
		return (NULL);
	doc = ft_calloc(1, sizeof(t_toml_doc));
	if (!doc)
	{
		ft_free_double_ptr((void ***)&lines);
		return (NULL);
	}
	doc->sections = NULL;
	doc->section_count = 0;
	current_section = NULL;
	
	// Create global section for values outside sections
	t_toml_section *global_section = toml_create_section("global");
	if (global_section)
	{
		doc->sections = ft_realloc(doc->sections,
			doc->section_count * sizeof(t_toml_section *),
			(doc->section_count + 1) * sizeof(t_toml_section *));
		if (doc->sections)
		{
			doc->sections[doc->section_count] = global_section;
			doc->section_count++;
			current_section = global_section;
		}
	}
	i = 0;
	while (lines[i])
	{
		// Check if it's a section
		section_name = toml_parse_section_name(lines[i]);
		if (section_name)
		{
			current_section = toml_create_section(section_name);
			if (!current_section)
			{
				free(section_name);
				continue;
			}
			// Add section to document
			doc->sections = ft_realloc(doc->sections,
				doc->section_count * sizeof(t_toml_section *),
				(doc->section_count + 1) * sizeof(t_toml_section *));
			if (!doc->sections)
			{
				free(section_name);
				continue;
			}
			doc->sections[doc->section_count] = current_section;
			doc->section_count++;
			free(section_name);
		}
		// Check if it's a key-value pair
		else
		{
			kv = toml_parse_line(lines[i]);
			if (kv && current_section)
				toml_add_kv_to_section(current_section, kv);
		}
		i++;
	}
	ft_free_double_ptr((void ***)&lines);
	return (doc);
} 
 