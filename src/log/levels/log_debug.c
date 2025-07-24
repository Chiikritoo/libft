/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:41:35 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/24 00:56:18 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

/**
 * @brief Logs a debug message.
 *
 * Calls the internal log_message function with the [DEBUG] tag.
 *
 * @param fmt Format string (printf-style).
 * @param ... Additional values to format.
 */
void	log_debug(const char *file, int line, const char *func, const char *fmt, va_list args)
{
	if (LOG_DEBUG < log_get_level())
		return ;

	log_message(LOG_DEBUG, "[DEBUG]", fmt, file, line, func, args);
}
