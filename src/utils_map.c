/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:35:21 by jose-gon          #+#    #+#             */
/*   Updated: 2024/04/30 01:33:04 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	init_colors(t_colors *colors)
{
	colors->topcolor = DEFAULT_TOP;
	colors->groundcolor = DEFAULT_GRO;
}

void	map_init(t_map *map)
{
	map->points = NULL;
	map->cpy_proje = NULL;
	map->limits.axis[X] = 0;
	map->limits.axis[Y] = 0;
	map->map_length = 0;
	map->max_z = 0;
	map->min_z = 0;
	map->scale = 0;
	map->rot_x = 0;
	map->rot_y = 0;
	map->rot_z = 0;
	map->x_move = 0;
	map->y_move = 0;
	map->map_memory = NULL;
	init_colors(&(map->colors));
}

void	parse_n_size(t_map *map)
{
	int	i;
	int	param;

	i = -1;
	param = 0;
	while (map->map_memory[++i])
	{
		if (ft_isalnum(map->map_memory[i]) && (map->map_memory[i + 1] == ' '
				|| map->map_memory[i + 1] == '\n' || map->map_memory[i
				+ 1] == '\0'))
			param++;
		if (map->map_memory[i + 1] == '\n' || (map->map_memory[i + 1] == '\0'
				&& map->map_memory[i] != '\n'))
		{
			map->limits.axis[Y]++;
			if (param != 0 && map->limits.axis[X] == 0)
				map->limits.axis[X] = param;
			if (param != map->limits.axis[X] && map->map_memory[i + 1])
				exterminate(ERROR_LINE, map, 1);
			param = 0;
		}
	}
	if (map->limits.axis[Y] <= 1)
		exterminate(ERROR_LINES, map, 1);
	map->map_length = map->limits.axis[X] * map->limits.axis[Y];
}

