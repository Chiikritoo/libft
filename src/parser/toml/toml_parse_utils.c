/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toml_parse_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 01:10:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/30 02:08:43 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function who checks if a string is a valid TOML date
bool	is_toml_date(const char *str)
{
	int	i;
	int	dash_count;
	int	colon_count;
	int	t_count;

	if (!str || ft_strlen(str) < 10)
		return (false);
	dash_count = 0;
	colon_count = 0;
	t_count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			dash_count++;
		else if (str[i] == ':')
			colon_count++;
		else if (str[i] == 'T' || str[i] == 't')
			t_count++;
		else if (!ft_isdigit(str[i]) && str[i] != '.' && str[i] != 'Z'
			&& str[i] != '+' && str[i] != '-')
			return (false);
		i++;
	}
	return (dash_count >= 2 && (t_count == 0 || (t_count == 1
				&& colon_count >= 2)));
}

// function who validates a TOML key
bool	is_valid_toml_key(const char *key)
{
	int	i;

	if (!key || ft_strlen(key) == 0)
		return (false);
	i = 0;
	while (key[i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_' && key[i] != '-'
			&& key[i] != '.')
		{
			LOG(LOG_WARNING, "Invalid character in key '%s': '%c'", key,
				key[i]);
			return (false);
		}
		i++;
	}
	return (true);
}

// function who removes inline comments from a string
char	*remove_inline_comment(const char *str)
{
	char	*result;
	int		i;
	bool	in_quotes;
	char	*trimmed;

	if (!str)
		return (NULL);
	result = ft_strdup(str);
	if (!result)
		return (NULL);
	in_quotes = false;
	i = 0;
	while (result[i])
	{
		if (result[i] == '"' && (i == 0 || result[i - 1] != '\\'))
			in_quotes = !in_quotes;
		else if (result[i] == '#' && !in_quotes)
		{
			result[i] = '\0';
			break ;
		}
		i++;
	}
	trimmed = ft_strtrim(result, " \t");
	free(result);
	return (trimmed);
}

// function who parses a TOML string with proper quote handling
char	*parse_toml_string(const char *str)
{
	char	*result;
	size_t	len;
	bool	is_quoted;
	size_t	result_len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	is_quoted = (str[0] == '"' && str[len - 1] == '"');
	if (is_quoted)
	{
		result = ft_substr(str, 1, len - 2);
		if (!result)
		{
			LOG(LOG_ERROR, "Failed to allocate memory for quoted string");
			return (NULL);
		}
	}
	else
	{
		result = ft_strdup(str);
		if (!result)
		{
			LOG(LOG_ERROR, "Failed to allocate memory for string");
			return (NULL);
		}
	}
	if (result && ft_strlen(result) > 0)
	{
		result_len = ft_strlen(result);
		if (result[result_len - 1] == '\n')
			result[result_len - 1] = '\0';
	}
	return (result);
}

// function who converts a TOML value to string representation
char	*toml_value_to_string(t_toml_value *value)
{
	char	*result;
	char	*temp;

	if (!value)
		return (ft_strdup("(null)"));
	switch (value->type)
	{
	case TOML_STRING:
		if (value->data.str)
			return (ft_strdup(value->data.str));
		return (ft_strdup(""));
	case TOML_INT:
		temp = ft_itoa(value->data.num);
		return (temp);
	case TOML_FLOAT:
		result = ft_calloc(32, sizeof(char));
		if (!result)
			return (NULL);
		snprintf(result, 32, "%.6f", value->data.f);
		return (result);
	case TOML_BOOL:
		return (ft_strdup(value->data.b ? "true" : "false"));
	case TOML_ARRAY:
		return (ft_strdup("[array]"));
	case TOML_TABLE:
		return (ft_strdup("{table}"));
	default:
		return (ft_strdup("(unknown)"));
	}
}
