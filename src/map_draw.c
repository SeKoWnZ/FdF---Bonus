/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:46:53 by jose-gon          #+#    #+#             */
/*   Updated: 2024/04/29 01:29:44 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_scale(t_point *point, t_point *lim)
{
	float	scale_l;
	int		x_min;
	int		y_min;

	x_min = 0;
	y_min = 0;
	if (WINX / (lim[1].axis[X] - lim[0].axis[X]) < WINY / (lim[1].axis[Y]
			- lim[0].axis[Y]))
		scale_l = WINX / (lim[1].axis[X] - lim[0].axis[X]);
	else
		scale_l = WINY / (lim[1].axis[Y] - lim[0].axis[Y]);
	x_min = (WINX - (scale_l * (lim[1].axis[X] - lim[0].axis[X]))) / 2;
	y_min = (WINY - (scale_l * (lim[1].axis[Y] - lim[0].axis[Y]))) / 2;
	point->axis[X] = ((point->axis[X] - lim[0].axis[X]) * scale_l) + x_min;
	point->axis[Y] = ((point->axis[Y] - lim[0].axis[Y]) * scale_l) + y_min;
}

void	set_line_param(t_global *global, t_point a, t_point b)
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
	set_line_param(global, a, b);
    while (1)
	{
        if (into_bounds(a))
            mlx_put_pixel(global->bitmap, a.axis[X], a.axis[Y], grad_point(strt, a, b));
        if (fabsf(a.axis[X] - b.axis[X]) <= TOLERANCE && fabsf(a.axis[Y] - b.axis[Y]) <= TOLERANCE)
            break;
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
			drawing(global,proje[i], proje[i], proje[i + (int)global->map.limits.axis[X]]);
		if (j < (global->map.limits.axis[X] - 1))
			drawing(global,proje[i], proje[i], proje[i + 1]);
		j++;
		if (j == global->map.limits.axis[X])
			j = 0;
	}
}

void	map_draw(t_global *global)
{
	int	i;

	i = -1;
	while (++i < global->map.map_length)
	{
		if (into_bounds(global->map.cpy_proje[i]))
			mlx_put_pixel(global->bitmap, global->map.cpy_proje[i].axis[X], global->map.cpy_proje[i].axis[Y],
				global->map.cpy_proje[i].color);
	}
	paint_lines(global, global->map.cpy_proje);
}

void	map_projection(t_global *global)
{
	int i; 
	
	copy_map(global->map.points, global->map.cpy_proje, global->map.map_length);
	change_perspective(&global->map, global->map.cpy_proje);
	i = -1;
	while (++i < global->map.map_length)
	{
		global->map.cpy_proje[i].axis[X] += global->map.x_move;
		global->map.cpy_proje[i].axis[Y] += global->map.y_move;
	}
	if (global->bitmap)
	{
		mlx_delete_image(global->my_mlx, global->bitmap);
		global->bitmap = mlx_new_image(global->my_mlx, WINX, WINY);
	}
	map_draw(global);
	mlx_image_to_window(global->my_mlx, global->bitmap, 0, 0);
}
