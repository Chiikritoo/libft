/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:31:59 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/13 03:36:09 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H
# define GARBAGE_H

# include "include.h"

// ==================
//       GARBAGE
// ==================
typedef struct s_garbage
{
	void				*ptr;
	struct s_garbage	*next;
}						t_garbage;

void	*ft_gc_calloc(size_t count, size_t size);
void	ft_clear_garbage(t_garbage **garbage);
void	*ft_garbage(t_garbage **garbage, size_t nmemb, size_t size);

#endif
