/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:52:43 by jose-gon          #+#    #+#             */
/*   Updated: 2023/10/10 12:07:07 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	len;

	len = 0;
	if (n != 0)
	{
		if (n == -2147483648)
			return (11);
		if (n < 0)
		{
			len++;
			n *= -1;
		}
		while (n > 0)
		{
			n = n / 10;
			len++;
		}
	}
	else
		len = 1;
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long		newn;

	i = ft_count(n);
	newn = n;
	str = malloc(i + 1);
	if (!str)
		return (0);
	if (newn == 0)
		str[0] = '0';
	str[i--] = '\0';
	if (newn < 0)
	{
		str[0] = '-';
		newn *= -1;
	}
	while (newn > 0)
	{
		str[i--] = (newn % 10) + '0';
		newn /= 10;
	}
	return (str);
}
