/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_route.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:55:34 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/24 00:57:35 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

/**
 * @brief Route a log message to the appropriate logging function based on the log level.
 * 
 * This function determines which logging function to call based on the provided log level.
 * It handles debug, info, warning, and error messages.
 * 
 * @param level The log level of the message.
 * @param file The file name where the log message is generated.
 * @param line The line number where the log message is generated.
 * @param func The function name where the log message is generated.
 * @param fmt The format string for the log message.
 * @param ... Additional arguments to format the log message.
 */
void	log_route(t_log_level level, const char *file, int line, const char *func, const char *fmt, ...)
{
	va_list	args;

	va_start(args, fmt);
	switch (level)
	{
		case LOG_DEBUG:
			log_debug(file, line, func, fmt, args);
			break ;
		case LOG_INFO:
			log_info(file, line, func, fmt, args);
			break ;
		case LOG_WARNING:
			log_warning(file, line, func, fmt, args);
			break ;
		case LOG_ERROR:
			log_error(file, line, func, fmt, args);
			break ;
		default:
			break ;
	}
}
