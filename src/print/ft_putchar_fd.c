/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:50:05 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/16 02:08:20 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/print.h"

// function who writes the character 'c' to the file descriptor 'fd'
void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
