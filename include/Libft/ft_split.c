/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:02:12 by jose-gon          #+#    #+#             */
/*   Updated: 2024/04/25 11:45:30 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_all(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static size_t	ft_word_counter(char const *s, char c)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	if (s[i] && s[0] != c)
	{
		w++;
		i++;
	}
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			w++;
		i++;
	}
	return (w);
}

static char	**ft_split_split(char **splitstr, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] == c)
			j++;
		k = j;
		while (s[j] && s[j] != c)
			j++;
		if (j > k)
		{
			splitstr[i] = ft_substr(s, k, (j - k));
			if (!splitstr[i])
			{
				ft_free_all(splitstr);
				return (NULL);
			}
			i++;
		}
	}
	return (splitstr);
}

char	**ft_split(char const *s, char c)
{
	char	**splitstr;

	if (!s || !c)
		return (0);
	splitstr = (char **)malloc(sizeof(char *) * (ft_word_counter(s, c) + 1));
	if (!splitstr || !s)
		return (0);
	splitstr[ft_word_counter(s, c)] = NULL;
	return (ft_split_split(splitstr, s, c));
}
