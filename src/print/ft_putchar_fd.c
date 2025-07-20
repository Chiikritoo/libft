/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:50:05 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 18:30:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who writes the character 'c' to the file descriptor 'fd'
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	safe_putchar_fd(t_libft *libft, char c, int fd)
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
	ft_putchar_fd(c, fd);
}
