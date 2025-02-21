/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:16:39 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/21 20:21:00 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who locates the last occurrence of 'c' in the string 's'
char	*ft_strrchr(char const *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	while (s[i] != (unsigned char)c)
	{
		if (i == 0)
			return (0);
		i--;
	}
	return ((char *) &s[i]);
}
