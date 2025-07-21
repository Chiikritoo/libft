/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:42:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/22 00:46:58 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JSON_H
# define JSON_H

# include "libft.h"

/* ************************************************************************** */
/*                              TYPE DEFINITIONS                               */
/* ************************************************************************** */

typedef enum e_token_type
{
	TOKEN_STRING,
	TOKEN_NUMBER,
	TOKEN_BOOL,
	TOKEN_NULL,
	TOKEN_LBRACE,    // {
	TOKEN_RBRACE,    // }
	TOKEN_LBRACKET,  // [
	TOKEN_RBRACKET,  // ]
	TOKEN_COLON,     // :
	TOKEN_COMMA,     // ,
	TOKEN_EOF,
	TOKEN_ERROR
}	t_token_type;

typedef enum e_json_type
{
	JSON_OBJECT,
	JSON_ARRAY,
	JSON_STRING,
	JSON_NUMBER,
	JSON_BOOL,
	JSON_NULL
}	t_json_type;

typedef enum e_json_error
{
	JSON_SUCCESS = 0,
	JSON_ERROR_NULL_PTR,
	JSON_ERROR_MEMORY_ALLOCATION,
	JSON_ERROR_INVALID_SYNTAX,
	JSON_ERROR_UNEXPECTED_TOKEN,
	JSON_ERROR_UNTERMINATED_STRING,
	JSON_ERROR_INVALID_ESCAPE,
	JSON_ERROR_INVALID_NUMBER,
	JSON_ERROR_INVALID_OPERATION,
	JSON_ERROR_FILE_IO
}	t_json_error;

typedef struct s_token
{
	t_token_type	type;
	t_value		value;
	size_t		line;
	size_t		column;
}	t_token;

typedef struct s_json_node	t_json_node;
typedef struct s_json_lexer	t_json_lexer;
typedef struct s_json_parser	t_json_parser;

struct s_json_node
{
	t_json_type	type;
	t_value		value;
	t_vector	*children;
	t_json_node	*parent;
	char		*key;
};

struct s_json_lexer
{
	const char	*input;
	size_t		position;
	size_t		line;
	size_t		column;
	t_token		current_token;
};

struct s_json_parser
{
	t_json_lexer	*lexer;
	t_json_error	last_error;
	char		*error_message;
	size_t		error_line;
	size_t		error_column;
};

/* ************************************************************************** */
/*                              LEXER FUNCTIONS                                */
/* ************************************************************************** */

/**
 * @brief Creates a new JSON lexer
 * @param input The input string to tokenize
 * @return Pointer to the new lexer, NULL on failure
 */
t_json_lexer	*json_lexer_new(const char *input);

/**
 * @brief Destroys a JSON lexer
 * @param lexer The lexer to destroy
 */
void		json_lexer_destroy(t_json_lexer *lexer);

/**
 * @brief Gets the next token from the lexer
 * @param lexer The lexer to use
 * @return The next token
 */
t_token		json_get_next_token(t_json_lexer *lexer);

/**
 * @brief Peeks at the next token without consuming it
 * @param lexer The lexer to use
 * @return The next token
 */
t_token		json_peek_token(t_json_lexer *lexer);

/**
 * @brief Skips whitespace characters
 * @param lexer The lexer to use
 */
void		json_skip_whitespace(t_json_lexer *lexer);

/* ************************************************************************** */
/*                              PARSER FUNCTIONS                               */
/* ************************************************************************** */

/**
 * @brief Creates a new JSON parser
 * @param input The input string to parse
 * @return Pointer to the new parser, NULL on failure
 */
t_json_parser	*json_parser_new(const char *input);

/**
 * @brief Destroys a JSON parser
 * @param parser The parser to destroy
 */
void		json_parser_destroy(t_json_parser *parser);

/**
 * @brief Parses a JSON string into an AST
 * @param parser The parser to use
 * @return Root node of the AST, NULL on failure
 */
t_json_node	*json_parse(t_json_parser *parser);

/**
 * @brief Parses a JSON object
 * @param parser The parser to use
 * @return Object node, NULL on failure
 */
t_json_node	*json_parse_object(t_json_parser *parser);

/**
 * @brief Parses a JSON array
 * @param parser The parser to use
 * @return Array node, NULL on failure
 */
t_json_node	*json_parse_array(t_json_parser *parser);

/**
 * @brief Parses a JSON value (string, number, bool, null, object, array)
 * @param parser The parser to use
 * @return Value node, NULL on failure
 */
t_json_node	*json_parse_value(t_json_parser *parser);

/**
 * @brief Parses a JSON string with escape sequences
 * @param lexer The lexer to use
 * @return String value, NULL on failure
 */
char		*json_parse_string(t_json_lexer *lexer);

/**
 * @brief Parses a JSON number
 * @param lexer The lexer to use
 * @return Number value
 */
double		json_parse_number(t_json_lexer *lexer);

/* ************************************************************************** */
/*                              NODE FUNCTIONS                                 */
/* ************************************************************************** */

/**
 * @brief Creates a new JSON node
 * @param type The type of the node
 * @return Pointer to the new node, NULL on failure
 */
t_json_node	*json_node_new(t_json_type type);

/**
 * @brief Destroys a JSON node and all its children
 * @param node The node to destroy
 */
void		json_node_destroy(t_json_node *node);

/**
 * @brief Creates a deep copy of a JSON node
 * @param node The node to clone
 * @return Pointer to the cloned node, NULL on failure
 */
t_json_node	*json_node_clone(t_json_node *node);

/**
 * @brief Adds a child node to a parent node
 * @param parent The parent node
 * @param child The child node to add
 * @return JSON_SUCCESS on success, error code on failure
 */
t_json_error	json_node_add_child(t_json_node *parent, t_json_node *child);

/**
 * @brief Sets the key of a JSON node (for object properties)
 * @param node The node to set the key for
 * @param key The key string
 * @return JSON_SUCCESS on success, error code on failure
 */
t_json_error	json_node_set_key(t_json_node *node, const char *key);

/**
 * @brief Sets the value of a JSON node
 * @param node The node to set the value for
 * @param value The value to set
 * @return JSON_SUCCESS on success, error code on failure
 */
t_json_error	json_node_set_value(t_json_node *node, t_value value);

/**
 * @brief Gets a child node by index
 * @param node The parent node
 * @param index The index of the child
 * @return Pointer to the child node, NULL if not found
 */
t_json_node	*json_node_get_child(t_json_node *node, size_t index);

/**
 * @brief Gets a child node by key (for object properties)
 * @param node The parent node
 * @param key The key to search for
 * @return Pointer to the child node, NULL if not found
 */
t_json_node	*json_node_get_by_key(t_json_node *node, const char *key);

/**
 * @brief Gets the number of children in a node
 * @param node The node to count children for
 * @return Number of children
 */
size_t		json_node_child_count(t_json_node *node);

/**
 * @brief Checks if a node is a leaf (has no children)
 * @param node The node to check
 * @return true if leaf, false otherwise
 */
bool		json_node_is_leaf(t_json_node *node);

/* ************************************************************************** */
/*                              NODE CREATION HELPERS                          */
/* ************************************************************************** */

/**
 * @brief Creates a JSON string node
 * @param value The string value
 * @return Pointer to the new node, NULL on failure
 */
t_json_node	*json_create_string(const char *value);

/**
 * @brief Creates a JSON number node
 * @param value The number value
 * @return Pointer to the new node, NULL on failure
 */
t_json_node	*json_create_number(double value);

/**
 * @brief Creates a JSON boolean node
 * @param value The boolean value
 * @return Pointer to the new node, NULL on failure
 */
t_json_node	*json_create_bool(bool value);

/**
 * @brief Creates a JSON null node
 * @return Pointer to the new node, NULL on failure
 */
t_json_node	*json_create_null(void);

/**
 * @brief Creates a JSON object node
 * @return Pointer to the new node, NULL on failure
 */
t_json_node	*json_create_object(void);

/**
 * @brief Creates a JSON array node
 * @return Pointer to the new node, NULL on failure
 */
t_json_node	*json_create_array(void);

/* ************************************************************************** */
/*                              MEMORY MANAGEMENT                              */
/* ************************************************************************** */

/**
 * @brief Cleans up a JSON value, freeing allocated memory
 * @param value The value to clean up
 */
void		json_cleanup_value(t_value *value);

/**
 * @brief Creates a deep copy of a JSON value
 * @param value The value to clone
 * @return The cloned value
 */
t_value		json_clone_value(t_value value);

/* ************************************************************************** */
/*                              ACCESS FUNCTIONS                               */
/* ************************************************************************** */

/**
 * @brief Gets a value from a JSON object by key
 * @param root The root JSON node
 * @param key The key to search for
 * @return Pointer to the value node, NULL if not found
 */
t_json_node	*json_get(t_json_node *root, const char *key);

/**
 * @brief Sets a value in a JSON object
 * @param root The root JSON node
 * @param key The key to set
 * @param value The value to set
 * @return JSON_SUCCESS on success, error code on failure
 */
t_json_error	json_set(t_json_node *root, const char *key, t_json_node *value);

/**
 * @brief Deletes a key from a JSON object
 * @param root The root JSON node
 * @param key The key to delete
 * @return JSON_SUCCESS on success, error code on failure
 */
t_json_error	json_delete(t_json_node *root, const char *key);

/**
 * @brief Merges two JSON objects
 * @param dest The destination object
 * @param src The source object
 * @return JSON_SUCCESS on success, error code on failure
 */
t_json_error	json_merge(t_json_node *dest, t_json_node *src);

/* ************************************************************************** */
/*                              SERIALIZATION                                  */
/* ************************************************************************** */

/**
 * @brief Converts a JSON node to a string
 * @param node The node to serialize
 * @return JSON string, NULL on failure
 */
char		*json_to_string(t_json_node *node);

/**
 * @brief Converts a JSON node to a pretty-printed string
 * @param node The node to serialize
 * @param indent The indentation level
 * @return Pretty-printed JSON string, NULL on failure
 */
char		*json_pretty_print(t_json_node *node, int indent);

/**
 * @brief Converts a JSON node to a minified string
 * @param node The node to serialize
 * @return Minified JSON string, NULL on failure
 */
char		*json_minify(t_json_node *node);

/* ************************************************************************** */
/*                              FILE OPERATIONS                                */
/* ************************************************************************** */

/**
 * @brief Loads JSON from a file
 * @param filename The file to load from
 * @return Root node of the JSON, NULL on failure
 */
t_json_node	*json_from_file(const char *filename);

/**
 * @brief Saves JSON to a file
 * @param node The root node to save
 * @param filename The file to save to
 * @param pretty Whether to pretty-print
 * @return JSON_SUCCESS on success, error code on failure
 */
t_json_error	json_to_file(t_json_node *node, const char *filename, bool pretty);

/* ************************************************************************** */
/*                              VALIDATION                                     */
/* ************************************************************************** */

/**
 * @brief Validates JSON syntax
 * @param input The JSON string to validate
 * @return JSON_SUCCESS if valid, error code on failure
 */
t_json_error	json_validate(const char *input);

/**
 * @brief Gets the last error from a parser
 * @param parser The parser to get error from
 * @return The last error code
 */
t_json_error	json_get_last_error(t_json_parser *parser);

/**
 * @brief Gets the last error message from a parser
 * @param parser The parser to get error from
 * @return The last error message
 */
const char	*json_get_error_message(t_json_parser *parser);

/**
 * @brief Gets a string representation of an error code
 * @param error The error code
 * @return String representation of the error
 */
const char	*json_error_string(t_json_error error);

/* ************************************************************************** */
/*                              UTILITY FUNCTIONS                              */
/* ************************************************************************** */

/**
 * @brief Creates a JSON object from key-value pairs
 * @param ... Variable arguments: key1, value1, key2, value2, ..., NULL
 * @return Object node, NULL on failure
 */
t_json_node	*json_object(const char *key, t_json_node *value, ...);

/**
 * @brief Creates a JSON array from values
 * @param ... Variable arguments: value1, value2, ..., NULL
 * @return Array node, NULL on failure
 */
t_json_node	*json_array(t_json_node *value, ...);

/**
 * @brief Gets a string value from a JSON node
 * @param node The node to get value from
 * @return The string value, NULL if not a string
 */
const char	*json_get_string(t_json_node *node);

/**
 * @brief Gets a number value from a JSON node
 * @param node The node to get value from
 * @return The number value, 0.0 if not a number
 */
double		json_get_number(t_json_node *node);

/**
 * @brief Gets a boolean value from a JSON node
 * @param node The node to get value from
 * @return The boolean value, false if not a boolean
 */
bool		json_get_bool(t_json_node *node);

/**
 * @brief Checks if a JSON node is null
 * @param node The node to check
 * @return true if null, false otherwise
 */
bool		json_is_null(t_json_node *node);

#endif 
