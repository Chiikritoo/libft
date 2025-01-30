/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 02:26:46 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/30 02:27:00 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who duplicates the string 's' until the character 'c'
char	*gc_strcdup(t_gc_ctx *ctx, char const *s, char c)
{
	char	*dup;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	dup = gc_calloc(ctx, i + 1, sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, i + 1);
	return (dup);
}
