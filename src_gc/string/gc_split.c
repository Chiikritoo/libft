/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:48:28 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 02:44:51 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	count_words(char const *str, char sep)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i])
			words++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (words);
}

static int	subcpy(t_gc_ctx *ctx, char *str, char **tab, size_t len)
{
	*tab = gc_substr(ctx, str, 0, len);
	if (!tab)
		return (0);
	return (1);
}

char	**gc_split(t_gc_ctx *ctx, char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	tab = gc_calloc(ctx, count_words(s, c) + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	while (s[i] && k < count_words(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i != j && !subcpy(ctx, (char *)s + j, tab + k++, i - j))
			return (ft_free_double_ptr((void **)tab), NULL);
	}
	return (tab);
}
