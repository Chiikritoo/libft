/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toml_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:30:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/15 10:30:00 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function who gets an integer value with default
int	toml_get_int(t_toml_doc *doc, const char *path, int default_val)
{
	t_toml_value	*value;

	if (!doc || !path)
		return (default_val);
	value = toml_get_value(doc, path);
	if (!value || value->type != TOML_INT)
		return (default_val);
	return (value->data.num);
}

// function who gets a float value with default
double	toml_get_float(t_toml_doc *doc, const char *path, double default_val)
{
	t_toml_value	*value;

	if (!doc || !path)
		return (default_val);
	value = toml_get_value(doc, path);
	if (!value || value->type != TOML_FLOAT)
		return (default_val);
	return (value->data.f);
}

// function who gets a string value with default
char	*toml_get_string(t_toml_doc *doc, const char *path,
		const char *default_val)
{
	t_toml_value	*value;

	if (!doc || !path)
		return (ft_strdup(default_val));
	value = toml_get_value(doc, path);
	if (!value || value->type != TOML_STRING)
		return (ft_strdup(default_val));
	return (ft_strdup(value->data.str));
}

// function who gets a boolean value with default
bool	toml_get_bool(t_toml_doc *doc, const char *path, bool default_val)
{
	t_toml_value	*value;

	if (!doc || !path)
		return (default_val);
	value = toml_get_value(doc, path);
	if (!value || value->type != TOML_BOOL)
		return (default_val);
	return (value->data.b);
}
