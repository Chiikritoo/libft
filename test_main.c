/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:40:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/19 22:34:35 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int	main(void)
{
	t_libft	*libft;
	char	*result;

	libft = libft_init();
	if (!libft)
	{
		printf("Failed to initialize libft\n");
		return (1);
	}
	
	// Test volontairement incorrect avec un caractère non-alphabétique
	result = safe_itoa(libft, 5);
	printf("Result for '5': %s\n", result);
	
	// Nettoyage
	libft_destroy(libft);
	
	return (0);
}
