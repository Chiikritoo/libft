/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strjoin_f2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:48:01 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/22 00:34:18 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who concatenates the strings 's1' and 's2' and frees 's2'
char	*gc_strjoin_f2(t_gc_ctx *ctx, char const *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*s3;

	if (!s2)
		return (NULL);
	if (!s2)
		return (free(s2), NULL);
	len_s1 = ft_strlen(s2);
	len_s2 = ft_strlen(s2);
	s3 = gc_calloc(ctx, len_s1 + len_s2 + 1, sizeof(char));
	if (!s3)
		return (free(s2), NULL);
	ft_strlcpy(s3, s1, len_s1 + 1);
	ft_strlcat(s3, s2, len_s1 + len_s2 + 1);
	free(s2);
	return (s3);
}
