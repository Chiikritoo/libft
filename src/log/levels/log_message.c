/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_message.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:35:09 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/27 04:59:27 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

/**
 * @brief Convert a log level to a color.
 *
 * @param level The log level.
 * @return The color associated with the log level.
 */
const char	*log_level_to_color(t_log_level level)
{
	if (level == LOG_ERROR)
		return (ANSI_RED);
	if (level == LOG_WARNING)
		return (ANSI_YELLOW);
	if (level == LOG_INFO)
		return (ANSI_GREEN);
	if (level == LOG_DEBUG)
		return (ANSI_BLUE);
	return ("");
}

/**
 * @brief Internal function to write a message to the log file (and optionally stderr).
 *
 * @param level   Log level of the message.
 * @param tag     Text tag to prefix the message (e.g. "[INFO]").
 * @param fmt     Format string (like printf).
 * @param args    Argument list.
 */
void	log_message(t_log_level level, const char *tag, const char *fmt, const char *file, int line, const char *func, va_list args)
{
	int			fd;
	va_list		args_copy;
	static bool	first_call = true;

	if (level < log_get_level())
		return ;

	fd = *log_fd();
	if (fd > 2)
	{
		log_write_timestamp(fd);
		log_write_prefix(fd);
		if (level == LOG_DEBUG)
			ft_dprintf(fd, "%s [%s:%d] %s(): ", tag, file, line, func);
		else
			ft_dprintf(fd, "%s ", tag);
		va_copy(args_copy, args);
		if (ft_vdprintf(fd, fmt, args_copy) < 0)
		{
			va_end(args_copy);
			ft_dprintf(2, "error: failed to write to log file\n");
		}
		else
			va_end(args_copy);
		ft_dprintf(fd, "\n");
	}
	else
	{
		if (first_call)
		{
			log_write_timestamp(2);
			ft_dprintf(2, BOLD ANSI_YELLOW"[WARNING]"RESET" log file not opened, writing to stderr only\n");
			first_call = false;
		}
	}

	log_write_timestamp(2);
	log_write_prefix(2);
	if (level == LOG_DEBUG)
		ft_dprintf(2, BOLD"%s%s "RESET"[%s:%d] %s(): ", log_level_to_color(level), tag, file, line, func);
	else
		ft_dprintf(2, BOLD"%s%s "RESET, log_level_to_color(level), tag);
	if (ft_vdprintf(2, fmt, args) < 0)
		ft_dprintf(2, "error: failed to write to stderr\n");
	ft_dprintf(2, "\n");
}

