/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:48:17 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/24 00:00:53 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

/**
 * @brief Returns the full path to the session log file ("<log_path>/log.txt")
 * 
 * This function uses a static buffer to construct the path to the log file.
 * It combines the current session path (retrieved via `get_log_path()`)
 * and appends "/log.txt" to it.
 * 
 * @return const char* Full path to the log.txt file.
 */
const char	*log_get_file_path(void)
{
	static char	full_path[PATH_MAX];
	const char	*dir_path = log_get_path();
	size_t		len;

	len = ft_strlcpy(full_path, dir_path, PATH_MAX);
	if (len + 9 < PATH_MAX)
		ft_strlcat(full_path, "/log.txt", PATH_MAX);
	else
	{
		ft_dprintf(2, "Error: log file path too long.\n");
		exit(EXIT_FAILURE);
	}
	return (full_path);
}
