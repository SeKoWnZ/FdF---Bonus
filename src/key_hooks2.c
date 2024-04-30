/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:39:47 by jose-gon          #+#    #+#             */
/*   Updated: 2024/04/30 18:58:32 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

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
