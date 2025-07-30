/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toml_string_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 01:15:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/30 02:04:35 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

// function who counts elements in a string for splitting
static int	count_elements(const char *str)
{
	int		count;
	int		depth;
	int		i;
	bool	in_quotes;

	if (!str)
		return (0);
	count = 1;
	depth = 0;
	in_quotes = false;
	i = 0;
	while (str[i])
	{
		if (str[i] == '"' && (i == 0 || str[i - 1] != '\\'))
			in_quotes = !in_quotes;
		else if (!in_quotes)
		{
			if (str[i] == '[' || str[i] == '{')
				depth++;
			else if (str[i] == ']' || str[i] == '}')
				depth--;
			else if (str[i] == ',' && depth == 0)
				count++;
		}
		i++;
	}
	return (count);
}

// function who allocates result array
static char	**allocate_result_array(int count)
{
	char	**result;

	result = ft_calloc(count + 1, sizeof(char *));
	if (!result)
	{
		LOG(LOG_ERROR, "Failed to allocate result array");
		return (NULL);
	}
	return (result);
}

// function who extracts element from position
static char	*extract_element(const char *str, int start, int end)
{
	char	*element;

	if (start >= end)
		return (ft_strdup(""));
	element = ft_substr(str, start, end - start);
	if (!element)
	{
		LOG(LOG_ERROR, "Failed to extract element");
		return (NULL);
	}
	return (ft_strtrim(element, " \t"));
}

static char	**process_array_elements(const char *str, char **result, int count)
{
	int		i;
	int		start;
	int		depth;
	bool	in_quotes;
	int		result_index;

	i = 0;
	start = 0;
	depth = 0;
	in_quotes = false;
	result_index = 0;
	while (str[i] && result_index < count)
	{
		if (str[i] == '"' && (i == 0 || str[i - 1] != '\\'))
			in_quotes = !in_quotes;
		else if (!in_quotes)
		{
			if (str[i] == '[' || str[i] == '{')
				depth++;
			else if (str[i] == ']' || str[i] == '}')
				depth--;
			else if (str[i] == ',' && depth == 0)
			{
				result[result_index] = extract_element(str, start, i);
				if (!result[result_index])
				{
					ft_free_double_ptr((void ***)&result);
					return (NULL);
				}
				result_index++;
				start = i + 1;
			}
		}
		i++;
	}
	if (result_index < count)
		result[result_index] = extract_element(str, start, i);
	return (result);
}

// function who splits array elements respecting nested structures
char	**ft_split_array_elements(const char *str)
{
	char	**result;
	int		count;

	if (!str)
		return (NULL);
	count = count_elements(str);
	result = allocate_result_array(count);
	if (!result)
		return (NULL);
	return (process_array_elements(str, result, count));
}

// function who splits table pairs respecting nested structures
char	**ft_split_table_pairs(const char *str)
{
	return (ft_split_array_elements(str));
}
