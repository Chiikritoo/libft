/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:45:32 by anchikri          #+#    #+#             */
/*   Updated: 2023/11/01 15:45:32 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/libft.h"

void	ft_putchar(char **str, char c)
{
	char	*tmp;

	tmp = ft_realloc(*str, ft_strlen(*str) + 2);
	if (!tmp)
		return ;
	*str = tmp;
	(*str)[ft_strlen(*str)] = c;
}

void	ft_putstr(char **str, char *s)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_realloc(*str, ft_strlen(*str) + ft_strlen(s) + 1);
	if (!tmp)
		return ;
	*str = tmp;
	ft_strlcpy(*str + ft_strlen(*str), s, ft_strlen(s) + 1);
}
