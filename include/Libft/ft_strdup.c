/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:03:56 by jose-gon          #+#    #+#             */
/*   Updated: 2023/09/26 14:07:10 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*point;
	size_t	len;

	len = (ft_strlen(s1) + 1);
	point = malloc(len);
	if (point == 0)
		return (0);
	return (ft_memcpy(point, s1, len));
}
