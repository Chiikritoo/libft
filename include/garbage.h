/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:31:59 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 01:06:39 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H
# define GARBAGE_H

# include "include.h"

typedef struct s_gc_context	t_gc_context;
typedef struct s_garbage	t_garbage;

struct s_gc_context
{
	t_garbage	*head;
};

struct s_garbage
{
	void				*ptr;
	struct s_garbage	*next;
};

void			*gc_alloc(t_gc_context *ctx, size_t nmemb, size_t size);
void			gc_clear(t_gc_context *ctx);
void			gc_destroy(t_gc_context *ctx);
void			gc_free(t_gc_context *ctx, void *ptr);
t_gc_context	*gc_init(void);

#endif
