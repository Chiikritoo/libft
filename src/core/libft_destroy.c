/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 21:15:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/19 22:09:37 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	libft_destroy(t_libft *libft)
{
	if (!libft)
		return ;
	if (libft->error_ctx)
		error_ctx_destroy(libft->error_ctx);
	ft_free_ptr((void **)&libft);
} 
