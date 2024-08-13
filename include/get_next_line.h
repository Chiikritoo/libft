/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:33:44 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/13 03:52:53 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "include.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

// =================
//   GET_NEXT_LINE
// =================
char	*get_next_line( int fd);

#endif
