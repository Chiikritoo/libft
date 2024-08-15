/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:10:37 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 00:10:37 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/string.h"

char	*ft_strjoin_free(char *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*s3;

	if (!s1)
	{
		s1 = ft_calloc(1, sizeof(char));
		if (!s1)
			return (NULL);
	}
	if (!s2)
		return (free(s1), NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s3 = (char *)ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!s3)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(s3, s1, len_s1 + 1);
	ft_strlcat(s3, s2, len_s1 + len_s2 + 1);
	free(s1);
	return (s3);
}
