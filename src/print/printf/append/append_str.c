/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:57:35 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/14 23:59:51 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/libft.h"

void	append_str(char **str, char *s)
{
	size_t	len_str;
	size_t	len_s;
	char	*tmp;

	len_str = ft_strlen(*str);
	len_s = ft_strlen(s);
	tmp = ft_realloc(*str, len_str, len_str + len_s + 1);
	if (!tmp)
		return ;
	*str = tmp;
	ft_memcpy(*str + len_str, s, len_s);
	(*str)[len_str + len_s] = '\0';
}
