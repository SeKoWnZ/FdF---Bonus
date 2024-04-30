/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 00:58:10 by jose-gon          #+#    #+#             */
/*   Updated: 2024/04/30 01:52:45 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_scale(mlx_key_data_t key, void *param)
{
	t_global	*global;

	global = (t_global *)param;
	if (key.key == MLX_KEY_KP_SUBTRACT && key.action == MLX_PRESS)
	{
		global->map.scale *= 0.8;
		map_projection(global);
	}
	if (key.key == MLX_KEY_KP_ADD && key.action == MLX_PRESS)
	{
		global->map.scale *= 1.2;
		map_projection(global);		
	}
}

void	key_rotations1(mlx_key_data_t key, void *param)
{
	t_global	*global;

	global = (t_global *)param;
	if (key.key == MLX_KEY_D && key.action == MLX_PRESS)
	{
		global->map.rot_z += 5 * (M_PI / 180);
		map_projection(global);
	}
	if (key.key == MLX_KEY_A && key.action == MLX_PRESS)
	{
		global->map.rot_z -= 5 * (M_PI / 180);
		map_projection(global);
	}
	if (key.key == MLX_KEY_Q && key.action == MLX_PRESS)
	{
		global->map.rot_y += 5 * (M_PI / 180);
		map_projection(global);
	}
	if (key.key == MLX_KEY_E && key.action == MLX_PRESS)
	{
		global->map.rot_y -= 5 * (M_PI / 180);
		map_projection(global);
	}
}

void	key_rotations2(mlx_key_data_t key, void *param)
{
	t_global	*global;

	global = (t_global *)param;
	if (key.key == MLX_KEY_W && key.action == MLX_PRESS)
	{
		global->map.rot_x += 5 * (M_PI / 180);
		map_projection(global);
	}
	if (key.key == MLX_KEY_S && key.action == MLX_PRESS)
	{
		global->map.rot_x -= 5 * (M_PI / 180);
		map_projection(global);
	}
}

void	key_translations(mlx_key_data_t key, void *param)
{
	t_global	*global;

	global = (t_global *)param;
	if (key.key == MLX_KEY_LEFT && key.action == MLX_PRESS)
	{
		global->map.x_move += -5;
		map_projection(global);
	}
	if (key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS)
	{
		global->map.x_move += +5;
		map_projection(global);
	}
	if (key.key == MLX_KEY_UP && key.action == MLX_PRESS)
	{
		global->map.y_move += -5;
		map_projection(global);
	}
	if (key.key == MLX_KEY_DOWN && key.action == MLX_PRESS)
	{
		global->map.y_move += +5;
		map_projection(global);
	}
}

void	keys_controls(mlx_key_data_t key, void *param)
{
	t_global	*global;

	global = (t_global *)param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window((mlx_t *)global->my_mlx);
	key_translations(key, param);
	key_rotations1(key, param);
	key_rotations2(key, param);
	key_scale(key, param);
}