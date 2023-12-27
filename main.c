/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 02:40:48 by gfredes-          #+#    #+#             */
/*   Updated: 2023/12/28 00:39:47 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key,void *map)
{
	printf("%d\n", key); //AÑADIR MI FT_PRINTF A LIBFT Y UTILIZARLA AQUI!!!!???
	return (0);
}

int	close_window(void *param)
{
	(void)param;
	exit (0);
}

int	loop_hook(int key, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	return (0);
}

int	key_hook(int key, void *param)
{
	if (key == 65307)
		close_window(param);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	read_map(argv[1], map);
	map->mlx_ptr = mlx_init();
	map->window_ptr = mlx_new_window(map->mlx_ptr, 1000, 1000, "FDF");
	map->zoom = 20;
	draw_sequence(map);
	mlx_key_hook(map->window_ptr, deal_key, map);
	mlx_key_hook(map->window_ptr, key_hook, map);
	mlx_hook(map->window_ptr, 17, 1L << 17, close_window, map);
	mlx_hook(map->window_ptr, 2, 0, close_window, map);
	mlx_loop_hook(map->mlx_ptr, loop_hook, map);
	mlx_loop(map->mlx_ptr);
	return (0);
}
