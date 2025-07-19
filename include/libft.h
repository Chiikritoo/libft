/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:04:43 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/19 22:32:27 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* ************************************************************************* */
/*                            STANDARD INCLUSIONS                            */
/* ************************************************************************* */
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <errno.h>

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
long long					ft_atoll(const char *str);
int							len_int(int n);
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

/* ************************************************************************* */
/*                              ERROR FUNCTIONS                              */
/* ************************************************************************* */

typedef enum e_error_type
{
	ERROR_NONE,
	ERROR_MEMORY,
	ERROR_INVALID_PARAM,
	ERROR_IO,
	ERROR_LOGIC,
	ERROR_UNKNOWN,
}					t_error_type;

/* ************************************************************************* */
/*                              ERROR MACROS                                 */
/* ************************************************************************* */
# define SET_ERROR(ctx, type, code, msg, ...) \
	set_error_ctx(ctx, type, code, __FILE__, __func__, __LINE__, msg, ##__VA_ARGS__)
# define CHECK_ERROR(ctx) has_error_ctx(ctx)
# define PRINT_ERROR(ctx) print_error_ctx(ctx)
# define CLEAR_ERROR(ctx) clear_error_ctx(ctx)

typedef struct s_error_ctx
{
	t_error_type		type;
	int					code;
	char				*message;
	char				*function;
	char				*file;
	int					line;
	void				*data;
	bool				has_error;
}					t_error_ctx;

// Context management
t_error_ctx					*error_ctx_init(void);
void						error_ctx_destroy(t_error_ctx *ctx);
void						error_ctx_reset(t_error_ctx *ctx);
void						error_ctx_copy(t_error_ctx *dest, const t_error_ctx *src);

// Error operations
void						set_error_ctx(t_error_ctx *ctx, t_error_type type, int code,
								const char *file, const char *func, int line, const char *msg, ...);
void						clear_error_ctx(t_error_ctx *ctx);
bool						has_error_ctx(const t_error_ctx *ctx);
void						print_error_ctx(const t_error_ctx *ctx);

// Error information
t_error_type				get_error_type(const t_error_ctx *ctx);
int							get_error_code(const t_error_ctx *ctx);
const char					*get_error_message(const t_error_ctx *ctx);
const char					*get_error_function(const t_error_ctx *ctx);
const char					*get_error_file(const t_error_ctx *ctx);
int							get_error_line(const t_error_ctx *ctx);
void						*get_error_data(const t_error_ctx *ctx);

// Error type utilities
const char					*get_error_type_name(t_error_type type);
bool						is_error_type_valid(t_error_type type);

typedef struct s_libft
{
	struct			s_check
	{
		int			(*isalpha)(int c);
		int			(*isdigit)(int c);
		int			(*isalnum)(int c);
		int			(*isascii)(int c);
		int			(*isprint)(int c);
	} check;
	struct			s_convert
	{
		int			(*atoi)(const char *str);
		long long	(*atoll)(const char *str);
		char		*(*itoa)(int n);
		int			(*tolower)(int c);
		int			(*toupper)(int c);
		char		*(*utoa)(unsigned int n);
	} convert;
	struct			s_free
	{
		void		(*free_ptr)(void **ptr);
		void		(*free_double_ptr)(void ***ptr);
	} free;
	struct			s_gnl
	{
		char		*(*get_next_line)(int fd);
	} gnl;
	struct			s_list
	{
		void		(*ctx_destroy)(t_lst_ctx *ctx);
		t_lst_ctx	*(*ctx_init)(void);
		void		(*add_back)(t_lst_ctx *ctx, t_lst *new);
		void		(*add_front)(t_lst_ctx *ctx, t_lst *new);
		void		(*clear)(t_lst_ctx *ctx, void (*del)(void *));
		void		(*delone)(t_lst_ctx *ctx, t_lst *lst, void (*del)(void *));
		void		(*iter)(t_lst_ctx *ctx, void (*f)(void *));
		t_lst		*(*last)(t_lst_ctx *ctx);
		t_lst_ctx	*(*map)(t_lst_ctx *ctx, void *(*f)(void *), \
						void (*del)(void *));
		t_lst		*(*new)(void *content);
		int			(*size)(t_lst_ctx *ctx);
	} list;
	struct			s_memory
	{
		void		(*bzero)(void *s, size_t n);
		void		*(*calloc)(size_t nmemb, size_t size);
		void		*(*memchr)(const void *s, int c, size_t n);
		int			(*memcmp)(const void *s1, const void *s2, size_t n);
		void		*(*memcpy)(void *dest, const void *src, size_t n);
		void		*(*memdup)(const void *src, size_t size);
		void		*(*memmove)(void *dest, const void *src, size_t n);
		void		*(*memset)(void *s, int c, size_t n);
		void		*(*realloc)(void *ptr, size_t old_size, size_t new_size);
	} memory;
	struct			s_print
	{
		int			(*printf)(const char *s, ...);
		int			(*dprintf)(int fd, const char *s, ...);
		void		(*putchar_fd)(char c, int fd);
		void		(*putendl_fd)(char *s, int fd);
		void		(*putnbr_fd)(int n, int fd);
		void		(*putstr_fd)(char *s, int fd);
	} print;
	struct			s_string
	{
		char		**(*split)(const char *s, char c);
		char		*(*strcdup)(const char *s, char c);
		char		*(*strchr)(const char *s, int c);
		int			(*strcmp)(const char *s1, const char *s2);
		char		*(*strdup)(const char *s);
		void		(*striteri)(char *s, void (*f)(unsigned int, char *));
		char		*(*strjoin_f1)(char *s1, const char *s2);
		char		*(*strjoin_f2)(const char *s1, char *s2);
		char		*(*strjoin_gnl)(char *s1, const char *s2);
		char		*(*strjoin)(const char *s1, const char *s2);
		size_t		(*strlcat)(char *dst, const char *src, size_t size);
		size_t		(*strlcpy)(char *dst, const char *src, size_t size);
		ssize_t		(*strlen)(const char *s);
		char		*(*strmapi)(const char *s, char (*f)(unsigned int, char));
		int			(*strncmp)(const char *s1, const char *s2, size_t n);
		char		*(*strndup)(const char *s, size_t n);
		char		*(*strnstr)(const char *big, const char *little, \
						size_t len);
		char		*(*strrchr)(const char *s, int c);
		char		*(*strtrim)(const char *s1, const char *set);
		char		*(*substr)(const char *s, unsigned int start, size_t len);
	} string;
	// t_error			error;
	t_error_ctx		*error_ctx;
}					t_libft;

/* ************************************************************************** */
/*                                    CORE                                    */
/* ************************************************************************** */
t_libft						*libft_init(void);
void						libft_destroy(t_libft *libft);

/* ************************************************************************* */
/*                              SAFE FUNCTIONS                               */
/* ************************************************************************* */
int							safe_isalnum(t_libft *libft, int c);
int							safe_isalpha(t_libft *libft, int c);
int							safe_isascii(t_libft *libft, int c);
int							safe_isdigit(t_libft *libft, int c);
int							safe_isprint(t_libft *libft, int c);
int							safe_isspace(t_libft *libft, int c);
int							safe_atoi(t_libft *libft, const char *str);
long long					safe_atoll(t_libft *libft, const char *str);
char						*safe_itoa(t_libft *libft, int n);
int							safe_tolower(t_libft *libft, int c);
int							safe_toupper(t_libft *libft, int c);
char						*safe_utoa(t_libft *libft, unsigned int n);
char						**safe_split(t_libft *libft, const char *s, char c);
char						*safe_strcdup(t_libft *libft, const char *s, char c);
char						*safe_strdup(t_libft *libft, const char *s);
char						*safe_strndup(t_libft *libft, const char *s, size_t n);
void						safe_striteri(t_libft *libft, char *s, void (*f)(unsigned int, char *));
char						*safe_strjoin_f1(t_libft *libft, char *s1, const char *s2);
char						*safe_strjoin_f2(t_libft *libft, const char *s1, char *s2);
char						*safe_strjoin_gnl(t_libft *libft, char *s1, const char *s2);
char						*safe_substr(t_libft *libft, const char *s, unsigned int start, size_t len);
char						*safe_strtrim(t_libft *libft, const char *s1, const char *set);
char						*safe_strmapi(t_libft *libft, const char *s, char (*f)(unsigned int, char));
char						*safe_strnstr(t_libft *libft, const char *big, const char *little, size_t len);
char						*safe_strrchr(t_libft *libft, const char *s, int c);
char						*safe_strtrim(t_libft *libft, const char *s1, const char *set);
char						*safe_substr(t_libft *libft, const char *s, unsigned int start, size_t len);

#endif
