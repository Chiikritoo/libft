/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:48:28 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/13 03:03:38 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	ft_count_words(char const *str, char sep)
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

static int	ft_subcpy(char *str, char **tab, size_t len, int index)
{
	tab[index] = ft_substr(str, 0, len);
	if (!tab[index])
	{
		while (index > 0)
		{
			index--;
			free(tab[index]);
		}
		free(tab);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
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
	tab = ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	while (s[i] && k < ft_count_words(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i != j && !ft_subcpy((char *)s + j, tab, i - j, k++))
			return (NULL);
	}
	return (tab);
}
