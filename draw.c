/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:50:08 by gfredes-          #+#    #+#             */
/*   Updated: 2023/12/28 22:30:38 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fdf.h"

float	select_abs_max(float a, float b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if (a > b)
		return (a);
	else
		return (b);
}

void	isometric_proyection(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.7);
	*y = (*x + *y) * sin(0.7) - z;
}

void	draw_line(float x, float y, float x1, float y1, t_map *map)
{
	float	x_dist;
	float	y_dist;
	int		max_dist;
	int		z;
	int		z1;
	int		color;

	z = map->z_values[(int)y][(int)x];
	z1 = map->z_values[(int)y1][(int)x1];
	color = 0x01 * map->z_color[(int)y][(int)x];
	x *= map->zoom;
	y *= map->zoom;
	x1 *= map->zoom;
	y1 *= map->zoom;
	/*if (z > 0 || z1 > 0)
		map->color = 0x56ca1f;
	else if (z == 0 || z1 == 0)
		map->color = 0xffffff;
	else if (z < 0 || z1 < 0)
		map->color = 0x2424e7;*/
	z += map->zoom;
	z1 += map->zoom;
	isometric_proyection(&x, &y, z);
	isometric_proyection(&x1, &y1, z1);
	x += map->x_move;
	y += map->y_move;
	x1 += map->x_move;
	y1 += map->y_move;
	x_dist = x1 - x;
	y_dist = y1 - y;
	max_dist = select_abs_max(x_dist, y_dist);
	x_dist /= max_dist;
	y_dist /= max_dist;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(map->mlx_ptr, map->window_ptr, x, y, color);
		x += x_dist;
		y += y_dist;
	}
}

void	draw_sequence(t_map	*map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				draw_line(x, y, x + 1, y, map);
			if (y < map->height - 1)
				draw_line(x, y, x, y + 1, map);
			x++;
		}
		y++;
	}
}
