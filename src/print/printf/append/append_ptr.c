/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:58:16 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 15:30:55 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/print.h"

void	append_ptr(char **str, unsigned long n)
{
	append_str(str, "0x");
	append_base(str, n, "0123456789abcdef");
}
