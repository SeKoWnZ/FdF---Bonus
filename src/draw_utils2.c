/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 20:56:13 by jose-gon          #+#    #+#             */
/*   Updated: 2024/05/02 02:10:32 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	draw_menu(mlx_t *my_mlx)
{
	mlx_put_string(my_mlx, MENU, 10, 10);
	mlx_put_string(my_mlx, MENU1, 10, 30);
	mlx_put_string(my_mlx, MENU2, 10, 50);
	mlx_put_string(my_mlx, MENU3, 10, 70);
	mlx_put_string(my_mlx, MENU4, 10, 90);
	mlx_put_string(my_mlx, MENU5, 10, 110);
	mlx_put_string(my_mlx, MENU6, 10, 130);
	mlx_put_string(my_mlx, MENU7, 10, 150);
	mlx_put_string(my_mlx, MENU8, 10, 170);
	mlx_put_string(my_mlx, MENU9, 10, 190);
	mlx_put_string(my_mlx, MENU10, 10, 210);
	mlx_put_string(my_mlx, MENU11, 10, 230);
	mlx_put_string(my_mlx, MENU12, 10, 250);
	mlx_put_string(my_mlx, MENU13, 10, 270);
}