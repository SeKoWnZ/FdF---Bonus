/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 00:58:10 by jose-gon          #+#    #+#             */
/*   Updated: 2024/10/09 17:35:37 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	key_scale(void *param)
{
	t_global	*global;

	global = (t_global *)param;
	if (mlx_is_key_down(global->my_mlx, MLX_KEY_R))
		global->map.scale *= 0.8;
	if (mlx_is_key_down(global->my_mlx, MLX_KEY_T))
		global->map.scale *= 1.2;
}

void	key_rotations1(void *param)
{
	t_global	*global;

	global = (t_global *)param;
	if (mlx_is_key_down(global->my_mlx, MLX_KEY_D))
		global->map.rot_z += 5 * (M_PI / 180);
	if (mlx_is_key_down(global->my_mlx, MLX_KEY_A))
		global->map.rot_z -= 5 * (M_PI / 180);
	if (mlx_is_key_down(global->my_mlx, MLX_KEY_Q))
		global->map.rot_y += 5 * (M_PI / 180);
	if (mlx_is_key_down(global->my_mlx, MLX_KEY_E))
		global->map.rot_y -= 5 * (M_PI / 180);
}

void	key_rotations2(void *param)
{
	t_global	*global;

	global = (t_global *)param;
	if (mlx_is_key_down(global->my_mlx, MLX_KEY_W))
		global->map.rot_x += 5 * (M_PI / 180);
	if (mlx_is_key_down(global->my_mlx, MLX_KEY_S))
		global->map.rot_x -= 5 * (M_PI / 180);
}

void	key_translations(void *param)
{
	t_global	*global;

	global = (t_global *)param;
	if (mlx_is_key_down(global->my_mlx, MLX_KEY_LEFT))
		global->map.x_move += -5;
	if (mlx_is_key_down(global->my_mlx, MLX_KEY_RIGHT))
		global->map.x_move += +5;
	if (mlx_is_key_down(global->my_mlx, MLX_KEY_UP))
		global->map.y_move += -5;
	if (mlx_is_key_down(global->my_mlx, MLX_KEY_DOWN))
		global->map.y_move += +5;
}


void	keys_controls(void *param)
{
	t_global	*global;

	global = (t_global *)param;
	if (mlx_is_key_down(global->my_mlx, MLX_KEY_ESCAPE))
		mlx_close_window((mlx_t *)global->my_mlx);
	key_translations(param);
	key_rotations1(param);
	key_rotations2(param);
	key_scale(param);
	//map_projection_threads(global);
	map_projection(global);

}
