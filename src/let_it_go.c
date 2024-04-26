/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_it_go.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:21:52 by jose-gon          #+#    #+#             */
/*   Updated: 2024/04/25 12:44:11 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	let_it_go(t_map *map, int flag)
{
	if (flag == 1)
		free(map->map_memory);
	if (flag <= 2)
		free(map->points);
	if (flag <= 3)
		free(map->cpy_proje);
}

void	exterminate(char *error, t_map *map, int flag)
{
	if (errno == 0)
	{
		let_it_go(map, flag);
		ft_putendl_fd(error, 2);
	}
	else
	{
		let_it_go(map, flag);
		perror(error);
	}
	exit(1);
}
