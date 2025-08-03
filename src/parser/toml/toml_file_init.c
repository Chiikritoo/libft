/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toml_file_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 01:20:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/08/02 18:51:32 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function who initializes the TOML document
t_toml_doc	*init_toml_doc(void)
{
	t_toml_doc	*doc;

	doc = ft_calloc(1, sizeof(t_toml_doc));
	if (!doc)
	{
		LOG(LOG_ERROR, "Failed to allocate memory for TOML document");
		return (NULL);
	}
	doc->sections = NULL;
	doc->section_count = 0;
	return (doc);
}

// function who creates and adds the global section
bool	add_global_section(t_toml_doc *doc)
{
	t_toml_section	*global_section;

	global_section = toml_create_section("global");
	if (!global_section)
	{
		LOG(LOG_ERROR, "Failed to create global section");
		return (false);
	}
	doc->sections = ft_realloc(doc->sections, doc->section_count
			* sizeof(t_toml_section *), (doc->section_count + 1)
			* sizeof(t_toml_section *));
	if (!doc->sections)
	{
		LOG(LOG_ERROR, "Failed to allocate memory for sections array");
		toml_free_section(global_section);
		return (false);
	}
	doc->sections[doc->section_count] = global_section;
	doc->section_count++;
	LOG(LOG_DEBUG, "Created global section");
	return (true);
}

// function who finds an existing section by name
static t_toml_section	*find_existing_section(t_toml_doc *doc, const char *name)
{
	int	i;

	if (!doc || !name)
		return (NULL);
	i = 0;
	while (i < doc->section_count)
	{
		if (ft_strcmp(doc->sections[i]->name, name) == 0)
			return (doc->sections[i]);
		i++;
	}
	return (NULL);
}

// function who adds a section to the document
bool	add_section_to_doc(t_toml_doc *doc, t_toml_section *section)
{
	if (!doc || !section)
		return (false);
	doc->sections = ft_realloc(doc->sections, doc->section_count
			* sizeof(t_toml_section *), (doc->section_count + 1)
			* sizeof(t_toml_section *));
	if (!doc->sections)
	{
		LOG(LOG_ERROR, "Failed to reallocate sections array");
		return (false);
	}
	doc->sections[doc->section_count] = section;
	doc->section_count++;
	LOG(LOG_DEBUG, "Added section '%s' to document", section->name);
	return (true);
}

// function who handles array of tables sections
bool	handle_array_of_tables_section(t_toml_doc *doc, const char *section_name)
{
	t_toml_section	*existing_section;
	t_toml_section	*new_section;

	if (!doc || !section_name)
		return (false);
	existing_section = find_existing_section(doc, section_name);
	if (existing_section)
	{
		LOG(LOG_DEBUG, "Found existing section '%s', preparing for new table", 
			section_name);
		return (true);
	}
	new_section = toml_create_section(section_name);
	if (!new_section)
		return (false);
	new_section->is_array = true;
	return (add_section_to_doc(doc, new_section));
}

// function who gets a section by name from document
t_toml_section	*toml_get_section(t_toml_doc *doc, const char *name)
{
	if (!doc || !name)
		return (NULL);
	return (find_existing_section(doc, name));
}

// function who initializes document with file content
t_toml_doc	*init_doc_with_file(const char *filename, char ***lines)
{
	t_toml_doc	*doc;

	LOG(LOG_INFO, "Parsing TOML file: %s", filename);
	*lines = ft_get_file(filename);
	if (!*lines)
	{
		LOG(LOG_ERROR, "Failed to read file: %s", filename);
		return (NULL);
	}
	doc = init_toml_doc();
	if (!doc)
	{
		ft_free_double_ptr((void ***)lines);
		return (NULL);
	}
	if (!add_global_section(doc))
	{
		ft_free_double_ptr((void ***)lines);
		free(doc);
		return (NULL);
	}
	return (doc);
}
