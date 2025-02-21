/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:58:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/21 21:37:54 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/libft.h"

// function who appends the unsigned integer 'n' to the string 'str'
void	append_uint(char **str, unsigned int n)
{
	char	*nb_str;

	if (!str)
		return ;
	nb_str = ft_utoa(n);
	if (!nb_str)
		return ;
	append_str(str, nb_str);
	free(nb_str);
}
