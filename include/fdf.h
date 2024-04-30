/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:06:16 by jose-gon          #+#    #+#             */
/*   Updated: 2024/04/30 18:51:53 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "Libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WINX 1920
# define WINY 1080

# define READ_BUFFER 500000
# define TOLERANCE 0.8

# define MENU "||||||-| KEYBINDS |-||||||"
# define MENU1 "   -->Translations<--"
# define MENU2 "       ARROW KEYS"
# define MENU3 "    -->Rotations<--"
# define MENU4 " [A] & [D] - rotate Z axis"
# define MENU5 " [W] & [S] - rotate X axis"
# define MENU6 " [Q] & [E] - rotate Y axis"
# define MENU7 "   -->Zoom in / out<--"
# define MENU8 "       [+] & [-]"

enum				e_axis
{
	X,
	Y,
	Z
};

typedef struct s_colors
{
	unsigned int	topcolor;
	unsigned int	groundcolor;
}					t_colors;

typedef struct s_line
{
	float			dx;
	float			dy;
	float			sx;
	float			sy;
	float			err;
	float			e2;
}					t_line;

typedef struct s_point
{
	float			axis[3];
	unsigned int	hex_color;
	unsigned int	color;
}					t_point;

typedef struct s_map
{
	t_point			*points;
	t_point			*cpy_proje;
	t_point			limits;
	int				map_length;
	int				max_z;
	int				min_z;
	float			scale;
	float			rot_x;
	float			rot_y;
	float			rot_z;
	float			x_move;
	float			y_move;
	char			*map_memory;
	t_colors		colors;
}					t_map;

typedef struct s_global
{
	t_map			map;
	t_line			line;
	mlx_t			*my_mlx;
	mlx_image_t		*bitmap;
	char			*name;
}					t_global;

// COLORS

# define BLACK 0x000000FF
# define CASI_BLACK 0x010000ff
# define WHITE 0xFFFFFFFF
# define RED 0xFF0000FF
# define YELLOW 0xFFFF00FF
# define PURPLE 0x9800C8FF

# define DEFAULT_TOP PURPLE
# define DEFAULT_GRO BLACK
// ERRORS DEF

# define ERROR_ARG "ERROR - Incorrect number of arguments"
# define ERROR_FORMAT "ERROR - File format not supported"
# define ERROR_OPEN "ERROR - Error opening file"
# define ERROR_MEMORY "ERROR - Memory error"
# define ERROR_LINE "ERROR - Line length discrepancy"
# define ERROR_LINES "ERROR - Not enought lines"
# define ERROR_READ "ERROR - Error reading file"
# define ERROR_COLOR "ERROR - Bad color adress"

// ERROR

void				exterminate(char *error, t_map *map, int flag);
void				let_it_go(t_map *map, int flag);

// MAP UTILS

void				load_fdf_map(t_map *map, char *filemap);
void				map_init(t_map *map);
void				parse_n_size(t_map *map);
void				map_projection(t_global *global);

// MAP UTILS

void				copy_map(t_point *src, t_point *dst, int len);
void				map_draw(t_global *global);
int					into_bounds(t_point dot);

// PROYECTION UTILS

void				change_perspective(t_global *global, t_point *proje);
void				isometric(t_point *point, t_point *proje);
void				ft_scale(t_point *point, t_point *lim);
void				rotate_x(t_map *map, t_point *a);
void				rotate_y(t_map *map, t_point *a);
void				rotate_z(t_map *map, t_point *a);

// COLOR UTILS

float				color_steps(float x1, float x2, float x);
void				set_point_color(t_map *map);
void				point_hex_color(t_map *map, char *value, t_point *point);
void				grade_color(t_map *map, t_point *point);
int					grad_point(t_point a, t_point b, t_point c);
int					get_rgba(int r, int g, int b, int a);
int					get_r(int rgba);
int					get_g(int rgba);
int					get_b(int rgba);
int					get_a(int rgba);

// KEY_HOOKS

void				keys_controls(mlx_key_data_t key, void *param);
void				key_perspectives(mlx_key_data_t key, void *param);

// BORRAR BORRAR

void				print_map_status(t_map *map, char *status);
// void	isometric_rotate(t_global *global, t_map *map, t_point *proje);

#endif