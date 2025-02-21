/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:20:22 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/21 20:15:54 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who duplicates the string 's'
char	*gc_strdup(t_gc_ctx *ctx, const char *s)
{
	int		i;
	char	*dup;

	if (!s)
		return (NULL);
	i = 0;
	dup = gc_calloc(ctx, ft_strlen(s) + 1, sizeof(char));
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}
