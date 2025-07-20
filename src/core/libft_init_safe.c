/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_init_safe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 02:35:14 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 03:12:02 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static void	init_safe_check_functions(t_libft *libft)
{
	libft->check.isalpha = safe_isalpha;
	libft->check.isdigit = safe_isdigit;
	libft->check.isalnum = safe_isalnum;
	libft->check.isascii = safe_isascii;
	libft->check.isprint = safe_isprint;
}

static void	init_safe_convert_functions(t_libft *libft)
{
	libft->convert.atoi = safe_atoi;
	libft->convert.atoll = safe_atoll;
	libft->convert.itoa = safe_itoa;
	libft->convert.tolower = safe_tolower;
	libft->convert.toupper = safe_toupper;
	libft->convert.utoa = safe_utoa;
}

static void	init_safe_free_functions(t_libft *libft)
{
	libft->free.free_ptr = safe_free_ptr;
	libft->free.free_double_ptr = safe_free_double_ptr;
}

static void	init_safe_gnl_functions(t_libft *libft)
{
	libft->gnl.get_next_line = get_next_line;
}

static void	init_safe_list_functions(t_libft *libft)
{
	libft->list.ctx_destroy = safe_ctx_destroy;
	libft->list.ctx_init = safe_ctx_init;
	libft->list.add_back = safe_lstadd_back;
	libft->list.add_front = safe_lstadd_front;
	libft->list.clear = safe_lstclear;
	libft->list.delone = safe_lstdelone;
	libft->list.iter = safe_lstiter;
	libft->list.last = safe_lstlast;
	libft->list.map = safe_lstmap;
	libft->list.new = safe_lstnew;
	libft->list.size = safe_lstsize;
}

static void	init_safe_memory_functions(t_libft *libft)
{
	libft->memory.bzero = safe_bzero;
	libft->memory.calloc = safe_calloc;
	libft->memory.memchr = safe_memchr;
	libft->memory.memcmp = safe_memcmp;
	libft->memory.memcpy = safe_memcpy;
	libft->memory.memdup = safe_memdup;
	libft->memory.memmove = safe_memmove;
	libft->memory.memset = safe_memset;
	libft->memory.realloc = safe_realloc;
}

static void	init_safe_print_functions(t_libft *libft)
{
	libft->print.printf = ft_printf;
	libft->print.dprintf = ft_dprintf;
	libft->print.putchar_fd = ft_putchar_fd;
	libft->print.putendl_fd = ft_putendl_fd;
	libft->print.putnbr_fd = ft_putnbr_fd;
	libft->print.putstr_fd = ft_putstr_fd;
}

static void	init_safe_string_functions(t_libft *libft)
{
	libft->string.split = safe_split;
	libft->string.strcdup = safe_strcdup;
	libft->string.strchr = safe_strchr;
	libft->string.strcmp = safe_strcmp;
	libft->string.strdup = safe_strdup;
	libft->string.striteri = safe_striteri;
	libft->string.strjoin_f1 = safe_strjoin_f1;
	libft->string.strjoin_f2 = safe_strjoin_f2;
	libft->string.strjoin_gnl = safe_strjoin_gnl;
	libft->string.strjoin = safe_strjoin;
	libft->string.strlcat = safe_strlcat;
	libft->string.strlcpy = safe_strlcpy;
	libft->string.strlen = safe_strlen;
	libft->string.strmapi = safe_strmapi;
	libft->string.strncmp = safe_strncmp;
	libft->string.strndup = safe_strndup;
	libft->string.strnstr = safe_strnstr;
	libft->string.strrchr = safe_strrchr;
	libft->string.strtrim = safe_strtrim;
	libft->string.substr = safe_substr;
}

static void	init_safe_gc_functions(t_libft *libft)
{
	libft->gc.ctx_init = gc_ctx_init;
	libft->gc.ctx_destroy = gc_ctx_destroy;
	libft->gc.calloc = gc_calloc;
	libft->gc.realloc = gc_realloc;
	libft->gc.clear = gc_clear;
	libft->gc.free = gc_free;
	libft->gc.strdup = gc_strdup;
	libft->gc.strcdup = gc_strcdup;
	libft->gc.strndup = gc_strndup;
	libft->gc.strjoin = gc_strjoin;
	libft->gc.strjoin_f1 = gc_strjoin_f1;
	libft->gc.strjoin_f2 = gc_strjoin_f2;
	libft->gc.strjoin_gnl = gc_strjoin_gnl;
	libft->gc.substr = gc_substr;
	libft->gc.split = gc_split;
	libft->gc.itoa = gc_itoa;
	libft->gc.utoa = gc_utoa;
	libft->gc.get_next_line = gc_get_next_line;
}

static void	init_safe_file_functions(t_libft *libft)
{
	libft->file.get_file = safe_get_file;
	libft->file.size = safe_file_size;
	libft->file.exists = safe_file_exists;
	libft->file.line_count = safe_file_line_count;
}

static void	init_safe_math_functions(t_libft *libft)
{
	libft->math.max = safe_max;
	libft->math.min = safe_min;
	libft->math.max_ll = safe_max_ll;
	libft->math.min_ll = safe_min_ll;
	libft->math.abs = safe_abs;
	libft->math.abs_ll = safe_abs_ll;
	libft->math.pow = safe_pow;
	libft->math.sqrt = safe_sqrt;
	libft->math.sqrt_precise = safe_sqrt_precise;
	libft->math.factorial = safe_factorial;
	libft->math.gcd = safe_gcd;
	libft->math.lcm = safe_lcm;
}

t_libft	*safe_libft_init(void)
{
	t_libft	*libft;

	libft = ft_calloc(1, sizeof(t_libft));
	if (!libft)
		return (NULL);
	libft->error_ctx = error_ctx_init();
	if (!libft->error_ctx)
	{
		ft_free_ptr((void **)&libft);
		return (NULL);
	}
	libft->gc_ctx = gc_ctx_init();
	if (!libft->gc_ctx)
	{
		error_ctx_destroy(libft->error_ctx);
		ft_free_ptr((void **)&libft);
		return (NULL);
	}
	init_safe_check_functions(libft);
	init_safe_convert_functions(libft);
	init_safe_free_functions(libft);
	init_safe_gnl_functions(libft);
	init_safe_list_functions(libft);
	init_safe_memory_functions(libft);
	init_safe_print_functions(libft);
	init_safe_string_functions(libft);
	init_safe_file_functions(libft);
	init_safe_math_functions(libft);
	init_safe_gc_functions(libft);
}
