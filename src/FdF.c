/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:35:10 by jose-gon          #+#    #+#             */
/*   Updated: 2024/04/30 17:47:16 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

// void	patata()
// {
// 	system("leaks fdf");
// }

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
	mlx_put_string(global.my_mlx, MENU, 10, 10);
	mlx_put_string(global.my_mlx, MENU1, 10, 30);
	mlx_put_string(global.my_mlx, MENU2, 10, 50);
	mlx_put_string(global.my_mlx, MENU3, 10, 70);
	mlx_put_string(global.my_mlx, MENU4, 10, 90);
	mlx_put_string(global.my_mlx, MENU5, 10, 110);
	mlx_put_string(global.my_mlx, MENU6, 10, 130);
	mlx_put_string(global.my_mlx, MENU7, 10, 150);
	mlx_put_string(global.my_mlx, MENU8, 10, 170);
	mlx_key_hook(global.my_mlx, &keys_controls, &global);
	mlx_loop(global.my_mlx);
	mlx_terminate(global.my_mlx);
	let_it_go(&global.map, 3);
}
