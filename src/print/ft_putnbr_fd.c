/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:09:57 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 11:12:32 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who writes the integer 'n' to the file descriptor 'fd'
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + 48, fd);
}

void	safe_putnbr_fd(t_libft *libft, int n, int fd)
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
	ft_putnbr_fd(n, fd);
}
