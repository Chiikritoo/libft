/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:57:02 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/16 02:11:34 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/print.h"

// function who appends the character 'c' to the string 'str'
void	append_char(char **str, char c)
{
	size_t	len;
	char	*tmp;

	len = ft_strlen(*str);
	tmp = ft_realloc(*str, len, len + 2);
	if (!tmp)
		return ;
	*str = tmp;
	(*str)[len] = c;
	(*str)[len + 1] = '\0';
}
