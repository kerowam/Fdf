/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:50:08 by gfredes-          #+#    #+#             */
/*   Updated: 2023/12/27 22:58:35 by gfredes-         ###   ########.fr       */
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

void	draw_line(float x, float y, float x1, float y1, t_map *map)
{
	float	x_dist;
	float	y_dist;
	int		max_dist;
	int		z;
	int		z1;

	z = map->z_values[(int)y][(int)x];
	z1 = map->z_values[(int)y1][(int)x1];
	x *= map->zoom;
	y *= map->zoom;
	x1 *= map->zoom;
	y1 *= map->zoom;
	if (z > 0)
		map->color = 0xe80c0c;
	else
		map->color = 0xffffff;
	x_dist = x1 - x;
	y_dist = y1 - y;
	max_dist = select_abs_max(x_dist, y_dist);
	x_dist /= max_dist;
	y_dist /= max_dist;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(map->mlx_ptr, map->window_ptr, x, y, map->color);
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
