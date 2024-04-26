/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric_pers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:21:44 by jose-gon          #+#    #+#             */
/*   Updated: 2024/04/25 19:02:48 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	change_perspective(t_map *map, t_point *proje)
{
	int		i;
	t_point	limits[2];

	limits[0].axis[X] = WINX / 2;
	limits[0].axis[Y] = WINY / 2;
	limits[1].axis[X] = WINX / 2;
	limits[1].axis[Y] = WINY / 2;
	i = -1;
	while (++i < map->map_length)
		isometric(map, &map->points[i], &proje[i], limits);
	i = -1;
	while (++i < map->map_length)
		ft_scale(&proje[i], limits);
}

void	isometric(t_map *map, t_point *point, t_point *proje, t_point *lim)
{
	proje->axis[X] = (point->axis[X] - point->axis[Y]) * cos(M_PI / map->rot_x) + WINX / 2;
	proje->axis[Y] = ((point->axis[X] + point->axis[Y]) * sin(M_PI / map->rot_y) + WINY / 2) - point->axis[Z];
	if (proje->axis[X] < lim[0].axis[X])
		lim[0].axis[X] = proje->axis[X];
	if (proje->axis[X] > lim[1].axis[X])
		lim[1].axis[X] = proje->axis[X];
	if (proje->axis[Y] < lim[0].axis[Y])
		lim[0].axis[Y] = proje->axis[Y];
	if (proje->axis[Y] > lim[1].axis[Y])
		lim[1].axis[Y] = proje->axis[Y];
}

// void	isometric_rotate(t_global *global, t_map *map, t_point *proje)
// {
// 	int i = -1;
// 	while (++i < global->map.map_length)
// 	{
// 		proje->axis[X] = (map->points[i].axis[X] - map->points[i].axis[Y]) * cos(M_PI / map->rot_x) + WINX / 2;
// 		proje->axis[Y] = ((map->points[i].axis[X] + map->points[i].axis[Y]) * sin(M_PI / map->rot_y) + WINY / 2) - map->points[i].axis[Z];
// 	}
// 	map_draw(global);
// 	mlx_image_to_window(global->my_mlx, global->bitmap, 0, 0);
// }
