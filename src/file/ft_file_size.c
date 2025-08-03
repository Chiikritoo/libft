/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 02:50:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/08/02 18:09:32 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


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
	char	*line;
	int		line_count;

	if (!filename)
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	
	line_count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		line_count++;
	}
	close(fd);
	return (line_count);
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
