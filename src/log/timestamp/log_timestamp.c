/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:14:24 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/24 00:15:57 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

/**
 * @brief Writes a timestamp in the format [YYYY-MM-DD HH:MM:SS] to the given file descriptor.
 *
 * This is intended to prefix log messages with the current date and time.
 *
 * @param fd The file descriptor to write the timestamp to.
 */
void	log_write_timestamp(int fd)
{
	time_t		now;
	struct tm	*lt;
	char		buffer[64];

	now = time(NULL);
	lt = localtime(&now);
	if (!lt)
		return ;
	if (strftime(buffer, sizeof(buffer), "[%Y-%m-%d %H:%M:%S] ", lt) > 0)
		ft_dprintf(fd, "%s", buffer);
}
