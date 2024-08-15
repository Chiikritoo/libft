/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:16:39 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 15:36:04 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/string.h"

char	*ft_strrchr(char const *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (s[i] != (unsigned char)c)
	{
		if (i == 0)
			return (0);
		i--;
	}
	return ((char *) &s[i]);
}
