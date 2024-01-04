/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:50:08 by gfredes-          #+#    #+#             */
/*   Updated: 2024/01/04 16:53:32 by gfredes-         ###   ########.fr       */
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

void	isometric_projection(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.7);
	*y = (*x + *y) * sin(0.7) - z;
}

void	do_zoom(t_map *map)
{
	map->zoom = 20;
	map->x *= map->zoom;
	map->y *= map->zoom;
	map->x1 *= map->zoom;
	map->y1 *= map->zoom;
	map->z += map->zoom;
	map->z1 += map->zoom;
}

void	draw_line(float x, float y, t_map *map)
{
	float	x_dist;
	float	y_dist;
	int		max_dist;
	int		color;

	set_z_z1(map, x, y);
	color = 0x01 * map->z_color[(int)y][(int)x];
	do_zoom(map);
	isometric_projection(&map->x, &map->y, map->z);
	isometric_projection(&map->x1, &map->y1, map->z1);
	map->x += map->x_move;
	map->y += map->y_move;
	map->x1 += map->x_move;
	map->y1 += map->y_move;
	x_dist = map->x1 - map->x;
	y_dist = map->y1 - map->y;
	max_dist = select_abs_max(x_dist, y_dist);
	x_dist /= max_dist;
	y_dist /= max_dist;
	while ((int)(map->x - map->x1) || (int)(map->y - map->y1))
	{
		mlx_pixel_put(map->mlx_ptr, map->window_ptr, map->x, map->y, color);
		map->x += x_dist;
		map->y += y_dist;
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
			set_x_y(x, y, map);
			if (x < map->width - 1)
			{
				set_x1_y1(x + 1, y, map);
				draw_line(x, y, map);
			}
			if (y < map->height - 1)
			{
				set_x_y(x, y, map);
				set_x1_y1(x, y + 1, map);
				draw_line(x, y, map);
			}
			x++;
		}
		y++;
	}
}
