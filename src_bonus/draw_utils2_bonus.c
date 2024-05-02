/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 20:56:13 by jose-gon          #+#    #+#             */
/*   Updated: 2024/05/02 17:18:38 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	draw_menu(mlx_t *my_mlx)
{
	mlx_put_string(my_mlx, MENU, 10, 10);
	mlx_put_string(my_mlx, MENU1, 10, 30);
	mlx_put_string(my_mlx, MENU2, 10, 50);
	mlx_put_string(my_mlx, MENU3, 10, 70);
	mlx_put_string(my_mlx, MENU4, 10, 90);
	mlx_put_string(my_mlx, MENU5, 10, 110);
	mlx_put_string(my_mlx, MENU6, 10, 130);
	mlx_put_string(my_mlx, MENU7, 10, 150);
	mlx_put_string(my_mlx, MENU8, 10, 170);
	mlx_put_string(my_mlx, MENU9, 10, 190);
	mlx_put_string(my_mlx, MENU10, 10, 210);
	mlx_put_string(my_mlx, MENU11, 10, 230);
	mlx_put_string(my_mlx, MENU12, 10, 250);
	mlx_put_string(my_mlx, MENU13, 10, 270);
	mlx_put_string(my_mlx, MENU14, 10, 1000);
	mlx_put_string(my_mlx, MENU15, 10, 1020);
	mlx_put_string(my_mlx, MENU16, 10, 1040);
}

void	recolorize(t_map *map, t_point *point, unsigned ground, unsigned top)
{
	int	r;
	int	g;
	int	b;

	if (map->max_z == 0 && map->min_z == 0)
		point->color = ground;
	else
	{
		r = get_r(ground) + ((get_r(top) - get_r(ground))
				* color_steps(map->min_z, map->max_z, point->axis[Z]));
		g = get_g(ground) + ((get_g(top) - get_g(ground))
				* color_steps(map->min_z, map->max_z, point->axis[Z]));
		b = get_b(ground) + ((get_b(top) - get_b(ground))
				* color_steps(map->min_z, map->max_z, point->axis[Z]));
		point->color = get_rgba(r, g, b, 255);
	}
}
