/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:01:47 by jose-gon          #+#    #+#             */
/*   Updated: 2023/09/25 16:34:36 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*src1;
	size_t	i;
	size_t	j;

	src1 = (char *)src;
	i = 0;
	j = 0;
	while (j < dstsize && dst[j])
		j++;
	while ((i + j + 1) < dstsize && src1[i])
	{
		dst[i + j] = src1[i];
		i++;
	}
	if (j + i < dstsize)
		dst[i + j] = '\0';
	return (j + ft_strlen(src1));
}
