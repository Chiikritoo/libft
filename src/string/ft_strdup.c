/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:20:22 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/29 17:25:48 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who duplicates the string 's'
char	*ft_strdup(char const *s)
{
	char	*dup;

	dup = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, ft_strlen(s) + 1);
	return (dup);
}
