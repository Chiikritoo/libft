/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:19:43 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/16 02:20:09 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "include.h"

void	ft_free_double_ptr(void **ptr);
void	ft_free_ptr(void *ptr);
void	ft_free_triple_ptr(void ***ptr);

#endif
