/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:42:06 by jose-gon          #+#    #+#             */
/*   Updated: 2023/09/25 10:59:12 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	char	*src2;

	i = 0;
	src2 = (char *)src;
	if (dstsize == 0)
		return (ft_strlen(src2));
	while (i < dstsize - 1 && src2[i] != '\0')
	{
		dst[i] = src2[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src2));
}
