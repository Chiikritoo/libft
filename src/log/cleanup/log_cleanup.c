/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_cleanup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 01:15:57 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/24 01:58:13 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

/**
 * @brief Cleans up the log system by closing the log file.
 * 
 * This function closes the log file and frees any allocated resources.
 */
# if LOG_AUTO_INIT
__attribute__((destructor))
# endif
void	log_cleanup(void)
{
	log_close();
}
