/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:04:43 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/21 20:14:36 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

/* ************************************************************************* */
/*                            STANDARD INCLUSIONS                            */
/* ************************************************************************* */
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>

/* ************************************************************************* */
/*                              CHECK FUNCTIONS                              */
/* ************************************************************************* */
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);

/* ************************************************************************* */
/*                             CONVERT FUNCTIONS                             */
/* ************************************************************************* */
int				ft_atoi(const char *str);
long long		ft_atoll(const char *str);
int				len_int(int n);
char			*ft_itoa(int n);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_utoa(unsigned int n);

/* ************************************************************************** */
/*                               FREE FUNCTIONS                               */
/* ************************************************************************** */
void			ft_free_double_ptr(void ***ptr);
void			ft_free_ptr(void **ptr);

/* ************************************************************************* */
/*                             GARBAGE FUNCTIONS                             */
/* ************************************************************************* */
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
	size_t	size;
};

struct s_gc
{
	void	*ptr;
	t_gc	*next;
	t_gc	*hash_next;
};

unsigned int	gc_hash(void *ptr);
int				gc_add(t_gc_ctx *ctx, t_gc *node, void *ptr);
void			*gc_calloc(t_gc_ctx *ctx, size_t nmemb, size_t size);
void			*gc_calloc_temporary(t_gc_ctx *ctx, size_t nmemb, size_t size);
void			gc_clear(t_gc_ctx *ctx);
void			gc_clear_temporary(t_gc_ctx *ctx);
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
char			*gc_strcdup(t_gc_ctx *ctx, const char *s, char c);
char			*gc_strndup(t_gc_ctx *ctx, const char *s, size_t n);
char			*gc_get_next_line(t_gc_ctx *ctx, int fd);
void			*gc_calloc(t_gc_ctx *ctx, size_t nmemb, size_t size);
void			*gc_realloc(t_gc_ctx *ctx, void *ptr, size_t old_s, size_t new_s);
char			*gc_get_next_line(t_gc_ctx *ctx, int fd);

/* ************************************************************************* */
/*                          GET_NEXT_LINE FUNCTIONS                          */
/* ************************************************************************* */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char			*get_next_line(int fd);

/* ************************************************************************** */
/*                               LIST FUNCTIONS                               */
/* ************************************************************************** */
typedef struct s_lst_ctx	t_lst_ctx;
typedef struct s_lst		t_lst;
typedef struct s_pool		t_pool;

struct s_lst_ctx
{
	t_lst	*head;
	t_lst	*tail;
	size_t	size;
};

struct s_lst
{
	void	*content;
	t_lst	*next;
	t_lst	*prev;
};

void			ft_ctx_destroy(t_lst_ctx *ctx);
t_lst_ctx		*ft_ctx_init(void);
void			ft_lstadd_back(t_lst_ctx *ctx, t_lst *new_node);
void			ft_lstadd_front(t_lst_ctx *ctx, t_lst *new_node);
void			ft_lstclear(t_lst_ctx *ctx, void (*del)(void *));
void			ft_lstdelone(t_lst_ctx *ctx, t_lst *lst, void (*del)(void *));
void			ft_lstiter(t_lst_ctx *ctx, void (*f)(void *));
t_lst			*ft_lstlast(t_lst_ctx *ctx);
t_lst_ctx		*ft_lstmap(t_lst_ctx *ctx, void *(*f)(void *), void (*del)(void *));
t_lst			*ft_lstnew(void *content);
int				ft_lstsize(t_lst_ctx *ctx);

/* ************************************************************************** */
/*                              MEMORY FUNCTIONS                              */
/* ************************************************************************** */
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memdup(void const *src, size_t size);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_realloc(void *ptr, size_t old_size, size_t new_size);

/* ************************************************************************* */
/*                              PRINT FUNCTIONS                              */
/* ************************************************************************* */
void			append_char(char **str, char c);
void			append_str(char **str, char *s);
void			append_int(char **str, int n);
void			append_uint(char **str, unsigned int n);
void			append_base(char **str, unsigned long long n, char *base);
void			append_ptr(char **str, unsigned long n);

int				ft_printf(const char *s, ...);
int				ft_dprintf(int fd, const char *s, ...);
void			handle_format(va_list ap, char **str, char c);

void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);

/* ************************************************************************** */
/*                              STRING FUNCTIONS                              */
/* ************************************************************************** */
char			**ft_split(char const *s, char c);
char			*ft_strchr(char const *s, int c);
int				ft_strcmp(char const *s1, char const *s2);
char			*ft_strdup(char const *s);
char			*ft_strcdup(char const *s, char c);
char			*ft_strndup(char const *s, size_t n);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin_gnl(char *s1, char const *s2);
char			*ft_strjoin_f1(char *s1, char const *s2);
char			*ft_strjoin_f2(char const *s1, char *s2);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, char const *src, size_t size);
size_t			ft_strlcpy(char *dst, char const *src, size_t size);
size_t			ft_strlen(char const *s);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(char const *s1, char const *s2, size_t n);
char			*ft_strnstr(char const *big, char const *little, size_t len);
char			*ft_strrchr(char const *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif
