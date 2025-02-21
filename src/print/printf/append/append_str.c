/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:57:35 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/21 21:40:49 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/libft.h"

// function who appends the string 's' to the string 'str'
void	append_str(char **str, char *s)
{
	size_t	len_str;
	size_t	len_s;
	char	*tmp;

	if (!str)
		return ;
	if (!s)
		s = "(null)";
	if (!*str)
	{
		*str = ft_strdup(s);
		return ;
	}
	len_str = ft_strlen(*str);
	len_s = ft_strlen(s);
	tmp = ft_realloc(*str, len_str, len_str + len_s + 1);
	if (!tmp)
		return ;
	*str = tmp;
	ft_memcpy(*str + len_str, s, len_s);
	(*str)[len_str + len_s] = '\0';
}
