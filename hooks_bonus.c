/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:48:34 by gfredes-          #+#    #+#             */
/*   Updated: 2024/01/04 19:36:41 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	close_window(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->window_ptr);
	exit (0);
}

int	key_hook(int key, t_map *map)
{
	if (key == 65307)
		close_window(map);
	else
	{
		if (key >= 65361 && key <= 65364)
			move_map(key, map);
		else if (key == 43 || key == 45)
			zoom_map (key, map);
		else if (key == 119 || key == 115 || key == 97 || key == 100)
			rotate_map(key, map);
		else if (key == 122 || key == 120)
			change_deep(key, map);
		else if (key == 112)
			change_projection(map);
		mlx_clear_window(map->mlx_ptr, map->window_ptr);
		draw_sequence(map);
	}
	return (0);
}

/*int	loop_hook(int key, void *param)
{
	//t_map	*map;

	(void)param;
	return (0);
}*/
