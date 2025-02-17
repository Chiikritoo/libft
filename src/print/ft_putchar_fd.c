/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:50:05 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/17 07:45:56 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who writes the character 'c' to the file descriptor 'fd'
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
