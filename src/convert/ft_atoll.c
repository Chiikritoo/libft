/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 06:31:13 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 02:21:33 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

long long	ft_atoll(const char *nptr)
{
	int			i;
	long long	nb;
	int			op;

	i = 0;
	nb = 0;
	op = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			op = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
		nb = nb * 10 + nptr[i++] - 48;
	return (nb * op);
}

long long	safe_atoll(t_libft *libft, const char *str)
{
	long long	result;

	if (!libft)
		return (0);
	if (!str)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"string is null");
		PRINT_ERROR(libft->error_ctx);
		return (0);
	}
	result = ft_atoll(str);
	return (result);
}
