/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:03:48 by jose-gon          #+#    #+#             */
/*   Updated: 2023/09/21 12:32:43 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dsti;
	unsigned char	*srce;

	dsti = (unsigned char *)dst;
	srce = (unsigned char *)src;
	i = 0;
	if (!dsti && !srce)
		return (0);
	while (i < n)
	{
		dsti[i] = srce[i];
		i++;
	}
	return (dst);
}
