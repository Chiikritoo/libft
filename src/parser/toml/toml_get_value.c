/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toml_get_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:30:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/15 10:30:00 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

// function who finds a section by name
static t_toml_section	*toml_find_section(t_toml_doc *doc, const char *section_name)
{
	int	i;

	if (!doc || !section_name)
		return (NULL);
	i = 0;
	while (i < doc->section_count)
	{
		if (ft_strcmp(doc->sections[i]->name, section_name) == 0)
			return (doc->sections[i]);
		i++;
	}
	return (NULL);
}

// function who finds a key-value pair by key in a section
static t_toml_kv	*toml_find_kv(t_toml_section *section, const char *key)
{
	int	i;

	if (!section || !key)
		return (NULL);
	i = 0;
	while (i < section->count)
	{
		if (ft_strcmp(section->kv[i]->key, key) == 0)
			return (section->kv[i]);
		i++;
	}
	return (NULL);
}

// function who gets a value from a document (section.key format)
t_toml_value	*toml_get_value(t_toml_doc *doc, const char *path)
{
	t_toml_section	*section;
	t_toml_kv		*kv;
	char		**parts;
	char		*section_name;
	char		*key_name;

	if (!doc || !path)
		return (NULL);
	parts = ft_split(path, '.');
	if (!parts || !parts[0] || !parts[1])
	{
		ft_free_double_ptr((void ***)&parts);
		return (NULL);
	}
	section_name = parts[0];
	key_name = parts[1];
	section = toml_find_section(doc, section_name);
	if (!section)
	{
		ft_free_double_ptr((void ***)&parts);
		return (NULL);
	}
	kv = toml_find_kv(section, key_name);
	ft_free_double_ptr((void ***)&parts);
	if (!kv)
		return (NULL);
	return (&kv->value);
} 
