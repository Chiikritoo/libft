/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:48:28 by anchikri          #+#    #+#             */
/*   Updated: 2025/01/29 17:25:48 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// function who counts the number of words in the string separated by 'sep'
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

// function who copies the substring of 'str' to the 'tab' at the index 'index'
static int	subcpy(char *str, char **tab, size_t len, int index)
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

// function who splits the string 's' using the character 'c' as a delimiter
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
	tab = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	while (s[i] && k < count_words(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i != j && !subcpy((char *)s + j, tab, i - j, k++))
			return (NULL);
	}
	return (tab);
}
