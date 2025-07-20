/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 02:50:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 02:55:45 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"


/**
 * @brief Obtient la taille d'un fichier en octets
 * @param filename Le nom du fichier
 * @return long long Taille du fichier en octets, -1 en cas d'erreur
 * @note Utilise stat() pour obtenir les informations du fichier
 */
long long	ft_file_size(const char *filename)
{
	struct stat	file_stat;

	if (!filename)
		return (-1);
	if (stat(filename, &file_stat) == -1)
		return (-1);
	return ((long long)file_stat.st_size);
}

/**
 * @brief Compte le nombre de lignes dans un fichier
 * @param filename Le nom du fichier
 * @return int Nombre de lignes, -1 en cas d'erreur
 * @note Utilise get_next_line pour compter les lignes
 */
int	ft_file_line_count(const char *filename)
{
	int		fd;
	int		line_count;

	if (!filename)
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	
	line_count = 0;
	while (get_next_line(fd) != NULL)
		line_count++;
	
	close(fd);
	return (line_count);
}

/**
 * @brief Version safe de ft_file_size avec gestion d'erreurs
 * @param libft Instance de libft
 * @param filename Le nom du fichier
 * @return long long Taille du fichier en octets, -1 en cas d'erreur
 */
long long	safe_file_size(t_libft *libft, const char *filename)
{
	long long	result;

	if (!libft || !filename)
	{
		if (libft)
			SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
				"filename is null");
		return (-1);
	}
	result = ft_file_size(filename);
	if (result == -1)
	{
		SET_ERROR(libft->error_ctx, ERROR_IO, errno,
			"Failed to get file size: %s", filename);
		PRINT_ERROR(libft->error_ctx);
	}
	return (result);
}

/**
 * @brief Vérifie si un fichier existe
 * @param filename Le nom du fichier
 * @return int 1 si le fichier existe, 0 sinon
 */
int	ft_file_exists(const char *filename)
{
	struct stat	file_stat;

	if (!filename)
		return (0);
	return (stat(filename, &file_stat) == 0);
}

/**
 * @brief Version safe de ft_file_exists avec gestion d'erreurs
 * @param libft Instance de libft
 * @param filename Le nom du fichier
 * @return int 1 si le fichier existe, 0 sinon
 */
int	safe_file_exists(t_libft *libft, const char *filename)
{
	int	result;

	if (!libft || !filename)
	{
		if (libft)
			SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
				"filename is null");
		return (0);
	}
	result = ft_file_exists(filename);
	return (result);
}

/**
 * @brief Version safe de ft_file_line_count avec gestion d'erreurs
 * @param libft Instance de libft
 * @param filename Le nom du fichier
 * @return int Nombre de lignes, -1 en cas d'erreur
 */
int	safe_file_line_count(t_libft *libft, const char *filename)
{
	int	result;

	if (!libft || !filename)
	{
		if (libft)
			SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
				"filename is null");
		return (-1);
	}
	result = ft_file_line_count(filename);
	if (result == -1)
	{
		SET_ERROR(libft->error_ctx, ERROR_IO, errno,
			"Failed to count lines in file: %s", filename);
		PRINT_ERROR(libft->error_ctx);
	}
	return (result);
}
