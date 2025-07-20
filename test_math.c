/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 03:02:30 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 03:02:37 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include <stdio.h>

void	print_result(const char *test_name, int result, int expected)
{
	if (result == expected)
		printf("\033[32m✓ %s: %d (expected: %d)\033[0m\n", test_name, result, expected);
	else
		printf("\033[31m✗ %s: %d (expected: %d)\033[0m\n", test_name, result, expected);
}

void	print_result_ll(const char *test_name, long long result, long long expected)
{
	if (result == expected)
		printf("\033[32m✓ %s: %lld (expected: %lld)\033[0m\n", test_name, result, expected);
	else
		printf("\033[31m✗ %s: %lld (expected: %lld)\033[0m\n", test_name, result, expected);
}

void	print_result_double(const char *test_name, double result, double expected)
{
	if (result == expected)
		printf("\033[32m✓ %s: %.6f (expected: %.6f)\033[0m\n", test_name, result, expected);
	else
		printf("\033[31m✗ %s: %.6f (expected: %.6f)\033[0m\n", test_name, result, expected);
}

int	main(void)
{
	t_libft	*libft;

	printf("\n\033[1;34m=== TESTING MATH FUNCTIONS ===\033[0m\n\n");

	// Test max/min
	printf("\033[1;33m--- Max/Min Tests ---\033[0m\n");
	print_result("ft_max(5, 3)", ft_max(5, 3), 5);
	print_result("ft_max(3, 5)", ft_max(3, 5), 5);
	print_result("ft_max(-5, 3)", ft_max(-5, 3), 3);
	print_result("ft_max(5, -3)", ft_max(5, -3), 5);
	
	print_result("ft_min(5, 3)", ft_min(5, 3), 3);
	print_result("ft_min(3, 5)", ft_min(3, 5), 3);
	print_result("ft_min(-5, 3)", ft_min(-5, 3), -5);
	print_result("ft_min(5, -3)", ft_min(5, -3), -3);

	print_result_ll("ft_max_ll(5, 3)", ft_max_ll(5, 3), 5);
	print_result_ll("ft_min_ll(5, 3)", ft_min_ll(5, 3), 3);

	// Test abs
	printf("\n\033[1;33m--- Absolute Value Tests ---\033[0m\n");
	print_result("ft_abs(5)", ft_abs(5), 5);
	print_result("ft_abs(-5)", ft_abs(-5), 5);
	print_result("ft_abs(0)", ft_abs(0), 0);
	
	print_result_ll("ft_abs_ll(5)", ft_abs_ll(5), 5);
	print_result_ll("ft_abs_ll(-5)", ft_abs_ll(-5), 5);

	// Test pow
	printf("\n\033[1;33m--- Power Tests ---\033[0m\n");
	print_result_ll("ft_pow(2, 0)", ft_pow(2, 0), 1);
	print_result_ll("ft_pow(2, 1)", ft_pow(2, 1), 2);
	print_result_ll("ft_pow(2, 3)", ft_pow(2, 3), 8);
	print_result_ll("ft_pow(5, 2)", ft_pow(5, 2), 25);
	print_result_ll("ft_pow(2, -1)", ft_pow(2, -1), -1); // Error case

	// Test sqrt
	printf("\n\033[1;33m--- Square Root Tests ---\033[0m\n");
	print_result("ft_sqrt(0)", ft_sqrt(0), 0);
	print_result("ft_sqrt(1)", ft_sqrt(1), 1);
	print_result("ft_sqrt(4)", ft_sqrt(4), 2);
	print_result("ft_sqrt(9)", ft_sqrt(9), 3);
	print_result("ft_sqrt(16)", ft_sqrt(16), 4);
	print_result("ft_sqrt(25)", ft_sqrt(25), 5);
	print_result("ft_sqrt(5)", ft_sqrt(5), 2); // sqrt(5) ≈ 2.236, returns 2
	print_result("ft_sqrt(-1)", ft_sqrt(-1), -1); // Error case

	// Test sqrt_precise
	printf("\n\033[1;33m--- Precise Square Root Tests ---\033[0m\n");
	print_result_double("ft_sqrt_precise(4, 5)", ft_sqrt_precise(4, 5), 2.0);
	print_result_double("ft_sqrt_precise(9, 5)", ft_sqrt_precise(9, 5), 3.0);
	print_result_double("ft_sqrt_precise(2, 5)", ft_sqrt_precise(2, 5), 1.414214);

	// Test factorial
	printf("\n\033[1;33m--- Factorial Tests ---\033[0m\n");
	print_result_ll("ft_factorial(0)", ft_factorial(0), 1);
	print_result_ll("ft_factorial(1)", ft_factorial(1), 1);
	print_result_ll("ft_factorial(5)", ft_factorial(5), 120);
	print_result_ll("ft_factorial(10)", ft_factorial(10), 3628800);
	print_result_ll("ft_factorial(-1)", ft_factorial(-1), -1); // Error case
	print_result_ll("ft_factorial(21)", ft_factorial(21), -1); // Error case (overflow)

	// Test gcd/lcm
	printf("\n\033[1;33m--- GCD/LCM Tests ---\033[0m\n");
	print_result("ft_gcd(12, 18)", ft_gcd(12, 18), 6);
	print_result("ft_gcd(7, 13)", ft_gcd(7, 13), 1);
	print_result("ft_gcd(0, 5)", ft_gcd(0, 5), 5);
	print_result("ft_gcd(-12, 18)", ft_gcd(-12, 18), 6);
	
	print_result_ll("ft_lcm(12, 18)", ft_lcm(12, 18), 36);
	print_result_ll("ft_lcm(7, 13)", ft_lcm(7, 13), 91);
	print_result_ll("ft_lcm(0, 5)", ft_lcm(0, 5), 0);

	// Test with libft interface
	printf("\n\033[1;33m--- Libft Interface Tests ---\033[0m\n");
	libft = libft_init();
	if (libft)
	{
		print_result("libft->math.max(5, 3)", libft->math.max(5, 3), 5);
		print_result("libft->math.min(5, 3)", libft->math.min(5, 3), 3);
		print_result_ll("libft->math.pow(2, 3)", libft->math.pow(2, 3), 8);
		print_result("libft->math.sqrt(16)", libft->math.sqrt(16), 4);
		print_result_ll("libft->math.factorial(5)", libft->math.factorial(5), 120);
		libft_destroy(libft);
	}

	printf("\n\033[1;34m=== MATH TESTS COMPLETED ===\033[0m\n\n");
	return (0);
} 
