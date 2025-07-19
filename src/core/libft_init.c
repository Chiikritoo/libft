/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 21:10:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/19 22:19:58 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static void	init_check_functions(t_libft *libft)
{
	libft->check.isalpha = ft_isalpha;
	libft->check.isdigit = ft_isdigit;
	libft->check.isalnum = ft_isalnum;
	libft->check.isascii = ft_isascii;
	libft->check.isprint = ft_isprint;
}

static void	init_convert_functions(t_libft *libft)
{
	libft->convert.atoi = ft_atoi;
	libft->convert.atoll = ft_atoll;
	libft->convert.itoa = ft_itoa;
	libft->convert.tolower = ft_tolower;
	libft->convert.toupper = ft_toupper;
	libft->convert.utoa = ft_utoa;
}

static void	init_free_functions(t_libft *libft)
{
	libft->free.free_ptr = ft_free_ptr;
	libft->free.free_double_ptr = ft_free_double_ptr;
}

static void	init_gnl_functions(t_libft *libft)
{
	libft->gnl.get_next_line = get_next_line;
}

static void	init_list_functions(t_libft *libft)
{
	libft->list.ctx_destroy = ft_ctx_destroy;
	libft->list.ctx_init = ft_ctx_init;
	libft->list.add_back = ft_lstadd_back;
	libft->list.add_front = ft_lstadd_front;
	libft->list.clear = ft_lstclear;
	libft->list.delone = ft_lstdelone;
	libft->list.iter = ft_lstiter;
	libft->list.last = ft_lstlast;
	libft->list.map = ft_lstmap;
	libft->list.new = ft_lstnew;
	libft->list.size = ft_lstsize;
}

static void	init_memory_functions(t_libft *libft)
{
	libft->memory.bzero = ft_bzero;
	libft->memory.calloc = ft_calloc;
	libft->memory.memchr = ft_memchr;
	libft->memory.memcmp = ft_memcmp;
	libft->memory.memcpy = ft_memcpy;
	libft->memory.memdup = ft_memdup;
	libft->memory.memmove = ft_memmove;
	libft->memory.memset = ft_memset;
	libft->memory.realloc = ft_realloc;
}

static void	init_print_functions(t_libft *libft)
{
	libft->print.printf = ft_printf;
	libft->print.dprintf = ft_dprintf;
	libft->print.putchar_fd = ft_putchar_fd;
	libft->print.putendl_fd = ft_putendl_fd;
	libft->print.putnbr_fd = ft_putnbr_fd;
	libft->print.putstr_fd = ft_putstr_fd;
}

static void	init_string_functions(t_libft *libft)
{
	libft->string.split = ft_split;
	libft->string.strcdup = ft_strcdup;
	libft->string.strchr = ft_strchr;
	libft->string.strcmp = ft_strcmp;
	libft->string.strdup = ft_strdup;
	libft->string.striteri = ft_striteri;
	libft->string.strjoin_f1 = ft_strjoin_f1;
	libft->string.strjoin_f2 = ft_strjoin_f2;
	libft->string.strjoin_gnl = ft_strjoin_gnl;
	libft->string.strjoin = ft_strjoin;
	libft->string.strlcat = ft_strlcat;
	libft->string.strlcpy = ft_strlcpy;
	libft->string.strlen = ft_strlen;
	libft->string.strmapi = ft_strmapi;
	libft->string.strncmp = ft_strncmp;
	libft->string.strndup = ft_strndup;
	libft->string.strnstr = ft_strnstr;
	libft->string.strrchr = ft_strrchr;
	libft->string.strtrim = ft_strtrim;
	libft->string.substr = ft_substr;
}

t_libft	*libft_init(void)
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
	// init_error_functions(&libft->error);
	init_check_functions(libft);
	init_convert_functions(libft);
	init_free_functions(libft);
	init_gnl_functions(libft);
	init_list_functions(libft);
	init_memory_functions(libft);
	init_print_functions(libft);
	init_string_functions(libft);
	return (libft);
} 
