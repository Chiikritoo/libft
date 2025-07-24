/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:29:10 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/23 23:31:14 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

/**
 * @brief Returns a pointer to the static log file descriptor.
 *
 * This is used internally to keep the log file open during runtime.
 * Initially set to -1, must be set using log_open().
 *
 * @return Pointer to the log file descriptor.
 */
int	*log_fd(void)
{
	static int	fd = -1;
	return (&fd);
}

/**
 * @brief Opens the session log file and stores its file descriptor.
 *
 * This function builds the full path to the log file (session_path/log.txt),
 * opens it in append mode, and stores the file descriptor internally
 * for future use. It should be called once during initialization.
 *
 * @return true if the log file was successfully opened, false otherwise.
 */
bool	log_open(void)
{
	char	*session_path;
	char	*log_file_path;
	int		fd;

	session_path = (char *)log_get_path();
	if (!session_path || *session_path == '\0')
	{
		ft_dprintf(2, "log_open: session path is not initialized\n");
		return (false);
	}
	log_file_path = ft_strjoin(session_path, "/log.txt");
	if (!log_file_path)
	{
		ft_dprintf(2, "log_open: ft_strjoin failed\n");
		return (false);
	}
	fd = open(log_file_path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	free(log_file_path);
	if (fd < 0)
	{
		ft_dprintf(2, "log_open: failed to open log file\n");
		return (false);
	}
	*log_fd() = fd;
	ft_dprintf(fd, "[INIT] Log file opened successfully\n");
	return (true);
}

/**
 * @brief Closes the currently open log file descriptor, if any.
 *
 * This should be called once at the end of the application to properly
 * release the log file resource. After calling, the internal fd is reset.
 */
void	log_close(void)
{
	int	*fd = log_fd();

	if (*fd >= 0)
	{
		ft_dprintf(*fd, "[SHUTDOWN] Log file closed\n");
		close(*fd);
		*fd = -1;
	}
}
