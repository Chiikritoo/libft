/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:52:18 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/29 17:25:09 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who checks for a white-space character
int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || \
		c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}
