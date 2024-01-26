/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:48:34 by gfredes-          #+#    #+#             */
/*   Updated: 2024/01/20 23:00:40 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void clear_image(t_map *map)
{
	int x;
	int y;

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
	printf("%d\n", key);
	if (key == 53)
		close_window(map);
	else
	{
		if (key >= 123 && key <= 126)
			move_map(key, map);
		else if (key == 30 || key == 44)
			zoom_map (key, map);
		else if (key == 13 || (key >= 0 && key <= 2))
			rotate_map(key, map);
		else if (key == 6 || key == 7)
			change_deep(key, map);
		else if (key == 35)
			change_projection(map);
		clear_image(map);
		draw_sequence(map);
		mlx_put_image_to_window(map->mlx_ptr, map->window_ptr, map->image_ptr, 0, 0);
	}
	return (0);
}

