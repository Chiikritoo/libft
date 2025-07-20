/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_file_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 02:53:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 02:56:29 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

// Couleurs pour les tests
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

int	main(void)
{
	printf(GREEN "=== TEST ft_file_size et ft_file_exists ===" RESET "\n\n");
	
	t_libft *libft = libft_init();
	if (!libft) {
		printf(RED "Failed to initialize libft\n" RESET);
		return (1);
	}
	
	// Test ft_file_exists
	printf(YELLOW "=== Test ft_file_exists ===" RESET "\n");
	printf("test_file.txt existe: %s\n", ft_file_exists("test_file.txt") ? "OUI" : "NON");
	printf("fichier_inexistant.txt existe: %s\n", ft_file_exists("fichier_inexistant.txt") ? "OUI" : "NON");
	printf("NULL existe: %s\n", ft_file_exists(NULL) ? "OUI" : "NON");
	
	// Test ft_file_size
	printf("\n" YELLOW "=== Test ft_file_size ===" RESET "\n");
	long long size = ft_file_size("test_file.txt");
	printf("Taille de test_file.txt: %lld octets\n", size);
	
	size = ft_file_size("fichier_inexistant.txt");
	printf("Taille de fichier_inexistant.txt: %lld octets\n", size);
	
	size = ft_file_size(NULL);
	printf("Taille de NULL: %lld octets\n", size);
	
	// Test versions safe
	printf("\n" YELLOW "=== Test versions safe ===" RESET "\n");
	printf("safe_file_exists(test_file.txt): %s\n", safe_file_exists(libft, "test_file.txt") ? "OUI" : "NON");
	printf("safe_file_exists(NULL): %s\n", safe_file_exists(libft, NULL) ? "OUI" : "NON");
	
	size = safe_file_size(libft, "test_file.txt");
	printf("safe_file_size(test_file.txt): %lld octets\n", size);
	
	size = safe_file_size(libft, "fichier_inexistant.txt");
	printf("safe_file_size(fichier_inexistant.txt): %lld octets\n", size);
	
	// Test avec libft->file
	printf("\n" YELLOW "=== Test avec libft->file ===" RESET "\n");
	printf("libft->file.file_exists(test_file.txt): %s\n", libft->file.file_exists("test_file.txt") ? "OUI" : "NON");
	size = libft->file.file_size("test_file.txt");
	printf("libft->file.file_size(test_file.txt): %lld octets\n", size);
	
	// Test ft_file_line_count
	printf("\n" YELLOW "=== Test ft_file_line_count ===" RESET "\n");
	int line_count = ft_file_line_count("test_file.txt");
	printf("Nombre de lignes dans test_file.txt: %d\n", line_count);
	
	line_count = ft_file_line_count("fichier_inexistant.txt");
	printf("Nombre de lignes dans fichier_inexistant.txt: %d\n", line_count);
	
	line_count = ft_file_line_count(NULL);
	printf("Nombre de lignes dans NULL: %d\n", line_count);
	
	// Test version safe
	printf("\n" YELLOW "=== Test safe_file_line_count ===" RESET "\n");
	line_count = safe_file_line_count(libft, "test_file.txt");
	printf("safe_file_line_count(test_file.txt): %d\n", line_count);
	
	line_count = safe_file_line_count(libft, "fichier_inexistant.txt");
	printf("safe_file_line_count(fichier_inexistant.txt): %d\n", line_count);
	
	// Test avec libft->file
	printf("\n" YELLOW "=== Test libft->file.file_line_count ===" RESET "\n");
	line_count = libft->file.file_line_count("test_file.txt");
	printf("libft->file.file_line_count(test_file.txt): %d\n", line_count);
	
	printf("\n" GREEN "=== TESTS TERMINÉS ===" RESET "\n");
	
	libft_destroy(libft);
	return (0);
} 
