/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:04:43 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 15:27:15 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

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

/* ************************************************************************** */
/*                               FILE FUNCTIONS                               */
/* ************************************************************************** */
char						**ft_get_file(const char *filename);
long long					ft_file_size(const char *filename);
int							ft_file_exists(const char *filename);
int							ft_file_line_count(const char *filename);

/* ************************************************************************** */
/*                              MATH FUNCTIONS                               */
/* ************************************************************************** */
int							ft_max(int a, int b);
int							ft_min(int a, int b);
long long					ft_max_ll(long long a, long long b);
long long					ft_min_ll(long long a, long long b);
int							ft_abs(int n);
long long					ft_abs_ll(long long n);
double						ft_pow(double x, double y);
float						ft_powf(float x, float y);
int							ft_sqrt(int n);
double						ft_sqrt_precise(double n, int precision);
long long					ft_factorial(int n);
double						ft_dfactorial(int n);
int							ft_pgcd(int a, int b);
long long					ft_lcm(int a, int b);
	double						ft_sin(double x);
	double						ft_cos(double x);
	double						ft_asin(double x);
	double						ft_acos(double x);
	double						ft_atan(double x);
	double						ft_atan2(double y, double x);
	float						ft_sinf(float x);
	float						ft_cosf(float x);
	float						ft_asinf(float x);
	float						ft_acosf(float x);
	float						ft_atanf(float x);
	float						ft_atan2f(float y, float x);

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
	struct			s_file
	{
		char		**(*get_file)(const char *filename);
		long long	(*size)(const char *filename);
		int			(*exists)(const char *filename);
		int			(*line_count)(const char *filename);
	} file;
	struct			s_math
	{
		int			(*max)(int a, int b);
		int			(*min)(int a, int b);
		long long	(*max_ll)(long long a, long long b);
		long long	(*min_ll)(long long a, long long b);
		int			(*abs)(int n);
		long long	(*abs_ll)(long long n);
		double		(*pow)(double x, double y);
		float		(*powf)(float x, float y);
		int			(*sqrt)(int n);
		double		(*sqrt_precise)(double n, int precision);
		long long	(*factorial)(int n);
		double		(*dfactorial)(int n);
		int			(*pgcd)(int a, int b);
		long long	(*lcm)(int a, int b);
		double		(*sin)(double x);
		double		(*cos)(double x);
		double		(*asin)(double x);
		double		(*acos)(double x);
		double		(*atan)(double x);
		double		(*atan2)(double y, double x);
		float		(*sinf)(float x);
		float		(*cosf)(float x);
		float		(*asinf)(float x);
		float		(*acosf)(float x);
		float		(*atanf)(float x);
		float		(*atan2f)(float y, float x);
	} math;
	struct			s_gc_functions
	{
		t_gc_ctx		*(*ctx_init)(void);
		void			(*ctx_destroy)(t_gc_ctx *ctx);
		void			*(*calloc)(t_gc_ctx *ctx, size_t nmemb, size_t size);
		void			*(*realloc)(t_gc_ctx *ctx, void *ptr, size_t old_s, size_t new_s);
		void			(*clear)(t_gc_ctx *ctx);
		void			(*free)(t_gc_ctx *ctx, void *ptr);
		char			*(*strdup)(t_gc_ctx *ctx, const char *s);
		char			*(*strcdup)(t_gc_ctx *ctx, const char *s, char c);
		char			*(*strndup)(t_gc_ctx *ctx, const char *s, size_t n);
		char			*(*strjoin)(t_gc_ctx *ctx, const char *s1, const char *s2);
		char			*(*strjoin_f1)(t_gc_ctx *ctx, char *s1, const char *s2);
		char			*(*strjoin_f2)(t_gc_ctx *ctx, const char *s1, char *s2);
		char			*(*strjoin_gnl)(t_gc_ctx *ctx, char *s1, const char *s2);
		char			*(*substr)(t_gc_ctx *ctx, const char *s, unsigned int st, size_t l);
		char			**(*split)(t_gc_ctx *ctx, const char *s, char c);
		char			*(*itoa)(t_gc_ctx *ctx, int n);
		char			*(*utoa)(t_gc_ctx *ctx, unsigned int n);
		char			*(*get_next_line)(t_gc_ctx *ctx, int fd);
	} gc;
	t_error_ctx		*error_ctx;
	t_gc_ctx		*gc_ctx;
}					t_libft;

/* ************************************************************************** */
/*                                    CORE                                    */
/* ************************************************************************** */
t_libft						*libft_init(void);
t_libft						*safe_libft_init(void);
void						libft_destroy(t_libft *libft);

/* ************************************************************************* */
/*                              SAFE FUNCTIONS                               */
/* ************************************************************************* */
char						**safe_get_file(t_libft *libft, const char *filename);
char						**gc_get_file(t_gc_ctx *ctx, const char *filename);
long long					safe_file_size(t_libft *libft, const char *filename);
int							safe_file_exists(t_libft *libft, const char *filename);
int							safe_file_line_count(t_libft *libft, const char *filename);

// Safe math functions
int							safe_max(t_libft *libft, int a, int b);
int							safe_min(t_libft *libft, int a, int b);
double						safe_pow(t_libft *libft, double x, double y);
int							safe_sqrt(t_libft *libft, int n);
long long					safe_factorial(t_libft *libft, int n);

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
char						*safe_strjoin(t_libft *libft, const char *s1, const char *s2);
int							safe_strcmp(t_libft *libft, const char *s1, const char *s2);
char						*safe_strjoin_f1(t_libft *libft, char *s1, const char *s2);
char						*safe_strjoin_f2(t_libft *libft, const char *s1, char *s2);
char						*safe_strjoin_gnl(t_libft *libft, char *s1, const char *s2);
char						*safe_substr(t_libft *libft, const char *s, unsigned int start, size_t len);
char						*safe_strtrim(t_libft *libft, const char *s1, const char *set);
char						*safe_strmapi(t_libft *libft, const char *s, char (*f)(unsigned int, char));
char						*safe_strnstr(t_libft *libft, const char *big, const char *little, size_t len);
char						*safe_strrchr(t_libft *libft, const char *s, int c);
	char						*safe_strchr(t_libft *libft, const char *s, int c);
size_t						safe_strlcat(t_libft *libft, char *dst, const char *src, size_t size);
size_t						safe_strlcpy(t_libft *libft, char *dst, const char *src, size_t size);
ssize_t						safe_strlen(t_libft *libft, const char *s);
int							safe_strncmp(t_libft *libft, const char *s1, const char *s2, size_t n);

/* ************************************************************************* */
/*                              SAFE LIST FUNCTIONS                           */
/* ************************************************************************* */
t_lst_ctx					*safe_ctx_init(t_libft *libft);
void						safe_ctx_destroy(t_libft *libft, t_lst_ctx *ctx);
t_lst						*safe_lstnew(t_libft *libft, void *content);
void						safe_lstadd_front(t_libft *libft, t_lst_ctx *ctx, t_lst *new);
void						safe_lstadd_back(t_libft *libft, t_lst_ctx *ctx, t_lst *new);
int							safe_lstsize(t_libft *libft, t_lst_ctx *ctx);
t_lst						*safe_lstlast(t_libft *libft, t_lst_ctx *ctx);
void						safe_lstdelone(t_libft *libft, t_lst_ctx *ctx, t_lst *lst, void (*del)(void *));
void						safe_lstclear(t_libft *libft, t_lst_ctx *ctx, void (*del)(void *));
void						safe_lstiter(t_libft *libft, t_lst_ctx *ctx, void (*f)(void *));
t_lst_ctx					*safe_lstmap(t_libft *libft, t_lst_ctx *ctx, void *(*f)(void *), void (*del)(void *));

/* ************************************************************************* */
/*                              SAFE MEMORY FUNCTIONS                         */
/* ************************************************************************* */
void						*safe_calloc(t_libft *libft, size_t nmemb, size_t size);
void						*safe_realloc(t_libft *libft, void *ptr, size_t old_size, size_t new_size);
void						*safe_memcpy(t_libft *libft, void *dest, const void *src, size_t n);
void						*safe_memmove(t_libft *libft, void *dest, const void *src, size_t n);
void						*safe_memset(t_libft *libft, void *s, int c, size_t n);
void						safe_bzero(t_libft *libft, void *s, size_t n);
void						*safe_memchr(t_libft *libft, const void *s, int c, size_t n);
int							safe_memcmp(t_libft *libft, const void *s1, const void *s2, size_t n);
void						*safe_memdup(t_libft *libft, const void *src, size_t size);

/* ************************************************************************* */
/*                              SAFE FREE FUNCTIONS                           */
/* ************************************************************************* */
void						safe_free_ptr(t_libft *libft, void **ptr);
void						safe_free_double_ptr(t_libft *libft, void ***ptr);

/* ************************************************************************* */
/*                            SAFE MATH FUNCTIONS                            */
/* ************************************************************************* */
int							safe_max(t_libft *libft, int a, int b);
int							safe_min(t_libft *libft, int a, int b);
long long					safe_max_ll(t_libft *libft, long long a, long long b);
long long					safe_min_ll(t_libft *libft, long long a, long long b);
int							safe_abs(t_libft *libft, int n);
long long					safe_abs_ll(t_libft *libft, long long n);
double						safe_pow(t_libft *libft, double x, double y);
float						safe_powf(t_libft *libft, float x, float y);
double						safe_sin(t_libft *libft, double x);
float						safe_sinf(t_libft *libft, float x);
double						safe_cos(t_libft *libft, double x);
float						safe_cosf(t_libft *libft, float x);
double						safe_asin(t_libft *libft, double x);
float						safe_asinf(t_libft *libft, float x);
double						safe_acos(t_libft *libft, double x);
float						safe_acosf(t_libft *libft, float x);
double						safe_atan(t_libft *libft, double x);
float						safe_atanf(t_libft *libft, float x);
double						safe_atan2(t_libft *libft, double y, double x);
float						safe_atan2f(t_libft *libft, float y, float x);
int							safe_sqrt(t_libft *libft, int n);
double						safe_sqrt_precise(t_libft *libft, double n, int precision);
long long					safe_factorial(t_libft *libft, int n);
int							safe_gcd(t_libft *libft, int a, int b);
long long					safe_lcm(t_libft *libft, int a, int b);

#endif
