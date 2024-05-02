/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:42:43 by jose-gon          #+#    #+#             */
/*   Updated: 2024/05/02 02:14:29 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	init_scale(t_map *map)
{
	float	max;

	if (map->limits.axis[X] > map->limits.axis[Y])
		max = map->limits.axis[X];
	else
		max = map->limits.axis[Y];
	if (max < 25)
		map->scale = 100;
	if (max < 50)
		map->scale = 50;
	else if (max < 100)
		map->scale = 25;
	else if (max < 500)
		map->scale = 5;
	else if (max < 1000)
		map->scale = 2;
	else if (max < 2000)
		map->scale = 1;
	else
		map->scale = 0.5;
	map->scale_r = map->scale;
}

void	split_n_load(t_map *map, char *line, int y_index)
{
	int			i;
	static int	p_index = 0;
	char		**splitted_point;

	i = -1;
	splitted_point = ft_split(line, ' ');
	if (!splitted_point)
		exterminate(ERROR_MEMORY, map, 1);
	while (splitted_point[++i])
	{
		map->points[p_index].axis[X] = i - map->limits.axis[X] / 2;
		map->points[p_index].axis[Y] = y_index - map->limits.axis[Y] / 2;
		map->points[p_index].axis[Z] = ft_atoi(splitted_point[i]);
		point_hex_color(map, splitted_point[i], &map->points[p_index]);
		if (map->points[p_index].axis[Z] < map->min_z)
			map->min_z = map->points[p_index].axis[Z];
		if (map->points[p_index].axis[Z] > map->max_z)
			map->max_z = map->points[p_index].axis[Z];
		p_index++;
	}
	ft_free_all(splitted_point);
}

void	fill_points(t_map *map)
{
	char	*line;
	int		st;
	int		i;
	int		y_index;

	y_index = 0;
	i = 0;
	st = i;
	map->points = ft_calloc(map->map_length, sizeof(t_point));
	if (!map->points)
		exterminate(ERROR_MEMORY, map, 1);
	while (map->map_memory[i])
	{
		if (map->map_memory[i + 1] == '\n'
			|| (map->map_memory[i + 1] == '\0' && map->map_memory[i] != '\n'))
		{
			line = ft_substr(map->map_memory, st, i - st + 1);
			split_n_load(map, line, y_index);
			y_index++;
			free(line);
			st = i + 2;
		}
		i++;
	}
	set_point_color(map);
}

void	read_map(int fd, t_map *map)
{
	char	*tmp;
	char	*buffer;

	buffer = get_next_line(fd);
	if (!buffer)
		exterminate(ERROR_READ, map, 0);
	while (buffer)
	{
		if (!map->map_memory)
		{
			map->map_memory = ft_strdup(buffer);
			if (!map->map_memory)
				exterminate(ERROR_READ, map, 0);
		}
		else
		{
			tmp = map->map_memory;
			map->map_memory = ft_strjoin(map->map_memory, buffer);
			if (!map->map_memory)
				exterminate(ERROR_MEMORY, map, 0);
			free(tmp);
		}
		free(buffer);
		buffer = get_next_line(fd);
	}
}

void	load_fdf_map(t_map *map, char *filemap)
{
	int	fd;

	fd = open(filemap, O_RDONLY);
	if (fd < 2)
		exterminate(ERROR_OPEN, map, 0);
	map_init(map);
	read_map(fd, map);
	if (!map->map_memory)
		exterminate(ERROR_MEMORY, map, 0);
	close(fd);
	parse_n_size(map);
	fill_points(map);
	init_scale(map);
}
