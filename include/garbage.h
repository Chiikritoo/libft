/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:31:59 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 17:57:47 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H
# define GARBAGE_H

# include "include.h"

typedef struct s_gc_ctx	t_gc_ctx;
typedef struct s_gc		t_gc;

struct s_gc_ctx
{
	t_gc	*head;
	size_t	size;
};

struct s_gc
{
	void		*ptr;
	struct s_gc	*next;
};

void		*gc_alloc(t_gc_ctx *ctx, size_t nmemb, size_t size);
void		gc_clear(t_gc_ctx *ctx);
void		gc_ctx_destroy(t_gc_ctx *ctx);
void		gc_free(t_gc_ctx *ctx, void *ptr);
t_gc_ctx	*gc_ctx_init(void);

char		*gc_itoa(t_gc_ctx *ctx, int n);
char		*gc_utoa(t_gc_ctx *ctx, unsigned int n);
char		*gc_strjoin(t_gc_ctx *ctx, char const *s1, char const *s2);
char		*gc_strjoin_free(t_gc_ctx *ctx, char *s1, char const *s2);
char		*gc_substr(t_gc_ctx *ctx, char const *s, unsigned int st, size_t l);
char		*gc_strdup(t_gc_ctx *ctx, const char *s);
char		*gc_get_next_line(t_gc_ctx *ctx, int fd);
void		*gc_calloc(t_gc_ctx *ctx, size_t nmemb, size_t size);
void		*gc_realloc(t_gc_ctx *ctx, void *ptr, size_t old_s, size_t new_s);
char		*gc_get_next_line(t_gc_ctx *ctx, int fd);

#endif
