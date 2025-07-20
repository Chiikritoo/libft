/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:05:24 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 18:30:54 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who writes the string 's' to the file descriptor 'fd'
void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	safe_putstr_fd(t_libft *libft, char *s, int fd)
{
	t_libft	*safe_libft;

	if (!libft)
	{
		safe_libft = safe_libft_init();
		SET_ERROR(safe_libft->error_ctx, ERROR_MEMORY, ENOMEM,
			"libft is null");
		PRINT_ERROR(safe_libft->error_ctx);
		libft_destroy(safe_libft);
		return ;
	}
	if (fd < 0 || fd >= 1024)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"file descriptor is invalid");
		PRINT_ERROR(libft->error_ctx);
		return ;
	}
	if (!s)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"string is null");
		PRINT_ERROR(libft->error_ctx);
		return ;
	}
	ft_putstr_fd(s, fd);
}
