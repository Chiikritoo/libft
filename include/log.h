/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:27:54 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/24 02:03:01 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

# include "libft.h"
// Using libft colors instead of separate color.h

# define BASE_LOG_DIR "logs/"

// Option to enable automatic initialization/cleanup
# ifndef LOG_AUTO_INIT
#  define LOG_AUTO_INIT 0
# endif

// Color definitions for log levels
# define ANSI_RESET    RESET
# define ANSI_RED      RED
# define ANSI_GREEN    GREEN
# define ANSI_YELLOW   YELLOW
# define ANSI_BLUE     BLUE
# define ANSI_MAGENTA  MAGENTA
# define ANSI_CYAN     CYAN
# define ANSI_WHITE    WHITE
# define ANSI_GRAY     "\033[90m"

// BOLD is already defined in libft.h

# ifndef PATH_MAX
#  define PATH_MAX 4096
# endif

/**
 * @brief Log a debug message with file, line and function context.
 * 
 * This macro expands to a call to log_debug_internal, injecting metadata
 * such as the current file name, line number and function name.
 *
 * Example:
 * LOG_DEBUG("Player position: %d", pos);
 */
#define LOG(level, fmt, ...) \
	log_route(level, __FILE__, __LINE__, __func__, fmt, ##__VA_ARGS__)
/**
 * @brief Enumeration of available log levels.
 *
 * The logger will only print messages with a level greater than
 * or equal to the current active level set by `log_set_level(...)`.
 */
typedef enum e_log_level
{
	LOG_DEBUG = 0, /**< All messages, including debug. */
	LOG_INFO,      /**< Informational messages only. */
	LOG_WARNING,   /**< Warnings and errors. */
	LOG_ERROR      /**< Errors only. */
}			t_log_level;

/* ************************************************************************** */
/*                               INITIALIZATION                               */
/* ************************************************************************** */
void		log_init(void);
void		log_set_level(t_log_level level);
t_log_level	log_get_level(void);
void		log_set_prefix(const char *prefix);

/* ************************************************************************** */
/*                                MAIN LOGGING                                */
/* ************************************************************************** */
void		log_route(t_log_level level, const char *file, int line, const char *func, const char *fmt, ...);
void		log_message(t_log_level level, const char *tag, const char *fmt, const char *file, int line, const char *func, va_list args);

/* ************************************************************************** */
/*                                 LOG LEVELS                                 */
/* ************************************************************************** */
void		log_debug(const char *file, int line, const char *func, const char *fmt, va_list args);
void		log_info(const char *file, int line, const char *func, const char *fmt, va_list args);
void		log_warning(const char *file, int line, const char *func, const char *fmt, va_list args);
void		log_error(const char *file, int line, const char *func, const char *fmt, va_list args);

/* ************************************************************************* */
/*                              FILE MANAGEMENT                              */
/* ************************************************************************* */
bool		log_open(void);
void		log_close(void);
int			*log_fd(void);

/* ************************************************************************* */
/*                              PATH MANAGEMENT                              */
/* ************************************************************************* */
const char	*log_get_path(void);

/* ************************************************************************** */
/*                                 FORMATTING                                 */
/* ************************************************************************** */
void		log_write_prefix(int fd);
void		log_write_timestamp(int fd);

/* ************************************************************************* */
/*                                  CLEANUP                                  */
/* ************************************************************************* */
void		log_cleanup(void);

#endif
