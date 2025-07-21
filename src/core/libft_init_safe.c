/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_init_safe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 02:35:14 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 13:40:08 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static void	init_safe_check_functions(t_libft *libft)
{
	libft->check.sisalpha = safe_isalpha;
	libft->check.sisdigit = safe_isdigit;
	libft->check.sisalnum = safe_isalnum;
	libft->check.sisascii = safe_isascii;
	libft->check.sisprint = safe_isprint;
}

static void	init_safe_convert_functions(t_libft *libft)
{
	libft->convert.satoi = safe_atoi;
	libft->convert.satoll = safe_atoll;
	libft->convert.sitoa = safe_itoa;
	libft->convert.stolower = safe_tolower;
	libft->convert.stoupper = safe_toupper;
	libft->convert.sutoa = safe_utoa;
}

static void	init_safe_free_functions(t_libft *libft)
{
	libft->free.sfree_ptr = safe_free_ptr;
	libft->free.sfree_double_ptr = safe_free_double_ptr;
}

static void	init_safe_gnl_functions(t_libft *libft)
{
	libft->gnl.sget_next_line = safe_get_next_line;
}

static void	init_safe_list_functions(t_libft *libft)
{
	libft->list.sctx_destroy = safe_ctx_destroy;
	libft->list.sctx_init = safe_ctx_init;
	libft->list.sadd_back = safe_lstadd_back;
	libft->list.sadd_front = safe_lstadd_front;
	libft->list.sclear = safe_lstclear;
	libft->list.sdelone = safe_lstdelone;
	libft->list.siter = safe_lstiter;
	libft->list.slast = safe_lstlast;
	libft->list.smap = safe_lstmap;
	libft->list.snew = safe_lstnew;
	libft->list.ssize = safe_lstsize;
}

static void	init_safe_memory_functions(t_libft *libft)
{
	libft->memory.sbzero = safe_bzero;
	libft->memory.scalloc = safe_calloc;
	libft->memory.smemchr = safe_memchr;
	libft->memory.smemcmp = safe_memcmp;
	libft->memory.smemcpy = safe_memcpy;
	libft->memory.smemdup = safe_memdup;
	libft->memory.smemmove = safe_memmove;
	libft->memory.smemset = safe_memset;
	libft->memory.srealloc = safe_realloc;
}

static void	init_safe_print_functions(t_libft *libft)
{
	libft->print.sprintf = safe_printf;
	libft->print.sdprintf = safe_dprintf;
	libft->print.sputchar_fd = safe_putchar_fd;
	libft->print.sputendl_fd = safe_putendl_fd;
	libft->print.sputnbr_fd = safe_putnbr_fd;
	libft->print.sputstr_fd = safe_putstr_fd;
}

static void	init_safe_string_functions(t_libft *libft)
{
	libft->string.ssplit = safe_split;
	libft->string.sstrcdup = safe_strcdup;
	libft->string.sstrchr = safe_strchr;
	libft->string.sstrcmp = safe_strcmp;
	libft->string.sstrdup = safe_strdup;
	libft->string.sstriteri = safe_striteri;
	libft->string.sstrjoin_f1 = safe_strjoin_f1;
	libft->string.sstrjoin_f2 = safe_strjoin_f2;
	libft->string.sstrjoin_gnl = safe_strjoin_gnl;
	libft->string.sstrjoin = safe_strjoin;
	libft->string.sstrlcat = safe_strlcat;
	libft->string.sstrlcpy = safe_strlcpy;
	libft->string.sstrlen = safe_strlen;
	libft->string.sstrmapi = safe_strmapi;
	libft->string.sstrncmp = safe_strncmp;
	libft->string.sstrndup = safe_strndup;
	libft->string.sstrnstr = safe_strnstr;
	libft->string.sstrrchr = safe_strrchr;
	libft->string.sstrtrim = safe_strtrim;
	libft->string.ssubstr = safe_substr;
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
	libft->file.sget_file = safe_get_file;
	libft->file.ssize = safe_file_size;
	libft->file.sexists = safe_file_exists;
	libft->file.sline_count = safe_file_line_count;
}

static void	init_safe_math_functions(t_libft *libft)
{
	libft->math.smax = safe_max;
	libft->math.smin = safe_min;
	libft->math.smax_ll = safe_max_ll;
	libft->math.smin_ll = safe_min_ll;
	libft->math.sabs = safe_abs;
	libft->math.sabs_ll = safe_abs_ll;
	libft->math.spow = safe_pow;
	libft->math.spowf = safe_powf;
	libft->math.ssqrt = safe_sqrt;
	libft->math.ssqrt_precise = safe_sqrt_precise;
	libft->math.sfactorial = safe_factorial;
	libft->math.sdfactorial = safe_dfactorial;
	libft->math.spgcd = safe_pgcd;
	libft->math.slcm = safe_lcm;
	libft->math.ssin = safe_sin;
	libft->math.scos = safe_cos;
	libft->math.ssinf = safe_sinf;
	libft->math.scosf = safe_cosf;
	libft->math.sasin = safe_asin;
	libft->math.sacos = safe_acos;
	libft->math.satan = safe_atan;
	libft->math.satan2 = safe_atan2;
	libft->math.ssinf = safe_sinf;
	libft->math.scosf = safe_cosf;
	libft->math.sasinf = safe_asinf;
	libft->math.sacosf = safe_acosf;
	libft->math.satanf = safe_atanf;
	libft->math.satan2f = safe_atan2f;
	libft->math.sfloor = safe_floor;
	libft->math.sfloorf = safe_floorf;
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
	return (libft);
}
