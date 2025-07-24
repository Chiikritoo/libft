/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_level.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:13:10 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/23 23:13:14 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

/**
 * @brief Internal accessor for storing the current log level.
 *
 * This uses a static variable without exposing a global.
 */
static t_log_level	*internal_log_level(void)
{
	static t_log_level	level = LOG_DEBUG;
	return (&level);
}

/**
 * @brief Sets the current log level.
 *
 * Only messages with a level >= to this will be printed.
 *
 * @param level The desired log level.
 */
void	log_set_level(t_log_level level)
{
	*internal_log_level() = level;
}

/**
 * @brief Returns the current log level.
 *
 * @return The active log level set via log_set_level().
 */
t_log_level	log_get_level(void)
{
	return (*internal_log_level());
}
