/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:46:53 by jose-gon          #+#    #+#             */
/*   Updated: 2024/10/09 18:30:11 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	set_line_direction(t_line *line, t_point a, t_point b)
{
	line->dx = fabsf(b.axis[X] - a.axis[X]);
	line->dy = fabsf(b.axis[Y] - a.axis[Y]);
	line->err = line->dx - line->dy;
	if (a.axis[X] < b.axis[X])
		line->sx = 1;
	else
		line->sx = -1;
	if (a.axis[Y] < b.axis[Y])
		line->sy = 1;
	else
		line->sy = -1;
}

void	drawing(bool drawing, t_global *global, t_point strt, t_point a, t_point b)
{
	t_line line = global->line;

	set_line_direction(&line, a, b);
	// if (!into_bounds(a) && !into_bounds(b))
	// 	return ;
	while (1)
	{
		if (into_bounds(a) && drawing)
			mlx_put_pixel(global->bitmap, a.axis[X], a.axis[Y], grad_point(strt,
					a, b));
		else
			return;
		if (fabsf(a.axis[X] - b.axis[X]) <= TOLERANCE && fabsf(a.axis[Y]
				- b.axis[Y]) <= TOLERANCE)
			break ;
		line.e2 = 2 * line.err;
		if (line.e2 > -line.dy)
		{
			line.err -= line.dy;
			a.axis[X] += line.sx;
		}
		if (line.e2 < line.dx)
		{
			line.err += line.dx;
			a.axis[Y] += line.sy;
		}
	}
}

#define NUM_THREADS 4

void *routine(void *args) {
	t_threads *ts = args;
	int	i;
	int	j;

	i = ts->start;
	j = 0;
	while (i < ts->end - 1)
	{
		if (i < ts->global.map.map_length - ts->global.map.limits.axis[X])
			drawing(ts->drawing, &ts->global, ts->proje[i], ts->proje[i], ts->proje[i + (int)ts->global.map.limits.axis[X]]);
		if (j < (ts->global.map.limits.axis[X] - 1))
			drawing(ts->drawing, &ts->global, ts->proje[i], ts->proje[i], ts->proje[i + 1]);
		j++;
		if (j == ts->global.map.limits.axis[X])
			j = 0;
		i++;
	}
	return NULL;
}

void *drawing_routine(void *args) {
	t_threads *ts = args;
	int	i;
	int	j;

	i = ts->start;
	j = 0;
	while (i < ts->end - 1)
	{
		if (i < ts->global.map.map_length - ts->global.map.limits.axis[X])
			drawing(ts->drawing, &ts->global, ts->proje[i], ts->proje[i], ts->proje[i + (int)ts->global.map.limits.axis[X]]);
		if (j < (ts->global.map.limits.axis[X] - 1))
			drawing(ts->drawing, &ts->global, ts->proje[i], ts->proje[i], ts->proje[i + 1]);
		j++;
		if (j == ts->global.map.limits.axis[X])
			j = 0;
		i++;
	}
	return NULL;
}
void paint_lines_threads(t_global *global, t_point *proje) {
	pthread_t threads[NUM_THREADS];
	t_threads ts[NUM_THREADS];
	for (int i = 0; i < NUM_THREADS; i++) {
		ts[i].global = *global;
		ts[i].proje = proje;
		ts[i].drawing = false;
		ts[i].start = i * (global->map.map_length / NUM_THREADS);
		ts[i].end = (i + 1) * (global->map.map_length / NUM_THREADS);
		pthread_create(&threads[i], NULL, routine, (void *)&ts[i]);
	}
	
	pthread_t drawer;
	t_threads drawing_ts;
	drawing_ts.global = *global;
	drawing_ts.proje = proje;
	drawing_ts.drawing = true;
	drawing_ts.start = 0;
	drawing_ts.end = global->map.map_length;
	pthread_create(&drawer, NULL, drawing_routine, (void *)&drawing_ts);
	
	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}
	pthread_join(drawer, NULL);
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
	//paint_lines(global, global->map.cpy_proje);
	
	paint_lines_threads(global, global->map.cpy_proje);
	mlx_image_to_window(global->my_mlx, global->bitmap, 0, 0);
}
