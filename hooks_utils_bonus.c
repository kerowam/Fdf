/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:50:05 by gfredes-          #+#    #+#             */
/*   Updated: 2024/01/04 18:50:54 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	move_map(int key, t_map *map)
{
	if (key == 65362)
		map->y_move -= 10;
	else if (key == 65361)
		map->x_move -= 10;
	else if (key == 65364)
		map->y_move += 10;
	else if (key == 65363)
		map->x_move += 10;
}

void	zoom_map(int key, t_map *map)
{
	if (key == 43)
		map->zoom += 10;
	else if (key == 45)
	{
		if (map->zoom > 10)
			map->zoom -= 10;
	}
}

void	rotate_map(int key, t_map *map)
{
	if (key == 119)
		map->angle_y -= 0.2;
	else if (key == 115)
		map->angle_y += 0.2;
	else if (key == 97)
		map->angle_x += 0.2;
	else if (key == 100)
		map->angle_x -= 0.2;
}

void	change_deep(int key, t_map *map)
{
	if (key == 122)
		map->z_mod -= 1;
	else if (key == 120)
		map->z_mod += 1;
}

void	change_projection(t_map *map)
{
	if (map->projection == 0)
		map->projection = 1;
	else
		map->projection = 0;
}
