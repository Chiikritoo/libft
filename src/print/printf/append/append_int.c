/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:57:44 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/14 23:59:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/libft.h"

void	append_int(char **str, int n)
{
	char	*nb_str;

	nb_str = ft_itoa(n);
	if (!nb_str)
		return ;
	append_str(str, nb_str);
	free(nb_str);
}
