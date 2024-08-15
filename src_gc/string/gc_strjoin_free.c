/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:10:37 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 00:10:37 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/garbage.h"

char	*gc_strjoin_free(t_gc_ctx *ctx, char *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*s3;

	if (!s1)
	{
		s1 = gc_alloc(ctx, 1, sizeof(char));
		if (!s1)
			return (NULL);
	}
	if (!s2)
		return (ft_free_ptr((void *)s1), NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s3 = gc_calloc(ctx, len_s1 + len_s2 + 1, sizeof(char));
	if (!s3)
	{
		ft_free_ptr((void *)s1);
		return (NULL);
	}
	ft_strlcpy(s3, s1, len_s1 + 1);
	ft_strlcat(s3, s2, len_s1 + len_s2 + 1);
	ft_free_ptr((void *)s1);
	return (s3);
}
