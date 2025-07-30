/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:55:00 by anchikri          #+#    #+#             */
/*   Updated: 2024/07/21 22:55:00 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strcspn(const char *s, const char *reject)
{
	size_t i = 0;

	if (!s || !reject)
		return 0;
	while (s[i] && !ft_strchr(reject, s[i]))
		i++;
	return (i);
}

