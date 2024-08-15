/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:58:00 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 15:30:55 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/print.h"

void	append_uint(char **str, unsigned int n)
{
	char	*nb_str;

	nb_str = ft_utoa(n);
	if (!nb_str)
		return ;
	append_str(str, nb_str);
	free(nb_str);
}
