/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:18:27 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 00:01:50 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "include.h"

// ==================
//  APPEND FUNCTIONS
// ==================
void	append_char(char **str, char c);
void	append_str(char **str, char *s);
void	append_int(char **str, int n);
void	append_uint(char **str, unsigned int n);
void	append_base(char **str, unsigned long long n, char *base);
void	append_ptr(char **str, unsigned long n);

int		ft_printf(const char *s, ...);
int		ft_dprintf(int fd, const char *s, ...);
void	handle_format(va_list ap, char **str, char c);

// ==============
//  FD FUNCTIONS
// ==============
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
