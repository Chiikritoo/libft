/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:36:41 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 00:23:53 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include "include.h"

// ==================
//  STRING FUNCTIONS
// ==================
char	**ft_split(char const *s, char c);
char	*ft_strchr(char const *s, int c);
int		ft_strcmp(char const *s1, char const *s2);
char	*ft_strdup(char const *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin_free(char *s1, char const *s2);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, char const *src, size_t size);
size_t	ft_strlcpy(char *dst, char const *src, size_t size);
size_t	ft_strlen(char const *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(char const *s1, char const *s2, size_t n);
char	*ft_strnstr(char const *big, char const *little, size_t len);
char	*ft_strrchr(char const *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
