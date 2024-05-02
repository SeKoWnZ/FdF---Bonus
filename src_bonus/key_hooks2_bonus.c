/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:39:47 by jose-gon          #+#    #+#             */
/*   Updated: 2024/05/02 18:45:00 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf_bonus.h>

void	key_perspectives(mlx_key_data_t key, void *param)
{
	t_global	*global;

	global = (t_global *)param;
	if (key.key == MLX_KEY_I && key.action == MLX_PRESS)
	{
		global->map.rot_x = 0.959932;
		global->map.rot_y = 0;
		global->map.rot_z = 0.785398;
		map_projection(global);
	}
	if (key.key == MLX_KEY_O && key.action == MLX_PRESS)
	{
		global->map.rot_x = 0;
		global->map.rot_y = 0;
		global->map.rot_z = 0;
		map_projection(global);
	}
}

void	key_colorize(mlx_key_data_t key, void *param)
{
	t_global	*global;

	global = (t_global *)param;
	if (key.key == MLX_KEY_KP_1 && key.action == MLX_PRESS)
	{
		global->map.colors.groundcolor = RED;
		global->map.colors.topcolor = GREEN;
		global->map.colorize = 1;
		map_projection(global);
	}
	if (key.key == MLX_KEY_KP_2 && key.action == MLX_PRESS)
	{
		global->map.colors.groundcolor = PURPLE;
		global->map.colors.topcolor = YELLOW;
		global->map.colorize = 1;
		map_projection(global);
	}
	if (key.key == MLX_KEY_KP_3 && key.action == MLX_PRESS)
	{
		global->map.colors.groundcolor = BLUE;
		global->map.colors.topcolor = ORANGE;
		global->map.colorize = 1;
		map_projection(global);
	}
}

void	key_resets(mlx_key_data_t key, void *param)
{
	t_global	*global;

	global = (t_global *)param;
	if (key.key == MLX_KEY_KP_0 && key.action == MLX_PRESS)
	{
		global->map.colorize = 2;
		map_projection(global);
	}
	if (key.key == MLX_KEY_BACKSPACE && key.action == MLX_PRESS)
	{
		global->map.scale = global->map.scale_r;
		global->map.y_move = 3;
		global->map.x_move = 0;
		global->map.rot_x = 0.959932;
		global->map.rot_y = 0;
		global->map.rot_z = 0.785398;
		map_projection(global);
	}
}
