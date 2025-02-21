/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:08:30 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/21 20:20:14 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who calculates the length of the string 's'
size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}
