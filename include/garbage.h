/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:31:59 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/29 16:58:36 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H
# define GARBAGE_H

# include "include.h"

# ifndef HASH_SIZE
#  define HASH_SIZE 1021
# endif

# ifndef POOL_SIZE
#  define POOL_SIZE 1024
# endif

typedef struct s_gc_ctx	t_gc_ctx;
typedef struct s_gc		t_gc;

struct s_gc_ctx
{
	t_gc	*hashmap[HASH_SIZE];
	t_gc	*pool;
	size_t	size;
	size_t	pool_size;
};

struct s_gc
{
	void		*ptr;
	struct s_gc	*next;
};

t_gc			*gc_pool_get(t_gc_ctx *ctx);
void			gc_pool_add(t_gc_ctx *ctx, t_gc *node);
void			gc_pool_resize(t_gc_ctx *ctx);
void			gc_pool_init(t_gc_ctx *ctx);
unsigned int	gc_hash(void *ptr);
void			gc_add(t_gc_ctx *ctx, t_gc *node, void *ptr);
void			*gc_calloc(t_gc_ctx *ctx, size_t nmemb, size_t size);
void			gc_clear(t_gc_ctx *ctx);
void			gc_ctx_destroy(t_gc_ctx *ctx);
void			gc_free(t_gc_ctx *ctx, void *ptr);
t_gc_ctx		*gc_ctx_init(void);

char			**gc_split(t_gc_ctx *ctx, char const *s, char c);
char			*gc_itoa(t_gc_ctx *ctx, int n);
char			*gc_utoa(t_gc_ctx *ctx, unsigned int n);
char			*gc_strjoin(t_gc_ctx *ctx, char const *s1, char const *s2);
char			*gc_strjoin_f1(t_gc_ctx *ctx, char *s1, char const *s2);
char			*gc_strjoin_f2(t_gc_ctx *ctx, char const *s1, char *s2);
char			*gc_strjoin_gnl(t_gc_ctx *ctx, char *s1, char const *s2);
char			*gc_substr(t_gc_ctx *ctx, char const *s, unsigned int st, size_t l);
char			*gc_strdup(t_gc_ctx *ctx, const char *s);
char			*gc_get_next_line(t_gc_ctx *ctx, int fd);
void			*gc_calloc(t_gc_ctx *ctx, size_t nmemb, size_t size);
void			*gc_realloc(t_gc_ctx *ctx, void *ptr, size_t old_s, size_t new_s);
char			*gc_get_next_line(t_gc_ctx *ctx, int fd);

#endif
