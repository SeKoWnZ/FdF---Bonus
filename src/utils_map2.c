/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 20:56:13 by jose-gon          #+#    #+#             */
/*   Updated: 2024/04/26 18:15:06 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	iso_rotate(t_global *global)
{
	int i = -1;

	while (++i < global->map.map_length)
	{
		global->map.cpy_proje[i].axis[X] = global->map.cpy_proje[i].axis[X] * cos(M_PI / 2) - global->map.cpy_proje[i].axis[Y] * sin(M_PI / 2);
		global->map.cpy_proje[i].axis[Y] = global->map.cpy_proje[i].axis[X] * sin(M_PI / 2) + global->map.cpy_proje[i].axis[Y] * cos(M_PI / 2);
	}
}
