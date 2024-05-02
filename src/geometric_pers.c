/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric_pers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:21:44 by jose-gon          #+#    #+#             */
/*   Updated: 2024/05/02 18:59:37 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	change_perspective(t_global *global, t_point *proje)
{
	int	i;

	i = -1;
	while (++i < global->map.map_length)
	{
		rotate_z(&global->map, &proje[i]);
		rotate_x(&global->map, &proje[i]);
		rotate_y(&global->map, &proje[i]);
		proje[i].axis[X] += global->map.x_move;
		proje[i].axis[Y] += global->map.y_move;
		proje[i].axis[X] *= global->map.scale;
		proje[i].axis[Y] *= global->map.scale;
		proje[i].axis[X] += (WINX / 2);
		proje[i].axis[Y] += (WINY / 2);
	}
}

void	rotate_x(t_map *map, t_point *a)
{
	float	tmp;

	tmp = a->axis[Y];
	a->axis[Y] = tmp * cos(map->rot_x) - a->axis[Z] * sin(map->rot_x);
	a->axis[Z] = tmp * sin(map->rot_x) + a->axis[Z] * cos(map->rot_x);
}

void	rotate_y(t_map *map, t_point *a)
{
	float	tmp;

	tmp = a->axis[X];
	a->axis[X] = tmp * cos(map->rot_y) + a->axis[Z] * sin(map->rot_y);
	a->axis[Z] = a->axis[Z] * cos(map->rot_y) - tmp * sin(map->rot_y);
}

void	rotate_z(t_map *map, t_point *a)
{
	float	tmp;

	tmp = a->axis[X];
	a->axis[X] = tmp * cos(map->rot_z) - a->axis[Y] * sin(map->rot_z);
	a->axis[Y] = tmp * sin(map->rot_z) + a->axis[Y] * cos(map->rot_z);
}
