/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:21:59 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/24 01:58:08 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

/**
 * @brief Returns a static buffer containing the path to the current log session directory.
 *
 * This function internally holds a static character array that persists throughout
 * the lifetime of the program. It is filled during `log_init()` and should only
 * be accessed via `log_get_path()` externally.
 *
 * @return A pointer to the static character array holding the log session path.
 */
const char	*log_get_path(void)
{
	static char	path[PATH_MAX];
	return (path);
}

/**
 * @brief Creates the base log directory ("logs/") if it doesn't exist.
 *
 * This function checks whether the `logs/` directory exists and attempts to
 * create it if not. If creation fails, it prints an error and exits the program.
 */
static void	create_base_log_dir(void)
{
	if (access(BASE_LOG_DIR, F_OK) != 0)
	{
		if (mkdir(BASE_LOG_DIR, 0755) < 0)
		{
			ft_dprintf(2, "error: failed to create base log directory: %s\n", BASE_LOG_DIR);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * @brief Creates a timestamped session log directory inside `logs/`.
 *
 * This function generates a directory with the current date and time in the format:
 * `logs/YYYY-MM-DD_HH-MM-SS/`. The full path is stored using `log_get_path()`.
 *
 * If any error occurs during time formatting, memory allocation or directory creation,
 * it prints an error and exits the program.
 */
static void	create_session_log_dir(void)
{
	time_t		now;
	struct tm	*lt;
	char		timestamp[64];
	char		*full_path;

	now = time(NULL);
	lt = localtime(&now);
	if (!lt)
	{
		ft_dprintf(2, "error: failed to get local time.\n");
		exit(EXIT_FAILURE);
	}
	if (strftime(timestamp, sizeof(timestamp), "%Y-%m-%d_%H-%M-%S", lt) == 0)
	{
		ft_dprintf(2, "error: strftime failed.\n");
		exit(EXIT_FAILURE);
	}
	full_path = ft_strjoin(BASE_LOG_DIR, timestamp);
	if (!full_path)
	{
		ft_dprintf(2, "error: memory allocation failed (ft_strjoin).\n");
		exit(EXIT_FAILURE);
	}
	if (mkdir(full_path, 0755) < 0)
	{
		ft_dprintf(2, "error: failed to create session log directory: %s\n", full_path);
		free(full_path);
		exit(EXIT_FAILURE);
	}
	ft_strlcpy((char *)log_get_path(), full_path, PATH_MAX);
	free(full_path);
}

/**
 * @brief Initializes the logging system by creating the required directories.
 *
 * This function ensures the base `logs/` directory exists and creates a
 * timestamped session directory inside it. The resulting path can be accessed
 * using `log_get_path()`.
 */
# if LOG_AUTO_INIT
__attribute__((constructor))
# endif
void	log_init(void)
{
	create_base_log_dir();
	create_session_log_dir();
	log_set_level(LOG_DEBUG);
	log_open();
}
