/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:36:29 by anchikri          #+#    #+#             */
/*   Updated: 2023/10/23 18:43:12 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function who checks for any printable character including space
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
