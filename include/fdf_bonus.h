/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:06:16 by jose-gon          #+#    #+#             */
/*   Updated: 2024/10/09 18:32:49 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "Libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <pthread.h>

# define WINX 1920
# define WINY 1080

# define READ_BUFFER 500000
# define TOLERANCE 0.8

// COLORS

# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define RED 0xFF0000FF
# define GREEN 0x00FF00FF
# define BLUE 0x0000FFFF
# define YELLOW 0xFFFF00FF
# define PURPLE 0x9800C8FF
# define ORANGE 0xFF6400FF

# define DEFAULT_TOP PURPLE
# define DEFAULT_GRO BLACK

// MENU

# define MENU " ||||||-| KEYBINDS |-||||||"
# define MENU1 "  --> Translations <--"
# define MENU2 "       ARROW KEYS"
# define MENU3 "   --> Rotations <--"
# define MENU4 "[A] & [D] - rotate Z axis"
# define MENU5 "[W] & [S] - rotate X axis"
# define MENU6 "[Q] & [E] - rotate Y axis"
# define MENU7 "  --> Zoom in / out <--"
# define MENU8 "       [+] & [-]"
# define MENU9 "--> Change perspective <--"
# define MENU10 "    [I] - Isometric"
# define MENU11 "    [O] - Ortogonal"
# define MENU12 "--> RESET PROJECTION <--"
# define MENU13 "      [BACKSPACE]"
# define MENU14 " --> Color scheme <--"
# define MENU15 "   [KP1]/[KP2]/[KP3]"
# define MENU16 "  [KP0] - reset color"

// STRUCT DEF

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
	unsigned int	color_r;
}					t_point;

typedef struct s_map
{
	t_point			*points;
	t_point			*cpy_proje;
	t_point			limits;
	int				map_length;
	int				max_z;
	int				min_z;
	int				colorize;
	float			scale;
	float			scale_r;
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

typedef struct s_threads
{
	t_global global;
	t_point *proje;
	int start;
	int end;
	bool drawing;
}	t_threads;
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

void	exterminate(char *error, t_map *map, int flag);
void	let_it_go(t_map *map, int flag);

// MAP UTILS

void	load_fdf_map(t_map *map, char *filemap);
void	map_init(t_map *map);
void	parse_n_size(t_map *map);
void	map_projection(t_global *global);

// MAP UTILS

void	copy_map(t_point *src, t_point *dst, int len);
int		into_bounds(t_point dot);

// PROYECTION UTILS

void	change_perspective(t_global *global, t_point *proje);
void	rotate_x(t_map *map, t_point *a);
void	rotate_y(t_map *map, t_point *a);
void	rotate_z(t_map *map, t_point *a);
void	draw_menu(mlx_t *my_mlx);

// COLOR UTILS

float	color_steps(float x1, float x2, float x);
void	set_point_color(t_map *map);
void	point_hex_color(t_map *map, char *value, t_point *point);
void	grade_color(t_map *map, t_point *point);
void	recolorize(t_map *map, t_point *point, unsigned ground, unsigned top);
int		grad_point(t_point a, t_point b, t_point c);
int		get_rgba(int r, int g, int b, int a);
int		get_r(int rgba);
int		get_g(int rgba);
int		get_b(int rgba);
int		get_a(int rgba);

// KEY_HOOKS

void	keys_controls(void *param);
void	key_perspectives(mlx_key_data_t key, void *param);
void	key_colorize(mlx_key_data_t key, void *param);
void	key_resets(mlx_key_data_t key, void *param);
void	key_presses(mlx_key_data_t key, void *param);

#endif
