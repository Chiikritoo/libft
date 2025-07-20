/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 02:45:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 02:45:36 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

// Couleurs pour les tests
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

void	print_file_content(char **lines, const char *test_name)
{
	printf("\n=== %s ===\n", test_name);
	if (!lines) {
		printf("NULL - Erreur lors de la lecture\n");
		return ;
	}
	
	int i = 0;
	while (lines[i]) {
		printf("Ligne %d: [%s]\n", i + 1, lines[i]);
		i++;
	}
	printf("Total: %d lignes\n", i);
}

void	test_ft_get_file(void)
{
	printf("\n" YELLOW "=== TEST ft_get_file ===" RESET "\n");
	
	// Test avec un fichier existant
	char **lines = ft_get_file("test_file.txt");
	print_file_content(lines, "ft_get_file - fichier normal");
	
	if (lines) {
		// Libérer la mémoire
		int i = 0;
		while (lines[i]) {
			free(lines[i]);
			i++;
		}
		free(lines);
	}
	
	// Test avec un fichier inexistant
	char **invalid = ft_get_file("fichier_inexistant.txt");
	print_file_content(invalid, "ft_get_file - fichier inexistant");
	
	// Test avec NULL
	char **null_test = ft_get_file(NULL);
	print_file_content(null_test, "ft_get_file - filename NULL");
}

void	test_safe_get_file(t_libft *libft)
{
	printf("\n" YELLOW "=== TEST safe_get_file ===" RESET "\n");
	
	// Test avec un fichier existant
	char **lines = safe_get_file(libft, "test_file.txt");
	print_file_content(lines, "safe_get_file - fichier normal");
	
	if (lines) {
		// Libérer la mémoire
		int i = 0;
		while (lines[i]) {
			free(lines[i]);
			i++;
		}
		free(lines);
	}
	
	// Test avec un fichier inexistant
	char **invalid = safe_get_file(libft, "fichier_inexistant.txt");
	print_file_content(invalid, "safe_get_file - fichier inexistant");
	
	// Test avec NULL
	char **null_test = safe_get_file(libft, NULL);
	print_file_content(null_test, "safe_get_file - filename NULL");
}

void	test_gc_get_file(t_libft *libft)
{
	printf("\n" YELLOW "=== TEST gc_get_file ===" RESET "\n");
	
	// Test avec un fichier existant
	char **lines = gc_get_file(libft->gc_ctx, "test_file.txt");
	print_file_content(lines, "gc_get_file - fichier normal");
	
	// Pas besoin de libérer manuellement, le GC s'en charge
	
	// Test avec un fichier inexistant
	char **invalid = gc_get_file(libft->gc_ctx, "fichier_inexistant.txt");
	print_file_content(invalid, "gc_get_file - fichier inexistant");
	
	// Test avec NULL
	char **null_test = gc_get_file(libft->gc_ctx, NULL);
	print_file_content(null_test, "gc_get_file - filename NULL");
}

int	main(void)
{
	printf(GREEN "=== TEST DE ft_get_file ===" RESET "\n");
	
	t_libft *libft = libft_init();
	if (!libft) {
		printf(RED "Failed to initialize libft\n" RESET);
		return (1);
	}
	
	test_ft_get_file();
	test_safe_get_file(libft);
	test_gc_get_file(libft);
	
	printf("\n" GREEN "=== TESTS TERMINÉS ===" RESET "\n");
	printf("Le garbage collector nettoiera automatiquement la mémoire\n");
	
	libft_destroy(libft);
	return (0);
} 
