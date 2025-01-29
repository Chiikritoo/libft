/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:57:44 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/29 17:26:09 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/libft.h"

// function who appends the integer 'n' to the string 'str'
void	append_int(char **str, int n)
{
	char	*nb_str;

	nb_str = ft_itoa(n);
	if (!nb_str)
		return ;
	append_str(str, nb_str);
	free(nb_str);
}
