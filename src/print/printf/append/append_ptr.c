/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:58:16 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/29 17:26:09 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/libft.h"

// function who appends the pointer 'n' to the string 'str'
void	append_ptr(char **str, unsigned long n)
{
	append_str(str, "0x");
	append_base(str, n, "0123456789abcdef");
}
