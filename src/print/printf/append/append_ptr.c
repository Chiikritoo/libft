/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:58:16 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/22 01:14:16 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/libft.h"

// function who appends the pointer 'n' to the string 'str'
void	append_ptr(t_buffer *buf, void *ptr)
{
	if (!buf)
		return ;
	if (!ptr)
		append_str(buf, "0x0");
	else
	{
		append_str(buf, "0x");
		append_base(buf, (unsigned long)ptr, "0123456789abcdef");
	}
}
