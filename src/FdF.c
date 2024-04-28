/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:35:10 by jose-gon          #+#    #+#             */
/*   Updated: 2024/04/29 01:24:30 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

// void	patata()
// {
// 	system("leaks fdf");
// }

void	key_rotations(mlx_key_data_t key, void *param)
{
	t_global	*global;

	global = (t_global *)param;
	if (key.key == MLX_KEY_W && key.action == MLX_PRESS)
	{
		global->map.rot_x += 1 * (M_PI / 180);
		map_projection(global);
	}
	if (key.key == MLX_KEY_D && key.action == MLX_PRESS)
	{
		global->map.rot_z += 1 * (M_PI / 180);
		map_projection(global);
	}
		if (key.key == MLX_KEY_A && key.action == MLX_PRESS)
	{
		global->map.rot_z -= 1 * (M_PI / 180);
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
	key_rotations(key, param);
}

int	mlx_initialize(t_global	*global, char *name)
{
	global->my_mlx = mlx_init(WINX, WINY, name, false);
	if (!global->my_mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	global->bitmap = mlx_new_image(global->my_mlx, WINX, WINY);
	if (!global->bitmap)
	{
		mlx_close_window(global->my_mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	global->map.cpy_proje = malloc(sizeof(t_point) * global->map.map_length);
		if (!global->map.cpy_proje)
			exterminate(ERROR_MEMORY, &global->map, 2);
	return (0);
}

int	main(int argc, char **argv)
{
	t_global	global;

	// atexit(patata);
	if (argc != 2)
		exterminate(ERROR_ARG, &global.map, 0);
	if (ft_strcmp(".fdf", &argv[1][ft_strlen(argv[1]) - 4]))
		exterminate(ERROR_FORMAT, &global.map, 0);
	load_fdf_map(&global.map, argv[1]);
	mlx_initialize(&global, argv[1]);
	map_projection(&global);
	mlx_key_hook(global.my_mlx, &keys_controls, &global);
	mlx_loop(global.my_mlx);
	mlx_terminate(global.my_mlx);
	let_it_go(&global.map, 3);
}
