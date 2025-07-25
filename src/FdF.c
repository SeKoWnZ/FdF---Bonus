/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:35:10 by jose-gon          #+#    #+#             */
/*   Updated: 2024/05/02 19:02:54 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	keys_controls(mlx_key_data_t key, void *param)
{
	t_global	*global;

	global = (t_global *)param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window((mlx_t *)global->my_mlx);
}

int	mlx_initialize(t_global *global, char *name)
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
