/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:18:27 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/13 03:38:24 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FD_H
# define FD_H

# include "include.h"

// ==============
//  FD FUNCTIONS
// ==============
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
