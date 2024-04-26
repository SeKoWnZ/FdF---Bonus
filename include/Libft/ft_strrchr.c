/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:36:14 by jose-gon          #+#    #+#             */
/*   Updated: 2023/09/21 14:20:18 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = -1;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == (unsigned char) c)
			j = i;
		i++;
	}
	if ((unsigned char) c == '\0' && str[i] == '\0')
		return (&str[i]);
	else if (j >= 0)
		return (&str[j]);
	else
		return (0);
}
