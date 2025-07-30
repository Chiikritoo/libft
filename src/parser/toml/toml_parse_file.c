/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toml_parse_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:30:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/30 02:08:43 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function who processes a single line
t_toml_section	*process_single_line(t_toml_doc *doc,
		t_toml_section *current_section, const char *line, int line_num)
{
	char			*clean_line;
	t_toml_section	*new_section;

	clean_line = ft_strtrim(line, " \t\n");
	if (!clean_line)
		return (current_section);
	if (should_skip_line(clean_line))
	{
		free(clean_line);
		return (current_section);
	}
	if (is_section_line(clean_line))
	{
		new_section = process_section_line(doc, clean_line, line_num);
		free(clean_line);
		if (new_section)
			return (new_section);
		return (current_section);
	}
	if (is_kv_line(clean_line))
		process_kv_line(current_section, clean_line, line_num);
	else
		LOG(LOG_WARNING, "Unrecognized line format at line %d: %s", line_num,
			clean_line);
	free(clean_line);
	return (current_section);
}

// function who parses a complete TOML file
t_toml_doc	*toml_parse_file(const char *filename)
{
	t_toml_doc	*doc;
	char		**lines;

	if (!filename)
	{
		LOG(LOG_ERROR, "toml_parse_file: filename is NULL");
		return (NULL);
	}
	doc = init_doc_with_file(filename, &lines);
	if (!doc)
		return (NULL);
	process_all_lines(doc, lines);
	ft_free_double_ptr((void ***)&lines);
	LOG(LOG_INFO, "Successfully parsed TOML file with %d sections",
		doc->section_count);
	return (doc);
}
