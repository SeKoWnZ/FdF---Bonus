/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric_pers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:21:44 by jose-gon          #+#    #+#             */
/*   Updated: 2024/04/29 17:13:42 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	change_perspective(t_map *map, t_point *proje)
{
	int		i;
	// t_point	limits[2];

	// limits[0].axis[X] = WINX / 2;
	// limits[0].axis[Y] = WINY / 2;
	// limits[1].axis[X] = WINX / 2;
	// limits[1].axis[Y] = WINY / 2;
	// i = -1;
	// while (++i < map->map_length)
	// 	ft_scale(&proje[i], limits);
	// i = -1;
	// while (++i < map->map_length)
	// 	isometric(&map->points[i], &proje[i]);
	i = -1;
	while (++i < map->map_length)
	{
		rotate_z(map, &proje[i]);
		rotate_x(map, &proje[i]);
		rotate_y(map, &proje[i]);
	}
}

void	isometric(t_point *point, t_point *proje)
{
	float	tmp;
	tmp = proje->axis[X];
	proje->axis[X] = (tmp - point->axis[Y]) * cos(M_PI / 6);
	proje->axis[Y] = (tmp + point->axis[Y]) * sin(M_PI / 6) - point->axis[Z];
	// if (proje->axis[X] < lim[0].axis[X])
	// 	lim[0].axis[X] = proje->axis[X];
	// if (proje->axis[X] > lim[1].axis[X])
	// 	lim[1].axis[X] = proje->axis[X];
	// if (proje->axis[Y] < lim[0].axis[Y])
	// 	lim[0].axis[Y] = proje->axis[Y];
	// if (proje->axis[Y] > lim[1].axis[Y])
	// 	lim[1].axis[Y] = proje->axis[Y];
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
