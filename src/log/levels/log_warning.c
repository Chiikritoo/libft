/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_warning.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:40:29 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/24 00:56:32 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

/**
 * @brief Logs a warning message.
 *
 * Calls the internal log_message function with the [WARNING] tag.
 *
 * @param fmt Format string (printf-style).
 * @param ... Additional values to format.
 */
void	log_warning(const char *file, int line, const char *func, const char *fmt, va_list args)
{
	if (LOG_WARNING < log_get_level())
		return ;

	log_message(LOG_WARNING, "[WARNING]", fmt, file, line, func, args);
}
