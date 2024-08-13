/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:19:53 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/13 03:40:06 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include "include.h"

// ==================
//      FT_DRINTF
// ==================
int		ft_dprintf(int fd, const char *s, ...);
void	ft_dputchar(char **str, char c);
void	ft_dputstr(char **str, char *s);
void	ft_dputnbr(char **str, int nb);
void	ft_dputnbr_base(char **str, unsigned long nb, char *hex, int dptr);
void	ft_dputnbr_hex(char **str, unsigned long nb, char *hex);

#endif
