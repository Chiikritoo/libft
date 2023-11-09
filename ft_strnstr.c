/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:38:49 by anchikri          #+#    #+#             */
/*   Updated: 2023/10/27 17:25:42 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
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
