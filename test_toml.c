/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_toml.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:30:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/15 10:30:00 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

// function who prints a TOML value
void	print_toml_value(t_toml_value *value)
{
	if (!value)
	{
		printf("(null)");
		return ;
	}
	switch (value->type)
	{
		case TOML_STRING:
			if (value->data.str)
				printf("\"%s\"", value->data.str);
			else
				printf("(null string)");
			break;
		case TOML_INT:
			printf("%d", value->data.num);
			break;
		case TOML_FLOAT:
			printf("%.1f", value->data.f);
			break;
		case TOML_BOOL:
			printf("%s", value->data.b ? "true" : "false");
			break;
		case TOML_ARRAY:
			if (value->data.array)
			{
				printf("[");
				for (size_t i = 0; i < value->data.array->size; i++)
				{
					if (i > 0)
						printf(", ");
					print_toml_value(value->data.array->values[i]);
				}
				printf("]");
			}
			else
				printf("(null array)");
			break;
		case TOML_TABLE:
			if (value->data.table)
			{
				printf("{");
				t_toml_table *current = value->data.table->next;
				int first = 1;
				while (current)
				{
					if (!first)
						printf(", ");
					printf("%s = ", current->key);
					print_toml_value(current->value);
					current = current->next;
					first = 0;
				}
				printf("}");
			}
			else
				printf("(null table)");
			break;
	}
}

int	main(void)
{
	t_toml_doc	*doc;

	// Parse the config file
	doc = toml_parse_file("test_config.toml");
	if (!doc)
	{
		printf("Error: Could not parse TOML file\n");
		return (1);
	}

	printf("=== TOML File Content ===\n\n");

	// Print all sections and their content
	for (int i = 0; i < doc->section_count; i++)
	{
		t_toml_section *section = doc->sections[i];
		printf("[%s]\n", section->name);
		
		for (int j = 0; j < section->count; j++)
		{
			t_toml_kv *kv = section->kv[j];
			printf("  %s = ", kv->key);
			print_toml_value(&kv->value);
			printf("\n");
		}
		printf("\n");
	}

	// Print summary
	printf("=== Summary ===\n");
	printf("Total sections: %d\n", doc->section_count);
	
	int total_kv = 0;
	for (int i = 0; i < doc->section_count; i++)
		total_kv += doc->sections[i]->count;
	printf("Total key-value pairs: %d\n", total_kv);
	printf("Parser status: SUCCESS\n");

	// Clean up
	toml_free_doc(doc);

	return (0);
} 
 