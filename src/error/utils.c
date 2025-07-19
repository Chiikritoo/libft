/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:35:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/19 22:21:42 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

bool	is_error_type_valid(t_error_type type)
{
	return (type > ERROR_NONE && type <= ERROR_UNKNOWN);
}
