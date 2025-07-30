/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:00:00 by anchikri          #+#    #+#             */
/*   Updated: 2024/07/21 20:00:00 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function who returns a new string which is the reverse of 's'
char	*ft_strrev(const char *s)
{
	size_t	len;
	size_t	i;
	char	*rev;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	rev = ft_calloc(len + 1, sizeof(char));
	if (!rev)
		return (NULL);
	i = 0;
	while (i < len)
	{
		rev[i] = s[len - 1 - i];
		i++;
	}
	return (rev);
}
