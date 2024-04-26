/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:47:20 by jose-gon          #+#    #+#             */
/*   Updated: 2023/09/22 11:30:59 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dsti;
	unsigned char	*srce;

	dsti = (unsigned char *)dst;
	srce = (unsigned char *)src;
	if (!dsti && !srce)
		return (0);
	if (dsti > srce)
	{
		while (len-- > 0)
			dsti[len] = srce[len];
	}
	else
	{
		ft_memcpy(dsti, srce, len);
	}
	return (dst);
}
