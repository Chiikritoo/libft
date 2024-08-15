/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:33:36 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 02:11:27 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*gc_strtrim(t_gc_ctx *ctx, char const *s1, char const *set)
{
	size_t	i;

	if (!s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strrchr(set, s1[i]))
		i--;
	return (gc_substr(ctx, s1, 0, i + 1));
}