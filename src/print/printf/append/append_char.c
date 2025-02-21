/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:57:02 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/21 20:47:05 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/libft.h"

// function who appends the character 'c' to the string 'str'
void	append_char(char **str, char c)
{
	size_t	len;
	char	*tmp;

	if (!str)
		return ;
	if (!*str)
	{
		*str = ft_calloc(2, sizeof(char));
		if (!*str)
			return ;
		(*str)[0] = c;
		(*str)[1] = '\0';
		return ;
	}
	len = ft_strlen(*str);
	tmp = ft_realloc(*str, len, len + 2);
	if (!tmp)
		return ;
	*str = tmp;
	(*str)[len] = c;
	(*str)[len + 1] = '\0';
}
