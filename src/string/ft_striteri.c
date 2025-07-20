/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:11:25 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 02:11:46 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who applies the function 'f' to each character of the string 's'
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

void	safe_striteri(t_libft *libft, char *s, void (*f)(unsigned int, char*))
{
	if (!libft)
		return ;
	if (!s)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"string is null");
		PRINT_ERROR(libft->error_ctx);
		return ;
	}
	if (!f)
	{
		SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
			"function pointer is null");
		PRINT_ERROR(libft->error_ctx);
		return ;
	}
	ft_striteri(s, f);
}
