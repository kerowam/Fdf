/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:34:22 by gfredes-          #+#    #+#             */
/*   Updated: 2024/01/29 19:20:54 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_image(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 1080)
	{
		while (x < 1920)
		{
			set_pixel(map, x, y, 0x000000);
			x++;
		}
		x = 0;
		y++;
	}
}

int	close_window(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->window_ptr);
	exit (0);
}

int	key_hook(int key, t_map *map)
{
	(void)map;
	if (key == 53)
		close_window(map);
	else
	{
		if (key == 126)
			map->y_move -= 10;
		else if (key == 123)
			map->x_move -= 10;
		else if (key == 125)
			map->y_move += 10;
		else if (key == 124)
			map->x_move += 10;
		clear_image(map);
		draw_sequence(map);
		mlx_put_image_to_window(map->mlx_ptr, map->window_ptr,
			map->img_ptr, 0, 0);
	}
	return (0);
}
