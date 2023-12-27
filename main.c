/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 02:40:48 by gfredes-          #+#    #+#             */
/*   Updated: 2023/12/27 20:40:31 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key,void *map)
{
	printf("%d", key); //AÑADIR MI FT_PRINTF A LIBFT Y UTILIZARLA AQUI!!!!
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	read_map(argv[1], map);
	map->mlx_ptr = mlx_init();
	map->window_ptr = mlx_new_window(map->mlx_ptr, 1000, 1000, "FDF");
	draw_line(10, 10, 600, 300, map);
	mlx_key_hook(map->window_ptr, deal_key, NULL);
	mlx_loop(map->mlx_ptr);
}
