/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:22:11 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/13 03:39:35 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "include.h"

// ==================
//       PRINTF
// ==================
int		ft_printf(const char *s, ...);
void	ft_putchar(char **str, char c);
void	ft_putstr(char **str, char *s);
void	ft_putnbr(char **str, int nb);
void	ft_putnbr_base(char **str, unsigned long nb, char *hex, int ptr);
void	ft_putnbr_hex(char **str, unsigned long nb, char *hex);

#endif
