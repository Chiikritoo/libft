/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_prefix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:42:22 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/23 23:42:35 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

/**
 * @brief Internal static prefix accessor.
 *
 * This function stores and returns a pointer to the current log prefix.
 * It is persistent without being global.
 *
 * @return A reference to the static prefix pointer.
 */
static const char	**get_log_prefix(void)
{
	static const char	*prefix = NULL;
	return (&prefix);
}

/**
 * @brief Sets the prefix used in log messages.
 *
 * @param prefix A static string identifying the log context. Pass NULL to disable.
 */
void	log_set_prefix(const char *prefix)
{
	*get_log_prefix() = prefix;
}

/**
 * @brief Writes the current log prefix to the specified file descriptor.
 *
 * This function is used internally by the log system to prepend a custom
 * module or context prefix (e.g., [RENDER], [AUDIO], [NET]) to each log line.
 * If no prefix has been set via `log_set_prefix(...)`, this function does nothing.
 *
 * @param fd The file descriptor to write the prefix to.
 */
void	log_write_prefix(int fd)
{
	const char *prefix = *get_log_prefix();

	if (prefix)
		ft_dprintf(fd, "[%s] ", prefix);
}
