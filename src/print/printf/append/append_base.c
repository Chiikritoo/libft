/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:57:58 by anchikri          #+#    #+#             */
/*   Updated: 2025/02/21 21:46:17 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/libft.h"

// function who calculates the length of the number 'n' in the base 'base_len'
static int	len_base(unsigned long long n, int base_len)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

// function who converts an unsigned long long to a string in the base 'base'
static char	*ft_ultoa_base(unsigned long long n, char *base)
{
	int		len;
	char	*tab;
	int		base_len;

	if (!base || ft_strlen(base) < 2)
		return (NULL);
	base_len = ft_strlen(base);
	len = len_base(n, base_len);
	tab = ft_calloc(len + 1, sizeof(char));
	if (!tab)
		return (NULL);
	while (len > 0)
	{
		len--;
		tab[len] = base[n % base_len];
		n /= base_len;
	}
	return (tab);
}

// function who appends the string 'nb_str' to the string 'str'
void	append_base(char **str, unsigned long long n, char *base)
{
	char	*nb_str;

	nb_str = ft_ultoa_base(n, base);
	if (!nb_str)
		return ;
	append_str(str, nb_str);
	free(nb_str);
}
