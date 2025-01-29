/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_f1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:41:41 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/29 17:25:48 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who concatenates the strings 's1' and 's2' and frees 's1'
char	*ft_strjoin_f1(char *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*s3;

	if (!s1)
		return (NULL);
	if (!s2)
		return (free(s1), NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s3 = ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!s3)
		return (free(s1), NULL);
	ft_strlcpy(s3, s1, len_s1 + 1);
	ft_strlcat(s3, s2, len_s1 + len_s2 + 1);
	free(s1);
	return (s3);
}
