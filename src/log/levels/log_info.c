/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:39:07 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/24 00:56:28 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

/**
 * @brief Logs an informational message.
 *
 * Calls the internal log_message function with the [INFO] tag.
 *
 * @param fmt Format string (printf-style).
 * @param ... Additional values to format.
 */
void	log_info(const char *file, int line, const char *func, const char *fmt, va_list args)
{
	if (LOG_INFO < log_get_level())
		return ;

	log_message(LOG_INFO, "[INFO]", fmt, file, line, func, args);
}
