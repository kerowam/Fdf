/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:45:27 by gfredes-          #+#    #+#             */
/*   Updated: 2024/01/04 17:45:17 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_z_z1(t_map *map, float x, float y)
{
	float	x1;
	float	y1;

	map->z = map->z_values[(int)y][(int)x];
	x = map->x;
	y = map->y;
	x1 = map->x1;
	y1 = map->y1;
	map->z1 = map->z_values[(int)y1][(int)x1];
}

void	set_x1_y1(int x1, int y1, t_map *map)
{
	map->x1 = (float)x1;
	map->y1 = (float)y1;
}

void	set_x_y(int x, int y, t_map *map)
{
	map->x = (float)x;
	map->y = (float)y;
}

void	set_parameters(t_map *map)
{
	map->x_move = 350;
	map->y_move = 350;
	map->zoom = 20;
}
