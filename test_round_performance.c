#include "include/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define TEST_ITERATIONS 1000000
#define BENCHMARK_ITERATIONS 5000000

void test_results(void)
{
    printf("=== TESTS DE RÉSULTATS ===\n");
    
    // Test des cas de base
    printf("\n--- Cas de base ---\n");
    printf("ft_round(0.0) = %.1f (attendu: 0.0)\n", ft_round(0.0));
    printf("ft_roundf(0.0f) = %.1f (attendu: 0.0)\n", ft_roundf(0.0f));
    
    // Test des entiers
    printf("\n--- Entiers ---\n");
    printf("ft_round(5.0) = %.1f (attendu: 5.0)\n", ft_round(5.0));
    printf("ft_roundf(5.0f) = %.1f (attendu: 5.0)\n", ft_roundf(5.0f));
    
    // Test des arrondis vers le haut
    printf("\n--- Arrondis vers le haut (>= 0.5) ---\n");
    printf("ft_round(3.5) = %.1f (attendu: 4.0)\n", ft_round(3.5));
    printf("ft_round(3.7) = %.1f (attendu: 4.0)\n", ft_round(3.7));
    printf("ft_round(3.9) = %.1f (attendu: 4.0)\n", ft_round(3.9));
    printf("ft_roundf(3.5f) = %.1f (attendu: 4.0)\n", ft_roundf(3.5f));
    printf("ft_roundf(3.7f) = %.1f (attendu: 4.0)\n", ft_roundf(3.7f));
    
    // Test des arrondis vers le bas (< 0.5)
    printf("\n--- Arrondis vers le bas (< 0.5) ---\n");
    printf("ft_round(3.2) = %.1f (attendu: 3.0)\n", ft_round(3.2));
    printf("ft_round(3.4) = %.1f (attendu: 3.0)\n", ft_round(3.4));
    printf("ft_roundf(3.2f) = %.1f (attendu: 3.0)\n", ft_roundf(3.2f));
    printf("ft_roundf(3.4f) = %.1f (attendu: 3.0)\n", ft_roundf(3.4f));
    
    // Test des nombres négatifs
    printf("\n--- Nombres négatifs ---\n");
    printf("ft_round(-3.2) = %.1f (attendu: -3.0)\n", ft_round(-3.2));
    printf("ft_round(-3.5) = %.1f (attendu: -4.0)\n", ft_round(-3.5));
    printf("ft_round(-3.7) = %.1f (attendu: -4.0)\n", ft_round(-3.7));
    printf("ft_roundf(-3.2f) = %.1f (attendu: -3.0)\n", ft_roundf(-3.2f));
    printf("ft_roundf(-3.5f) = %.1f (attendu: -4.0)\n", ft_roundf(-3.5f));
    
    // Test des grands nombres
    printf("\n--- Grands nombres ---\n");
    printf("ft_round(123456.7) = %.1f (attendu: 123457.0)\n", ft_round(123456.7));
    printf("ft_round(123456.3) = %.1f (attendu: 123456.0)\n", ft_round(123456.3));
    printf("ft_roundf(123456.7f) = %.1f (attendu: 123457.0)\n", ft_roundf(123456.7f));
    
    // Test des petits nombres
    printf("\n--- Petits nombres ---\n");
    printf("ft_round(0.1) = %.1f (attendu: 0.0)\n", ft_round(0.1));
    printf("ft_round(0.5) = %.1f (attendu: 1.0)\n", ft_round(0.5));
    printf("ft_round(0.9) = %.1f (attendu: 1.0)\n", ft_round(0.9));
    printf("ft_roundf(0.1f) = %.1f (attendu: 0.0)\n", ft_roundf(0.1f));
    printf("ft_roundf(0.5f) = %.1f (attendu: 1.0)\n", ft_roundf(0.5f));
}

void test_comparison_with_standard(void)
{
    printf("\n=== COMPARAISON AVEC LES FONCTIONS STANDARD ===\n");
    
    double test_values[] = {3.2, 3.5, 3.7, -3.2, -3.5, 0.1, 0.5, 0.9, 123456.7};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);
    
    printf("%-10s %-15s %-15s %-15s %-15s\n", "Valeur", "ft_round", "round()", "ft_roundf", "roundf()");
    printf("------------------------------------------------------------\n");
    
    for (int i = 0; i < num_tests; i++)
    {
        double val = test_values[i];
        printf("%-10.1f %-15.1f %-15.1f %-15.1f %-15.1f\n", 
               val, ft_round(val), round(val), ft_roundf(val), roundf(val));
    }
}

void benchmark_performance(void)
{
    printf("\n=== BENCHMARK DE PERFORMANCE ===\n");
    
    clock_t start, end;
    double cpu_time_used;
    double test_value = 3.7;
    double result = 0.0;
    
    // Benchmark ft_round
    start = clock();
    for (int i = 0; i < BENCHMARK_ITERATIONS; i++)
    {
        result += ft_round(test_value + i * 0.001);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("ft_round: %.6f secondes (%d iterations, resultat: %.1f)\n", 
           cpu_time_used, BENCHMARK_ITERATIONS, result);
    
    // Benchmark round() standard
    result = 0.0;
    start = clock();
    for (int i = 0; i < BENCHMARK_ITERATIONS; i++)
    {
        result += round(test_value + i * 0.001);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("round():  %.6f secondes (%d iterations, resultat: %.1f)\n", 
           cpu_time_used, BENCHMARK_ITERATIONS, result);
    
    // Benchmark ft_roundf
    result = 0.0;
    start = clock();
    for (int i = 0; i < BENCHMARK_ITERATIONS; i++)
    {
        result += ft_roundf(test_value + i * 0.001);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("ft_roundf: %.6f secondes (%d iterations, resultat: %.1f)\n", 
           cpu_time_used, BENCHMARK_ITERATIONS, result);
    
    // Benchmark roundf() standard
    result = 0.0;
    start = clock();
    for (int i = 0; i < BENCHMARK_ITERATIONS; i++)
    {
        result += roundf(test_value + i * 0.001);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("roundf(): %.6f secondes (%d iterations, resultat: %.1f)\n", 
           cpu_time_used, BENCHMARK_ITERATIONS, result);
}

void test_edge_cases(void)
{
    printf("\n=== CAS LIMITES ===\n");
    
    // Test avec des valeurs très grandes
    printf("ft_round(1e15) = %.1f\n", ft_round(1e15));
    printf("ft_roundf(1e15f) = %.1f\n", ft_roundf(1e15f));
    
    // Test avec des valeurs très petites
    printf("ft_round(1e-15) = %.1f\n", ft_round(1e-15));
    printf("ft_roundf(1e-15f) = %.1f\n", ft_roundf(1e-15f));
    
    // Test avec des valeurs proches de 0.5
    printf("ft_round(0.4999999999999999) = %.1f\n", ft_round(0.4999999999999999));
    printf("ft_round(0.5000000000000001) = %.1f\n", ft_round(0.5000000000000001));
    printf("ft_roundf(0.4999999f) = %.1f\n", ft_roundf(0.4999999f));
    printf("ft_roundf(0.5000001f) = %.1f\n", ft_roundf(0.5000001f));
}

void test_libft_integration(void)
{
    printf("\n=== TEST D'INTÉGRATION LIBFT ===\n");
    
    t_libft *libft = libft_init();
    if (!libft)
    {
        printf("Erreur: Impossible d'initialiser libft\n");
        return;
    }
    
    // Test via la structure libft
    printf("libft->math.round(3.7) = %.1f\n", libft->math.round(3.7));
    printf("libft->math.roundf(3.7f) = %.1f\n", libft->math.roundf(3.7f));
    
    // Test des fonctions safe
    printf("safe_round(libft, 3.7) = %.1f\n", safe_round(libft, 3.7));
    printf("safe_roundf(libft, 3.7f) = %.1f\n", safe_roundf(libft, 3.7f));
    
    // Test avec libft NULL
    printf("safe_round(NULL, 3.7) = %.1f (doit être 0.0)\n", safe_round(NULL, 3.7));
    printf("safe_roundf(NULL, 3.7f) = %.1f (doit être 0.0)\n", safe_roundf(NULL, 3.7f));
    
    libft_destroy(libft);
    printf("Libft détruit avec succès\n");
}

void stress_test(void)
{
    printf("\n=== TEST DE STRESS ===\n");
    
    clock_t start = clock();
    double total_result = 0.0;
    
    for (int i = 0; i < TEST_ITERATIONS; i++)
    {
        double val = (double)i * 0.001;
        total_result += ft_round(val);
        total_result += ft_roundf(val);
    }
    
    clock_t end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Test de stress: %.6f secondes\n", cpu_time_used);
    printf("Résultat total: %.1f\n", total_result);
    printf("Opérations par seconde: %.0f\n", (2.0 * TEST_ITERATIONS) / cpu_time_used);
}

int main(void)
{
    printf("=== TEST COMPLET DE FT_ROUND ET FT_ROUNDF ===\n");
    printf("Compilé le: %s %s\n", __DATE__, __TIME__);
    printf("=============================================\n");
    
    test_results();
    test_comparison_with_standard();
    test_edge_cases();
    test_libft_integration();
    benchmark_performance();
    stress_test();
    
    printf("\n=== FIN DES TESTS ===\n");
    return (0);
} 
