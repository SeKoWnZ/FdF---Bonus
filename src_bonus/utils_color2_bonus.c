/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:31:15 by jose-gon          #+#    #+#             */
/*   Updated: 2024/05/02 18:45:26 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf_bonus.h>

unsigned int	atou_color(t_map *map, char *str)
{
	unsigned int	result;
	unsigned int	num;
	int				i;

	result = 0;
	num = 0;
	i = -1;
	while (++i < 2)
	{
		if (*str >= 'a' && *str <= 'f')
			*str = *str - 32;
		if ((*str >= '0' && *str <= '9') || (*str >= 'A' && *str <= 'F'))
		{
			if (*str >= '0' && *str <= '9')
				num = *str - '0';
			else if (*str >= 'A' && *str <= 'F')
				num = *str - 'A' + 10;
			result = result * 16 + num;
		}
		else
			exterminate(ERROR_COLOR, map, 1);
		str++;
	}
	return (result);
}

int	hex_to_int(t_map *map, char *str)
{
	int	i;
	int	num[4];

	i = -1;
	while (++i < 3)
	{
		if (*str && *str + 1)
		{
			num[i] = atou_color(map, &(*str));
			str = str + 2;
		}
		else
			num[i] = 0;
	}
	if (*str && *str + 1)
		num[3] = atou_color(map, &(*str));
	else
		num[3] = 255;
	return (get_rgba(num[0], num[1], num[2], num[3]));
}

void	point_hex_color(t_map *map, char *value, t_point *point)
{
	char	**hex_color;

	hex_color = ft_split(value, ',');
	if (hex_color[1])
	{
		if (!ft_strncmp("0x", hex_color[1], 2))
			point->hex_color = hex_to_int(map, hex_color[1] + 2);
		else
		{
			ft_free_all(hex_color);
			exterminate(ERROR_COLOR, map, 1);
		}
	}
	else
		point->hex_color = 0;
	ft_free_all(hex_color);
}

void	grade_color(t_map *map, t_point *point)
{
	int	r;
	int	g;
	int	b;

	if (point->hex_color)
	{
		point->color = point->hex_color;
		point->color_r = point->hex_color;
	}
	else
	{
		if (map->max_z == 0 && map->min_z == 0)
			point->color = DEFAULT_GRO;
		else
		{
			r = get_r(DEFAULT_GRO) + ((get_r(DEFAULT_TOP) - get_r(DEFAULT_GRO))
					* color_steps(map->min_z, map->max_z, point->axis[Z]));
			g = get_g(DEFAULT_GRO) + ((get_g(DEFAULT_TOP) - get_g(DEFAULT_GRO))
					* color_steps(map->min_z, map->max_z, point->axis[Z]));
			b = get_b(DEFAULT_GRO) + ((get_b(DEFAULT_TOP) - get_b(DEFAULT_GRO))
					* color_steps(map->min_z, map->max_z, point->axis[Z]));
			point->color = get_rgba(r, g, b, 255);
			point->color_r = get_rgba(r, g, b, 255);
		}
	}
}

void	set_point_color(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->map_length)
		grade_color(map, &map->points[i]);
}
