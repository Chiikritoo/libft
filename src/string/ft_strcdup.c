/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 02:26:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/21 20:19:30 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who duplicates the string 's' until the character 'c'
char	*ft_strcdup(char const *s, char c)
{
	char	*dup;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	dup = ft_calloc(i + 1, sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, i + 1);
	return (dup);
}
