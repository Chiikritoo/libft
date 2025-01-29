/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:14:08 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/29 17:25:42 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who allocates and returns a substring from the string 's'
char	*gc_substr(t_gc_ctx *ctx, char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return ("");
	if (len_s - start < len)
		len = len_s - start;
	sub = gc_calloc(ctx, len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
