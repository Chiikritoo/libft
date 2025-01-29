/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:58:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/29 17:26:09 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/libft.h"

// function who appends the unsigned integer 'n' to the string 'str'
void	append_uint(char **str, unsigned int n)
{
	char	*nb_str;

	nb_str = ft_utoa(n);
	if (!nb_str)
		return ;
	append_str(str, nb_str);
	free(nb_str);
}
