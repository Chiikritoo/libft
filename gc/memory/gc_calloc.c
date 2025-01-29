/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:00:11 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/29 17:25:42 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

//	function who allocates memory for an array of nmemb elements of size bytes
//	and returns a pointer to the allocated memory. The memory is set to zero
void	*gc_calloc(t_gc_ctx *ctx, size_t nmemb, size_t size)
{
	char	*tab;
	size_t	len;

	if (!nmemb || !size)
		return (gc_calloc(ctx, 0, 0));
	len = nmemb * size;
	if (len / size != nmemb)
		return (NULL);
	tab = gc_calloc(ctx, len, sizeof(char));
	if (!tab)
		return (NULL);
	ft_bzero(tab, len);
	return (tab);
}
