/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:46:53 by jose-gon          #+#    #+#             */
/*   Updated: 2024/05/02 17:47:23 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	set_line_direction(t_global *global, t_point a, t_point b)
{
	global->line.dx = fabsf(b.axis[X] - a.axis[X]);
	global->line.dy = fabsf(b.axis[Y] - a.axis[Y]);
	global->line.err = global->line.dx - global->line.dy;
	if (a.axis[X] < b.axis[X])
		global->line.sx = 1;
	else
		global->line.sx = -1;
	if (a.axis[Y] < b.axis[Y])
		global->line.sy = 1;
	else
		global->line.sy = -1;
}

void	drawing(t_global *global, t_point strt, t_point a, t_point b)
{
	set_line_direction(global, a, b);
	while (1)
	{
		if (into_bounds(a))
			mlx_put_pixel(global->bitmap, a.axis[X], a.axis[Y], grad_point(strt,
					a, b));
		if (fabsf(a.axis[X] - b.axis[X]) <= TOLERANCE && fabsf(a.axis[Y]
				- b.axis[Y]) <= TOLERANCE)
			break ;
		global->line.e2 = 2 * global->line.err;
		if (global->line.e2 > -global->line.dy)
		{
			global->line.err -= global->line.dy;
			a.axis[X] += global->line.sx;
		}
		if (global->line.e2 < global->line.dx)
		{
			global->line.err += global->line.dx;
			a.axis[Y] += global->line.sy;
		}
	}
}

void	paint_lines(t_global *global, t_point *proje)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < global->map.map_length - 1)
	{
		if (i < global->map.map_length - global->map.limits.axis[X])
			drawing(global, proje[i], proje[i], proje[i
				+ (int)global->map.limits.axis[X]]);
		if (j < (global->map.limits.axis[X] - 1))
			drawing(global, proje[i], proje[i], proje[i + 1]);
		j++;
		if (j == global->map.limits.axis[X])
			j = 0;
	}
}

void	map_projection(t_global *global)
{
	int	i;

	i = -1;
	if (global->map.colorize == 1)
		while (++i < global->map.map_length)
			recolorize(&global->map, &global->map.points[i],
				global->map.colors.groundcolor, global->map.colors.topcolor);
	if (global->map.colorize == 2)
		while (++i < global->map.map_length)
			global->map.points[i].color = global->map.points[i].color_r;
	global->map.colorize = 0;
	copy_map(global->map.points, global->map.cpy_proje, global->map.map_length);
	change_perspective(global, global->map.cpy_proje);
	if (global->bitmap)
	{
		mlx_delete_image(global->my_mlx, global->bitmap);
		global->bitmap = mlx_new_image(global->my_mlx, WINX, WINY);
	}
	paint_lines(global, global->map.cpy_proje);
	mlx_image_to_window(global->my_mlx, global->bitmap, 0, 0);
}
