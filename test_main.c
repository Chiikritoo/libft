/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:40:00 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/20 02:24:55 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int	main(void)
{
	t_libft	*libft;
	char	*result;
	t_lst_ctx *list_ctx;
	t_lst *node1, *node2;
	char *str1, *str2;

	libft = libft_init();
	if (!libft)
	{
		printf("Failed to initialize libft\n");
		return (1);
	}
	
	// Test safe_itoa
	result = safe_itoa(libft, 42);
	printf("Result for '42': %s\n", result);
	free(result);
	
	// Test garbage collector intégré
	char *gc_str = libft->gc.strdup(libft->gc_ctx, "Hello GC!");
	printf("GC string: %s\n", gc_str);
	
	// Test listes avec safe functions
	list_ctx = safe_ctx_init(libft);
	if (list_ctx)
	{
		// Allouer dynamiquement les chaînes
		str1 = ft_strdup("Node 1");
		str2 = ft_strdup("Node 2");
		
		node1 = safe_lstnew(libft, str1);
		node2 = safe_lstnew(libft, str2);
		safe_lstadd_back(libft, list_ctx, node1);
		safe_lstadd_back(libft, list_ctx, node2);
		printf("List size: %d\n", safe_lstsize(libft, list_ctx));
		safe_ctx_destroy(libft, list_ctx);
	}
	// free(list_ctx);
	// Nettoyage automatique du GC
	libft_destroy(libft);
	
	return (0);
}
