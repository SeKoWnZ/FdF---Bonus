/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:46:53 by jose-gon          #+#    #+#             */
/*   Updated: 2024/05/02 18:54:42 by jose-gon         ###   ########.fr       */
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

#define NUM_THREADS 4
#define MAX_LEN global->map_length / NUM_THREADS
typedef struct s_threads
{
	t_global *global;
	t_point *proje;
	int start;
	int end;
}	t_threads;


void *routine(void *args) {
	t_threads *struct = args;
	int	i;
	int	j;

	i = struct->start;
	j = 0;
	while (i < struct->end - 1)
	{
		if (i < struct->global->map.map_length - struct->global->map.limits.axis[X])
			drawing(struct->global, struct->proje[i], struct->proje[i], struct->proje[i + (int)struct->global->map.limits.axis[X]]);
		if (j < (struct->global->map.limits.axis[X] - 1))
			drawing(struct->global, struct->proje[i], struct->proje[i], struct->proje[i + 1]);
		j++;
		if (j == struct->global->map.limits.axis[X])
			j = 0;
		i++;
	}
	return NULL;
}

void paint_lines_threads(t_global *global, t_point *proje) {
	pthread_t threads[NUM_THREADS];
	t_threads struct[NUM_THREADS];
	for (int i = 0; i < NUM_THREADS; i++) {
		struct[i].global = global;
		struct[i].proje = proje;
		struct[i].start = i * MAX_LEN;
		struct[i].end = (i + 1) * MAX_LEN;
		pthread_create(&threads[i], NULL, routine, (void *)&struct[i]);
	}
	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_join(threads[i], NULL);
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
