/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:26:24 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 00:22:59 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s3 = ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, len_s1 + 1);
	ft_strlcat(s3, s2, len_s1 + len_s2 + 1);
	return (s3);
}
