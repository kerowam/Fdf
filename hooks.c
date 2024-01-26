/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:34:22 by gfredes-          #+#    #+#             */
/*   Updated: 2024/01/20 22:49:09 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->window_ptr);
	exit (0);
}

int	key_hook(int key, t_map *map)
{
	(void)map;
	if (key == 65307)
		close_window(map);
	else
	{
		if (key == 65362)
			map->y_move -= 10;
		else if (key == 65361)
			map->x_move -= 10;
		else if (key == 65364)
			map->y_move += 10;
		else if (key == 65363)
			map->x_move += 10;
		mlx_clear_window(map->mlx_ptr, map->window_ptr);
		draw_sequence(map);
		mlx_put_image_to_window(map->mlx_ptr, map->window_ptr, map->image_ptr, 0, 0);
	}
	return (0);
}
