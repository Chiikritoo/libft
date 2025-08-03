/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toml.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:26:32 by anchikri          #+#    #+#             */
/*   Updated: 2025/08/02 18:51:28 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOML_H
# define TOML_H

# include "libft.h"

typedef enum e_toml_type
{
	TOML_STRING,
	TOML_INT,
	TOML_FLOAT,
	TOML_BOOL,
	TOML_ARRAY,
	TOML_TABLE
}					t_toml_type;

typedef struct s_toml_value	t_toml_value;

typedef struct s_toml_array
{
	t_toml_value	**values;
	size_t			size;
	t_toml_type		element_type;
}					t_toml_array;

typedef struct s_toml_table
{
	char			*key;
	t_toml_value	*value;
	struct s_toml_table	*next;
}					t_toml_table;

typedef struct s_toml_value
{
	t_toml_type		type;
	union
	{
		char		*str;
		int			num;
		double		f;
		bool		b;
		t_toml_array	*array;
		t_toml_table	*table;
	} data;
}					t_toml_value;

typedef struct s_toml_kv
{
	char			*key;
	t_toml_value	value;
}					t_toml_kv;

typedef struct s_toml_section
{
	char			*name;
	t_toml_kv		**kv;
	int				count;
	bool			is_array;
	t_toml_kv		***table_array;
	int				*table_counts;
	int				table_array_size;
}					t_toml_section;

typedef struct s_toml_doc
{
	t_toml_section	**sections;
	int				section_count;
}					t_toml_doc;

/* ************************************************************************** */
/*                              TOML FUNCTIONS                                */
/* ************************************************************************** */

// Parsing functions
t_toml_value		toml_parse_value(const char *str);
t_toml_kv			*toml_parse_line(const char *line);
char				*toml_parse_section_name(const char *line);
t_toml_section		*toml_create_section(const char *name);
int					toml_add_kv_to_section(t_toml_section *section,
						t_toml_kv *kv);
bool				toml_add_table_to_array_section(t_toml_section *section,
						t_toml_kv **table_kv, int table_count);
t_toml_doc			*toml_parse_file(const char *filename);

// Array functions
t_toml_array		*toml_create_array(t_toml_type element_type);
int				toml_add_to_array(t_toml_array *array, t_toml_value value);
t_toml_value		*toml_get_array_value(t_toml_array *array, size_t index);
t_toml_array		*toml_parse_array(const char *str);

// Table functions
t_toml_table		*toml_create_table(const char *key);
int				toml_add_to_table(t_toml_table *table, const char *key, t_toml_value value);
t_toml_value		*toml_get_table_value(t_toml_table *table, const char *key);
t_toml_table		*toml_parse_table(const char *str);

// Getter functions
t_toml_value		*toml_get_value(t_toml_doc *doc, const char *path);
t_toml_section		*toml_get_section(t_toml_doc *doc, const char *section_name);

// Helper functions
int					toml_get_int(t_toml_doc *doc, const char *path,
						int default_val);
double				toml_get_float(t_toml_doc *doc, const char *path,
						double default_val);
char				*toml_get_string(t_toml_doc *doc, const char *path,
						const char *default_val);
bool				toml_get_bool(t_toml_doc *doc, const char *path,
						bool default_val);

// Advanced parsing functions
char				**ft_split_array_elements(const char *str);
char				**ft_split_table_pairs(const char *str);
char				*toml_value_to_string(t_toml_value *value);

// Utility functions
bool				is_toml_date(const char *str);
bool				is_valid_toml_key(const char *key);
char				*remove_inline_comment(const char *str);
char				*parse_toml_string(const char *str);

// Value type detection and creation
bool				is_array_format(const char *str);
bool				is_table_format(const char *str);
bool				is_number_format(const char *str);
t_toml_value		create_array_value(const char *str);
t_toml_value		create_table_value(const char *str);
t_toml_value		create_number_or_string_value(const char *str);
t_toml_value		toml_dispatch_value_parsing(const char *str);

// Value parsing functions
bool				parse_float(const char *str, t_toml_value *value);
bool				parse_integer(const char *str, t_toml_value *value);
bool				parse_number(const char *str, t_toml_value *value);
bool				parse_boolean(const char *str, t_toml_value *value);
bool				parse_string_value(const char *str, t_toml_value *value);

// Document initialization functions
t_toml_doc			*init_toml_doc(void);
bool				add_global_section(t_toml_doc *doc);
bool				add_section_to_doc(t_toml_doc *doc, t_toml_section *section);
bool				handle_array_of_tables_section(t_toml_doc *doc, 
						const char *section_name);
t_toml_section		*toml_get_section(t_toml_doc *doc, const char *name);
t_toml_doc			*init_doc_with_file(const char *filename, char ***lines);

// Line processing functions
bool				should_skip_line(const char *clean_line);
bool				is_section_line(const char *clean_line);
bool				is_kv_line(const char *clean_line);
t_toml_section		*process_section_line(t_toml_doc *doc, const char *line, int line_num);
bool				process_kv_line(t_toml_section *current_section, const char *line, int line_num);
void				process_all_lines(t_toml_doc *doc, char **lines);
t_toml_section		*process_single_line(t_toml_doc *doc, t_toml_section *current_section, const char *line, int line_num);

// Structure parsing functions
t_toml_array		*toml_parse_array(const char *str);
t_toml_table		*toml_parse_table(const char *str);

// Free functions
void				toml_free_value(t_toml_value *value);
void				toml_free_kv(t_toml_kv *kv);
void				toml_free_section(t_toml_section *section);
void				toml_free_doc(t_toml_doc *doc);
void				toml_free_array(t_toml_array *array);
void				toml_free_table(t_toml_table *table);

#endif
