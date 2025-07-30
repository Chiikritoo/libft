/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toml_parse_section.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:30:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/30 02:08:43 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function who checks if a line is an array of tables section
static bool	is_array_of_tables(const char *trimmed)
{
	size_t	len;

	if (!trimmed)
		return (false);
	len = ft_strlen(trimmed);
	return (len >= 4 && trimmed[0] == '[' && trimmed[1] == '[' && trimmed[len
		- 1] == ']' && trimmed[len - 2] == ']');
}

// function who checks if a line is a regular section
static bool	is_regular_section(const char *trimmed)
{
	size_t	len;

	if (!trimmed)
		return (false);
	len = ft_strlen(trimmed);
	return (len >= 3 && trimmed[0] == '[' && trimmed[1] != '[' && trimmed[len
		- 1] == ']' && trimmed[len - 2] != ']');
}

// function who extracts section name from array of tables format
static char	*extract_array_section_name(const char *trimmed)
{
	char	*name;
	size_t	len;
	char	*trimmed_name;

	len = ft_strlen(trimmed);
	if (len < 4)
		return (NULL);
	name = ft_substr(trimmed, 2, len - 4);
	if (!name)
		return (NULL);
	trimmed_name = ft_strtrim(name, " \t");
	free(name);
	return (trimmed_name);
}

// function who extracts section name from regular section format
static char	*extract_regular_section_name(const char *trimmed)
{
	char	*name;
	size_t	len;
	char	*trimmed_name;

	len = ft_strlen(trimmed);
	if (len < 3)
		return (NULL);
	name = ft_substr(trimmed, 1, len - 2);
	if (!name)
		return (NULL);
	trimmed_name = ft_strtrim(name, " \t");
	free(name);
	return (trimmed_name);
}

// function who parses a TOML section name from a line
char	*toml_parse_section_name(const char *line)
{
	char	*trimmed;
	char	*section_name;

	if (!line)
		return (NULL);
	trimmed = ft_strtrim(line, " \t");
	if (!trimmed)
		return (NULL);
	LOG(LOG_DEBUG, "Parsing section name from: %s", trimmed);
	if (is_array_of_tables(trimmed))
	{
		section_name = extract_array_section_name(trimmed);
		LOG(LOG_DEBUG, "Extracted array section name: %s", section_name);
	}
	else if (is_regular_section(trimmed))
	{
		section_name = extract_regular_section_name(trimmed);
		LOG(LOG_DEBUG, "Extracted regular section name: %s", section_name);
	}
	else
	{
		LOG(LOG_WARNING, "Invalid section format: %s", trimmed);
		section_name = NULL;
	}
	free(trimmed);
	return (section_name);
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
		if (current->key && ft_strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}
