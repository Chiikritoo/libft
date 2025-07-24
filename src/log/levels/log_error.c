/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:41:09 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/24 00:56:41 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

/**
 * @brief Logs an error message.
 *
 * Calls the internal log_message function with the [ERROR] tag.
 *
 * @param fmt Format string (printf-style).
 * @param ... Additional values to format.
 */
void	log_error(const char *file, int line, const char *func, const char *fmt, va_list args)
{
	if (LOG_ERROR < log_get_level())
		return ;

	log_message(LOG_ERROR, "[ERROR]", fmt, file, line, func, args);
}
