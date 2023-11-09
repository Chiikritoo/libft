/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:37:58 by anchikri          #+#    #+#             */
/*   Updated: 2023/10/23 19:02:06 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	functions convert lowercase letters to uppercase
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
