/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toml_parse_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:30:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/29 14:00:27 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

// function who parses a TOML line (section or key-value)
t_toml_kv	*toml_parse_line(const char *line)
{
	t_toml_kv	*kv;
	char		*trimmed;
	char		*equal_pos;
	char		*key;
	char		*value_str;

	if (!line)
		return (NULL);
	trimmed = ft_strtrim(line, " \t");
	if (!trimmed || trimmed[0] == '\0' || trimmed[0] == '#')
	{
		free(trimmed);
		return (NULL);
	}
	// Check if it's a section [section]
	if (trimmed[0] == '[' && trimmed[ft_strlen(trimmed) - 1] == ']')
	{
		free(trimmed);
		return (NULL); // Sections are handled separately
	}
	// Parse key-value pair
	equal_pos = ft_strchr(trimmed, '=');
	if (!equal_pos)
	{
		free(trimmed);
		return (NULL);
	}
	// Extract key
	key = ft_substr(trimmed, 0, equal_pos - trimmed);
	key = ft_strtrim(key, " \t");
	// Extract value
	value_str = ft_strdup(equal_pos + 1);
	value_str = ft_strtrim(value_str, " \t\n");
	// Create key-value pair
	kv = ft_calloc(1, sizeof(t_toml_kv));
	if (!kv)
	{
		free(key);
		free(value_str);
		free(trimmed);
		return (NULL);
	}
	kv->key = key;
	kv->value = toml_parse_value(value_str);
	free(value_str);
	free(trimmed);
	return (kv);
} 
