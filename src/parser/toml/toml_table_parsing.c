/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toml_table_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 01:15:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/30 02:08:43 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function who validates and extracts table content
static char	*validate_and_extract_table_content(const char *str)
{
	char	*content;
	size_t	len;

	if (!str || ft_strlen(str) < 2)
	{
		LOG(LOG_WARNING, "Invalid table format (too short): %s",
			str ? str : "(null)");
		return (NULL);
	}
	len = ft_strlen(str);
	if (str[0] != '{' || str[len - 1] != '}')
	{
		LOG(LOG_WARNING, "Invalid table format (missing braces): %s", str);
		return (NULL);
	}
	content = ft_substr(str, 1, len - 2);
	if (!content)
	{
		LOG(LOG_ERROR, "Failed to extract table content from: %s", str);
		return (NULL);
	}
	return (ft_strtrim(content, " \t"));
}

// function who processes a single table pair
static bool	process_table_pair(t_toml_table *table, const char *pair)
{
	char			*equal_pos;
	char			*key;
	char			*value_str;
	char			*trimmed_key;
	char			*trimmed_value;
	t_toml_value	parsed_value;

	if (!table || !pair)
		return (false);
	equal_pos = ft_strchr(pair, '=');
	if (!equal_pos)
	{
		LOG(LOG_WARNING, "No '=' found in table pair: %s", pair);
		return (false);
	}
	key = ft_substr(pair, 0, equal_pos - pair);
	value_str = ft_strdup(equal_pos + 1);
	if (!key || !value_str)
	{
		free(key);
		free(value_str);
		return (false);
	}
	trimmed_key = ft_strtrim(key, " \t");
	trimmed_value = ft_strtrim(value_str, " \t");
	free(key);
	free(value_str);
	if (!trimmed_key || !trimmed_value)
	{
		free(trimmed_key);
		free(trimmed_value);
		return (false);
	}
	parsed_value = toml_parse_value(trimmed_value);
	if (toml_add_to_table(table, trimmed_key, parsed_value) == 0)
	{
		free(trimmed_key);
		free(trimmed_value);
		return (false);
	}
	free(trimmed_key);
	free(trimmed_value);
	return (true);
}

// function who processes all table pairs
static bool	process_table_pairs(t_toml_table *table, char **pairs)
{
	int	i;

	if (!table || !pairs)
		return (false);
	i = 0;
	while (pairs[i])
	{
		if (!process_table_pair(table, pairs[i]))
			return (false);
		i++;
	}
	return (true);
}

// function who parses a TOML table from a string
t_toml_table	*toml_parse_table(const char *str)
{
	t_toml_table	*table;
	char			*content;
	char			**pairs;

	LOG(LOG_DEBUG, "Parsing table: %s", str ? str : "(null)");
	content = validate_and_extract_table_content(str);
	if (!content)
		return (NULL);
	table = toml_create_table("table");
	if (!table)
	{
		LOG(LOG_ERROR, "Failed to create table");
		free(content);
		return (NULL);
	}
	if (ft_strlen(content) == 0)
	{
		LOG(LOG_DEBUG, "Empty table");
		free(content);
		return (table);
	}
	pairs = ft_split_table_pairs(content);
	free(content);
	if (!pairs)
	{
		LOG(LOG_ERROR, "Failed to split table pairs");
		toml_free_table(table);
		return (NULL);
	}
	if (!process_table_pairs(table, pairs))
	{
		ft_free_double_ptr((void ***)&pairs);
		toml_free_table(table);
		return (NULL);
	}
	ft_free_double_ptr((void ***)&pairs);
	LOG(LOG_DEBUG, "Successfully parsed table");
	return (table);
}
