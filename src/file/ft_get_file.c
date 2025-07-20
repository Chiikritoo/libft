/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 02:44:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 02:49:26 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include <fcntl.h>

/**
 * @brief Lit un fichier entier et retourne son contenu sous forme de tableau de chaînes
 * @param filename Le nom du fichier à lire
 * @return char** Tableau de chaînes (une par ligne), NULL en cas d'erreur
 * @note Chaque ligne se termine par '\n' sauf la dernière
 * @note Le tableau se termine par NULL
 * @note En cas d'erreur, retourne NULL
 */
char	**ft_get_file(const char *filename)
{
	int		fd;
	char	*line;
	char	**lines;
	int		line_count;
	int		i;

	if (!filename)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line_count = 0;
	while (get_next_line(fd) != NULL)
		line_count++;
	close(fd);
	// Allouer le tableau
	lines = ft_calloc(line_count + 1, sizeof(char *));
	if (!lines)
		return (NULL);
	// Deuxième passe : lire les lignes
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_free_double_ptr((void ***)&lines);
		return (NULL);
	}
	i = 0;
	while (i < line_count)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		lines[i] = line;
		i++;
	}
	lines[i] = NULL; // Terminer le tableau
	close(fd);
	return (lines);
}

/**
 * @brief Version safe de ft_get_file avec gestion d'erreurs
 * @param libft Instance de libft
 * @param filename Le nom du fichier à lire
 * @return char** Tableau de chaînes, NULL en cas d'erreur
 */
char	**safe_get_file(t_libft *libft, const char *filename)
{
	char	**result;

	if (!libft || !filename)
	{
		if (libft)
			SET_ERROR(libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
				"filename is null");
		return (NULL);
	}
	result = ft_get_file(filename);
	if (!result)
	{
		SET_ERROR(libft->error_ctx, ERROR_IO, errno,
			"Failed to read file: %s", filename);
		PRINT_ERROR(libft->error_ctx);
	}
	return (result);
}

/**
 * @brief Version GC de ft_get_file (mémoire gérée automatiquement)
 * @param ctx Contexte du garbage collector
 * @param filename Le nom du fichier à lire
 * @return char** Tableau de chaînes géré par le GC
 */
char	**gc_get_file(t_gc_ctx *ctx, const char *filename)
{
	int		fd;
	char	*line;
	char	**lines;
	int		line_count;
	int		i;

	if (!ctx || !filename)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	// Première passe : compter les lignes
	line_count = 0;
	while (get_next_line(fd) != NULL)
		line_count++;
	close(fd);
	// Allouer le tableau avec le GC
	lines = gc_calloc(ctx, line_count + 1, sizeof(char *));
	if (!lines)
		return (NULL);
	// Deuxième passe : lire les lignes
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = 0;
	while (i < line_count)
	{
		line = gc_get_next_line(ctx, fd);
		if (!line)
			break ;
		lines[i] = line;
		i++;
	}
	lines[i] = NULL; // Terminer le tableau
	close(fd);
	return (lines);
} 
