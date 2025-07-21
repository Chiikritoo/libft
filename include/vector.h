/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:42:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/22 00:00:16 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "libft.h"

/* ************************************************************************** */
/*                              TYPE DEFINITIONS                               */
/* ************************************************************************** */

typedef enum e_type
{
	TYPE_CHAR,
	TYPE_STRING,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_BOOL,
	TYPE_VOID,
	TYPE_PTR,
	TYPE_FUNC,
	TYPE_LST_CTX,
	TYPE_GC_CTX,
	TYPE_VECTOR
}								e_type;

typedef enum e_vector_error
{
	VECTOR_SUCCESS = 0,
	VECTOR_ERROR_NULL_PTR,
	VECTOR_ERROR_OUT_OF_BOUNDS,
	VECTOR_ERROR_TYPE_MISMATCH,
	VECTOR_ERROR_MEMORY_ALLOCATION,
	VECTOR_ERROR_INVALID_OPERATION
}								t_vector_error;

typedef struct s_value			t_value;
typedef struct s_lst_ctx		t_lst_ctx;
typedef struct s_gc_ctx			t_gc_ctx;
typedef struct s_vector			t_vector;
typedef struct s_vector_iter	t_vector_iter;

typedef union u_any
{
	char						c;
	char						*str;
	int							i;
	float						f;
	double						d;
	bool						b;
	void						*p;
	void						(*func)(void);
	t_lst_ctx					*l;
	t_gc_ctx					*gc;
	t_vector					*v;
}								t_any;

struct							s_value
{
	e_type						type;
	bool						owned;
	t_any						as;
};

struct							s_vector
{
	t_value						*data;
	size_t						size;
	size_t						capacity;
	t_vector_error				last_error;
};

struct							s_vector_iter
{
	t_vector					*vector;
	size_t						index;
	bool						valid;
};

/* ************************************************************************** */
/*                              VECTOR CREATION                                */
/* ************************************************************************** */

/**
 * @brief Creates a new vector with initial capacity
 * @param initial_capacity Initial capacity of the vector
 * @return Pointer to the new vector, NULL on failure
 */
t_vector						*vector_new(size_t initial_capacity);

/**
 * @brief Creates a vector from an array of values
 * @param values Array of values
 * @param count Number of values
 * @return Pointer to the new vector, NULL on failure
 */
t_vector						*vector_from_array(t_value *values,
									size_t count);

/**
 * @brief Creates a copy of an existing vector
 * @param src Source vector to copy
 * @return Pointer to the new vector, NULL on failure
 */
t_vector						*vector_clone(t_vector *src);

/* ************************************************************************** */
/*                              VECTOR DESTRUCTION                             */
/* ************************************************************************** */

/**
 * @brief Destroys a vector and frees all memory
 * @param vector Vector to destroy
 */
void							vector_destroy(t_vector *vector);

/**
 * @brief Clears all elements from the vector
 * @param vector Vector to clear
 */
void							vector_clear(t_vector *vector);

/* ************************************************************************** */
/*                              ELEMENT ACCESS                                 */
/* ************************************************************************** */

/**
 * @brief Gets an element at the specified index
 * @param vector Vector to access
 * @param index Index of the element
 * @return Pointer to the value, NULL if out of bounds
 */
t_value							*vector_at(t_vector *vector, size_t index);

/**
 * @brief Gets the first element of the vector
 * @param vector Vector to access
 * @return Pointer to the first value, NULL if empty
 */
t_value							*vector_front(t_vector *vector);

/**
 * @brief Gets the last element of the vector
 * @param vector Vector to access
 * @return Pointer to the last value, NULL if empty
 */
t_value							*vector_back(t_vector *vector);

/* ************************************************************************** */
/*                              ELEMENT MODIFICATION                           */
/* ************************************************************************** */

/**
 * @brief Adds an element to the end of the vector
 * @param vector Vector to modify
 * @param value Value to add
 * @return VECTOR_SUCCESS on success, error code on failure
 */
t_vector_error					vector_push_back(t_vector *vector,
									t_value value);

/**
 * @brief Removes the last element from the vector
 * @param vector Vector to modify
 * @return VECTOR_SUCCESS on success, error code on failure
 */
t_vector_error					vector_pop_back(t_vector *vector);

/**
 * @brief Inserts an element at the specified index
 * @param vector Vector to modify
 * @param index Index where to insert
 * @param value Value to insert
 * @return VECTOR_SUCCESS on success, error code on failure
 */
t_vector_error					vector_insert(t_vector *vector, size_t index,
									t_value value);

/**
 * @brief Removes an element at the specified index
 * @param vector Vector to modify
 * @param index Index of the element to remove
 * @return VECTOR_SUCCESS on success, error code on failure
 */
t_vector_error					vector_erase(t_vector *vector, size_t index);

/**
 * @brief Sets an element at the specified index
 * @param vector Vector to modify
 * @param index Index where to set the value
 * @param value Value to set
 * @return VECTOR_SUCCESS on success, error code on failure
 */
t_vector_error					vector_set(t_vector *vector, size_t index,
									t_value value);

/* ************************************************************************** */
/*                              VECTOR INFORMATION                             */
/* ************************************************************************** */

/**
 * @brief Gets the current size of the vector
 * @param vector Vector to check
 * @return Size of the vector
 */
size_t							vector_size(t_vector *vector);

/**
 * @brief Gets the current capacity of the vector
 * @param vector Vector to check
 * @return Capacity of the vector
 */
size_t							vector_capacity(t_vector *vector);

/**
 * @brief Checks if the vector is empty
 * @param vector Vector to check
 * @return true if empty, false otherwise
 */
bool							vector_empty(t_vector *vector);

/**
 * @brief Gets the last error that occurred
 * @param vector Vector to check
 * @return Last error code
 */
t_vector_error					vector_get_last_error(t_vector *vector);

/* ************************************************************************** */
/*                              MEMORY MANAGEMENT                              */
/* ************************************************************************** */

/**
 * @brief Reserves memory for the specified number of elements
 * @param vector Vector to modify
 * @param capacity New capacity
 * @return VECTOR_SUCCESS on success, error code on failure
 */
t_vector_error					vector_reserve(t_vector *vector,
									size_t capacity);

/**
 * @brief Resizes the vector to the specified size
 * @param vector Vector to modify
 * @param new_size New size
 * @param default_value Default value for new elements
 * @return VECTOR_SUCCESS on success, error code on failure
 */
t_vector_error					vector_resize(t_vector *vector, size_t new_size,
									t_value default_value);

/**
 * @brief Shrinks the vector capacity to fit its size
 * @param vector Vector to modify
 * @return VECTOR_SUCCESS on success, error code on failure
 */
t_vector_error					vector_shrink_to_fit(t_vector *vector);

/* ************************************************************************** */
/*                              ITERATION                                      */
/* ************************************************************************** */

/**
 * @brief Creates an iterator for the vector
 * @param vector Vector to iterate over
 * @return Iterator structure
 */
t_vector_iter					vector_begin(t_vector *vector);

/**
 * @brief Creates an end iterator for the vector
 * @param vector Vector to iterate over
 * @return End iterator structure
 */
t_vector_iter					vector_end(t_vector *vector);

/**
 * @brief Advances the iterator to the next element
 * @param iter Iterator to advance
 * @return true if successful, false if at end
 */
bool							vector_iter_next(t_vector_iter *iter);

/**
 * @brief Gets the current value from the iterator
 * @param iter Iterator to get value from
 * @return Pointer to the current value, NULL if invalid
 */
t_value							*vector_iter_get(t_vector_iter *iter);

/**
 * @brief Checks if the iterator is valid
 * @param iter Iterator to check
 * @return true if valid, false otherwise
 */
bool							vector_iter_valid(t_vector_iter *iter);

/* ************************************************************************** */
/*                              SEARCHING                                      */
/* ************************************************************************** */

/**
 * @brief Finds the first occurrence of a value
 * @param vector Vector to search in
 * @param value Value to search for
 * @return Index of the first occurrence, -1 if not found
 */
ssize_t							vector_find(t_vector *vector, t_value value);

/**
 * @brief Finds the first occurrence of a value with custom comparison
 * @param vector Vector to search in
 * @param value Value to search for
 * @param cmp Comparison function
 * @return Index of the first occurrence, -1 if not found
 */
ssize_t							vector_find_if(t_vector *vector, t_value value,
									bool (*cmp)(t_value, t_value));

/**
 * @brief Counts occurrences of a value
 * @param vector Vector to search in
 * @param value Value to count
 * @return Number of occurrences
 */
size_t							vector_count(t_vector *vector, t_value value);

/* ************************************************************************** */
/*                              SORTING                                        */
/* ************************************************************************** */

/**
 * @brief Sorts the vector using the provided comparison function
 * @param vector Vector to sort
 * @param cmp Comparison function
 * @return VECTOR_SUCCESS on success, error code on failure
 */
t_vector_error					vector_sort(t_vector *vector,
									int (*cmp)(t_value, t_value));

/**
 * @brief Reverses the order of elements in the vector
 * @param vector Vector to reverse
 * @return VECTOR_SUCCESS on success, error code on failure
 */
t_vector_error					vector_reverse(t_vector *vector);

/* ************************************************************************** */
/*                              UTILITY FUNCTIONS                              */
/* ************************************************************************** */

/**
 * @brief Swaps two elements in the vector
 * @param vector Vector to modify
 * @param index1 First index
 * @param index2 Second index
 * @return VECTOR_SUCCESS on success, error code on failure
 */
t_vector_error					vector_swap(t_vector *vector, size_t index1,
									size_t index2);

/**
 * @brief Applies a function to each element in the vector
 * @param vector Vector to process
 * @param func Function to apply
 * @return VECTOR_SUCCESS on success, error code on failure
 */
t_vector_error					vector_for_each(t_vector *vector,
									void (*func)(t_value *));

/**
 * @brief Creates a sub-vector from the specified range
 * @param vector Source vector
 * @param start Start index (inclusive)
 * @param end End index (exclusive)
 * @return New vector containing the sub-range, NULL on failure
 */
t_vector						*vector_subvector(t_vector *vector,
									size_t start, size_t end);

/**
 * @brief Concatenates two vectors
 * @param dest Destination vector
 * @param src Source vector
 * @return VECTOR_SUCCESS on success, error code on failure
 */
t_vector_error					vector_concat(t_vector *dest, t_vector *src);

/* ************************************************************************** */
/*                              VALUE CREATION HELPERS                         */
/* ************************************************************************** */

/**
 * @brief Creates a value of the specified type
 * @param type Type of the value
 * @param data Data to store in the value
 * @return Created value
 */
t_value							value_create(e_type type, t_any data);

/**
 * @brief Creates a char value
 * @param c Character value
 * @return Created value
 */
t_value							value_char(char c);

/**
 * @brief Creates a string value
 * @param str String value
 * @return Created value
 */
t_value							value_string(char *str);

/**
 * @brief Creates an integer value
 * @param i Integer value
 * @return Created value
 */
t_value							value_int(int i);

/**
 * @brief Creates a float value
 * @param f Float value
 * @return Created value
 */
t_value							value_float(float f);

/**
 * @brief Creates a double value
 * @param d Double value
 * @return Created value
 */
t_value							value_double(double d);

/**
 * @brief Creates a boolean value
 * @param b Boolean value
 * @return Created value
 */
t_value							value_bool(bool b);

/**
 * @brief Creates a pointer value
 * @param p Pointer value
 * @return Created value
 */
t_value							value_ptr(void *p);

/* ************************************************************************** */
/*                              ERROR HANDLING                                 */
/* ************************************************************************** */

/**
 * @brief Gets a string representation of an error code
 * @param error Error code
 * @return String representation of the error
 */
const char						*vector_error_string(t_vector_error error);

/**
 * @brief Clears the last error from the vector
 * @param vector Vector to clear error from
 */
void							vector_clear_error(t_vector *vector);

#endif
