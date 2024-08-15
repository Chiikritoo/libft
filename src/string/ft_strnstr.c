/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:38:49 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 15:35:59 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/string.h"

char	*ft_strnstr(char const *big, char const *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!big && !len)
		return (NULL);
	if (!*little)
		return ((char *)big);
	while (big[i] && (i + ft_strlen(little)) <= len)
	{
		if (ft_strncmp(big + i, little, ft_strlen(little)) == 0)
			return ((char *) big + i);
		i++;
	}
	return (NULL);
}
