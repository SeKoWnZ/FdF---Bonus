/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:39:38 by jose-gon          #+#    #+#             */
/*   Updated: 2024/04/29 19:07:03 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	copy_map(t_point *src, t_point *dst, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

int	into_bounds(t_point dot)
{
	if (dot.axis[X] > WINX - 1 || dot.axis[X] < 1 ||
		dot.axis[Y] > WINY - 1 || dot.axis[Y] < 1)
		return (0);
	return (1);
}

float	color_steps(float x1, float x2, float x)
{
	if (x1 != x2)
		return ((x - x1) / (x2 - x1));
	return (0);
}

float	function(int x, int y, t_point a, t_point b)
{
	int		dx;
	int		dy;
	float	gradient;

	dx = b.axis[X] - a.axis[X];
	dy = b.axis[Y] - a.axis[Y];
	if (abs(dx) > abs(dy))
		gradient = color_steps(a.axis[X], b.axis[X], x);
	else
		gradient = color_steps(a.axis[Y], b.axis[Y], y);
	if (gradient > 1)
		gradient = 1;
	if (gradient < 0)
		gradient = 0;
	return (gradient);
}

int	grad_point(t_point src, t_point act, t_point dst)
{
	float	gradient;
	int		color;
	int		r;
	int		g;
	int		b;

	gradient = function(act.axis[X], act.axis[Y], src, dst);
	r = get_r(src.color) + ((get_r(dst.color) - get_r(src.color)) * gradient);
	g = get_g(src.color) + ((get_g(dst.color) - get_g(src.color)) * gradient);
	b = get_b(src.color) + ((get_b(dst.color) - get_b(src.color)) * gradient);
	color = get_rgba(r, g, b, 255);
	return (color);
}
