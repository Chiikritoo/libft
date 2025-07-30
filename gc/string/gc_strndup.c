/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 02:23:59 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/30 02:09:09 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function who duplicates the first 'n' characters of the string 's'
char	*gc_strndup(t_gc_ctx *ctx, char const *s, size_t n)
{
	char	*dup;

	if (!s)
		return (NULL);
	dup = gc_calloc(ctx, n + 1, sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, n + 1);
	return (dup);
}
