/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toml_parse_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:30:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/30 02:05:08 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

// function who extracts and validates the key from a line
static char	*extract_key(const char *line, const char *equal_pos)
{
	char	*key;
	char	*trimmed_key;

	key = ft_substr(line, 0, equal_pos - line);
	if (!key)
	{
		LOG(LOG_ERROR, "Failed to extract key from line: %s", line);
		return (NULL);
	}
	trimmed_key = ft_strtrim(key, " \t");
	free(key);
	if (!trimmed_key || ft_strlen(trimmed_key) == 0)
	{
		LOG(LOG_WARNING, "Empty key in line: %s", line);
		free(trimmed_key);
		return (NULL);
	}
	if (!is_valid_toml_key(trimmed_key))
	{
		LOG(LOG_WARNING, "Invalid key format: %s", trimmed_key);
		free(trimmed_key);
		return (NULL);
	}
	return (trimmed_key);
}

// function who extracts and validates the value from a line
static char	*extract_value(const char *equal_pos)
{
	char	*value_str;

	value_str = ft_strdup(equal_pos + 1);
	if (!value_str)
	{
		LOG(LOG_ERROR, "Failed to extract value from line");
		return (NULL);
	}
	value_str = ft_strtrim(value_str, " \t\n");
	return (value_str);
}

// function who creates a key-value pair
static t_toml_kv	*create_kv_pair(const char *key, const char *value_str)
{
	t_toml_kv	*kv;

	kv = ft_calloc(1, sizeof(t_toml_kv));
	if (!kv)
	{
		LOG(LOG_ERROR, "Failed to allocate memory for key-value pair");
		return (NULL);
	}
	kv->key = ft_strdup(key);
	kv->value = toml_parse_value(value_str);
	// Validate parsed value
	if (kv->value.type == TOML_STRING && !kv->value.data.str)
		LOG(LOG_WARNING, "Failed to parse value for key '%s': %s", key,
			value_str);
	else
		LOG(LOG_DEBUG, "Successfully parsed key-value pair: %s = ...", key);
	return (kv);
}

static char	*prepare_line_for_parsing(const char *line)
{
	char	*clean_line;
	char	*trimmed;

	clean_line = remove_inline_comment(line);
	if (!clean_line)
	{
		LOG(LOG_ERROR, "Failed to process line: %s", line);
		return (NULL);
	}
	trimmed = ft_strtrim(clean_line, " \t");
	free(clean_line);
	if (!trimmed || trimmed[0] == '\0')
	{
		free(trimmed);
		return (NULL);
	}
	return (trimmed);
}

static bool	is_section_line_format(const char *trimmed)
{
	size_t	len;

	len = ft_strlen(trimmed);
	return (trimmed[0] == '[' && trimmed[len - 1] == ']');
}

static t_toml_kv	*parse_key_value_pair(const char *trimmed)
{
	char		*equal_pos;
	char		*key;
	char		*value_str;
	t_toml_kv	*kv;

	equal_pos = ft_strchr(trimmed, '=');
	if (!equal_pos)
	{
		LOG(LOG_WARNING, "No '=' found in line: %s", trimmed);
		return (NULL);
	}
	key = extract_key(trimmed, equal_pos);
	if (!key)
		return (NULL);
	value_str = extract_value(equal_pos);
	if (!value_str)
	{
		free(key);
		return (NULL);
	}
	kv = create_kv_pair(key, value_str);
	free(key);
	free(value_str);
	return (kv);
}

t_toml_kv	*toml_parse_line(const char *line)
{
	char		*trimmed;
	t_toml_kv	*result;

	if (!line)
	{
		LOG(LOG_WARNING, "toml_parse_line: input line is NULL");
		return (NULL);
	}
	trimmed = prepare_line_for_parsing(line);
	if (!trimmed)
		return (NULL);
	LOG(LOG_DEBUG, "Parsing line: '%s'", trimmed);
	if (is_section_line_format(trimmed))
	{
		LOG(LOG_DEBUG, "Line is a section, skipping: %s", trimmed);
		free(trimmed);
		return (NULL);
	}
	result = parse_key_value_pair(trimmed);
	free(trimmed);
	return (result);
}
