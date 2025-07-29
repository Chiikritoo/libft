/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:04:43 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/29 13:37:22 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define ANSI_RED "\033[31m"
# define ANSI_GREEN "\033[32m"
# define ANSI_YELLOW "\033[33m"
# define ANSI_BLUE "\033[34m"
# define ANSI_MAGENTA "\033[35m"
# define ANSI_CYAN "\033[36m"
# define ANSI_WHITE "\033[37m"
# define ANSI_RESET "\033[0m"
# define ANSI_BOLD "\033[1m"

/* ************************************************************************* */
/*                            STANDARD INCLUSIONS                            */
/* ************************************************************************* */
# define _GNU_SOURCE
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <errno.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include "log.h"
# include "toml.h"

/* ************************************************************************* */
/*                              CHECK FUNCTIONS                              */
/* ************************************************************************* */
int							ft_isalnum(int c);
int							ft_isalpha(int c);
int							ft_isascii(int c);
int							ft_isdigit(int c);
int							ft_isprint(int c);
int							ft_isspace(int c);

/* ************************************************************************* */
/*                             CONVERT FUNCTIONS                             */
/* ************************************************************************* */
int							ft_atoi(const char *str);
double						ft_atof(const char *str);
long long					ft_atoll(const char *str);
int							len_int(int n);
int							len_uint(unsigned int n);
char						*ft_itoa(int n);
int							ft_tolower(int c);
int							ft_toupper(int c);
char						*ft_utoa(unsigned int n);

/* ************************************************************************** */
/*                               FREE FUNCTIONS                               */
/* ************************************************************************** */
void						ft_free_double_ptr(void ***ptr);
void						ft_free_ptr(void **ptr);

/* ************************************************************************* */
/*                             GARBAGE FUNCTIONS                             */
/* ************************************************************************* */
# ifndef HASH_SIZE
#  define HASH_SIZE 1021
# endif

typedef struct s_gc_ctx		t_gc_ctx;
typedef struct s_gc			t_gc;

struct						s_gc_ctx
{
	t_gc					**hashmap;
	size_t					capacity;
	size_t					size;
	float					load_factor;
};

struct						s_gc
{
	void					*ptr;
	t_gc					*next;
	t_gc					*hash_next;
};

unsigned int				gc_hash(void *ptr, size_t capacity);
int							gc_add(t_gc_ctx *ctx, t_gc *node, void *ptr);
void						*gc_calloc(t_gc_ctx *ctx, size_t nmemb,
								size_t size);
void						gc_clear(t_gc_ctx *ctx);
void						gc_clear_temporary(t_gc_ctx *ctx);
void						gc_ctx_destroy(t_gc_ctx *ctx);
void						gc_free(t_gc_ctx *ctx, void *ptr);
void						gc_resize(t_gc_ctx *ctx);
t_gc_ctx					*gc_ctx_init(void);

char						**gc_split(t_gc_ctx *ctx, const char *s, char c);
char						*gc_itoa(t_gc_ctx *ctx, int n);
char						*gc_utoa(t_gc_ctx *ctx, unsigned int n);
char						*gc_strjoin(t_gc_ctx *ctx, const char *s1,
								const char *s2);
char						*gc_strjoin_f1(t_gc_ctx *ctx, char *s1,
								const char *s2);
char						*gc_strjoin_f2(t_gc_ctx *ctx, const char *s1,
								char *s2);
char						*gc_strjoin_gnl(t_gc_ctx *ctx, char *s1,
								const char *s2);
char						*gc_substr(t_gc_ctx *ctx, const char *s,
								unsigned int st, size_t l);
char						*gc_strdup(t_gc_ctx *ctx, const char *s);
char						*gc_strcdup(t_gc_ctx *ctx, const char *s, char c);
char						*gc_strndup(t_gc_ctx *ctx, const char *s, size_t n);
char						*gc_get_next_line(t_gc_ctx *ctx, int fd);
void						*gc_calloc(t_gc_ctx *ctx, size_t nmemb,
								size_t size);
void						*gc_realloc(t_gc_ctx *ctx, void *ptr, size_t old_s,
								size_t new_s);
char						*gc_get_next_line(t_gc_ctx *ctx, int fd);

/* ************************************************************************* */
/*                          GET_NEXT_LINE FUNCTIONS                          */
/* ************************************************************************* */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char						*get_next_line(int fd);

/* ************************************************************************** */
/*                               LIST FUNCTIONS                               */
/* ************************************************************************** */
typedef struct s_lst_ctx	t_lst_ctx;
typedef struct s_lst		t_lst;
typedef struct s_pool		t_pool;

struct						s_lst_ctx
{
	t_lst					*head;
	t_lst					*tail;
	size_t					size;
};

struct						s_lst
{
	void					*content;
	t_lst					*next;
	t_lst					*prev;
};

void						ft_ctx_destroy(t_lst_ctx *ctx);
t_lst_ctx					*ft_ctx_init(void);
void						ft_lstadd_back(t_lst_ctx *ctx, t_lst *new);
void						ft_lstadd_front(t_lst_ctx *ctx, t_lst *new);
void						ft_lstclear(t_lst_ctx *ctx, void (*del)(void *));
void						ft_lstdelone(t_lst_ctx *ctx, t_lst *lst,
								void (*del)(void *));
void						ft_lstiter(t_lst_ctx *ctx, void (*f)(void *));
t_lst						*ft_lstlast(t_lst_ctx *ctx);
t_lst_ctx					*ft_lstmap(t_lst_ctx *ctx, void *(*f)(void *),
								void (*del)(void *));
t_lst						*ft_lstnew(void *content);
int							ft_lstsize(t_lst_ctx *ctx);

/* ************************************************************************** */
/*                              MEMORY FUNCTIONS                              */
/* ************************************************************************** */
void						ft_bzero(void *s, size_t n);
void						*ft_calloc(size_t nmemb, size_t size);
void						*ft_memchr(const void *s, int c, size_t n);
int							ft_memcmp(const void *s1, const void *s2, size_t n);
void						*ft_memcpy(void *dest, const void *src, size_t n);
void						*ft_memdup(void const *src, size_t size);
void						*ft_memmove(void *dest, const void *src, size_t n);
void						*ft_memset(void *s, int c, size_t n);
void						*ft_realloc(void *ptr, size_t old_size,
								size_t new_size);

/* ************************************************************************* */
/*                              PRINT FUNCTIONS                              */
/* ************************************************************************* */
typedef struct s_buffer
{
	char					data[BUFFER_SIZE];
	size_t					capacity;
	size_t					length;
}							t_buffer;

void						append_char(t_buffer *buf, char c);
void						append_str(t_buffer *buf, char *s);
void						append_int(t_buffer *buf, int n);
void						append_uint(t_buffer *buf, unsigned int n);
void						append_base(t_buffer *buf, unsigned long long n,
								char *base);
void						append_ptr(t_buffer *buf, void *ptr);
int							buffer_init(t_buffer *buf);

int							ft_printf(const char *s, ...);
int							ft_dprintf(int fd, const char *s, ...);
int							ft_vdprintf(int fd, const char *s, va_list ap);
int							ft_vsnprintf(char *str, size_t size, \
								const char *format, va_list ap);
void						handle_format(va_list *ap, t_buffer *buf, char c);
void						buffer_flush(t_buffer *buf);

void						ft_putchar_fd(char c, int fd);
void						ft_putendl_fd(char *s, int fd);
void						ft_putnbr_fd(int n, int fd);
void						ft_putstr_fd(char *s, int fd);

/* ************************************************************************** */
/*                              STRING FUNCTIONS                              */
/* ************************************************************************** */
char						**ft_split(const char *s, char c);
char						*ft_strchr(const char *s, int c);
int							ft_strcmp(const char *s1, const char *s2);
char						*ft_strdup(const char *s);
char						*ft_strcdup(const char *s, char c);
char						*ft_strndup(const char *s, size_t n);
void						ft_striteri(char *s, void (*f)(unsigned int,
									char *));
char						*ft_strjoin_gnl(char *s1, const char *s2);
char						*ft_strjoin_f1(char *s1, const char *s2);
char						*ft_strjoin_f2(const char *s1, char *s2);
char						*ft_strjoin(const char *s1, const char *s2);
size_t						ft_strlcat(char *dst, const char *src, size_t size);
size_t						ft_strlcpy(char *dst, const char *src, size_t size);
ssize_t						ft_strlen(const char *s);
char						*ft_strmapi(const char *s, char (*f)(unsigned int,
									char));
int							ft_strncmp(const char *s1, const char *s2,
								size_t n);
char						*ft_strnstr(const char *big, const char *little,
								size_t len);
char						*ft_strrchr(const char *s, int c);
char						*ft_strtrim(const char *s1, const char *set);
char						*ft_substr(const char *s, unsigned int start,
								size_t len);
char						*ft_strrev(const char *s);
char						*ft_strtok(char *str, const char *delim, char **nextp);
size_t						ft_strspn(const char *s, const char *accept);
size_t						ft_strcspn(const char *s, const char *reject);
char						*ft_strpbrk(const char *s, const char *accept);

/* ************************************************************************** */
/*                               FILE FUNCTIONS                               */
/* ************************************************************************** */
char						**ft_get_file(const char *filename);
long long					ft_file_size(const char *filename);
int							ft_file_exists(const char *filename);
int							ft_file_line_count(const char *filename);

#endif
