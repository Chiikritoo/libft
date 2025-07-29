/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 23:00:00 by anchikri          #+#    #+#             */
/*   Updated: 2024/07/21 23:00:00 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strpbrk(const char *s, const char *accept)
{
	size_t	i;

	if (!s || !accept)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (ft_strchr(accept, s[i]))
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
