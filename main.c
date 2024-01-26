/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 02:40:48 by gfredes-          #+#    #+#             */
/*   Updated: 2024/01/20 23:02:39 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void check_leaks(void)
{
	system("leaks fdf");
}*/

int	main(int argc, char **argv)
{
	t_map	*map;
	int		fd;

	map = (t_map *)malloc(sizeof(t_map));
	if (argc != 2)
	{
		ft_putstr_fd("Error: The program only admit one argument.\n", 1);
		return (1);
	}
	fd = open(argv[1], O_RDONLY, 0);
	if (fd <= 0)
	{
		ft_putstr_fd("Error: problem opening the file!\n", 1);
		return (2);
	}
	read_map(argv[1], map);
	set_parameters(map);
	map->mlx_ptr = mlx_init();
	map->window_ptr = mlx_new_window(map->mlx_ptr, 1920, 1080, "FDF");
	map->image_ptr = mlx_new_image(map->mlx_ptr, 1920, 1080);
	map->addr = mlx_get_data_addr(map->image_ptr, &map->bits_per_pixel,
			&map->line_length, &map->endian);
	draw_sequence(map);
	mlx_put_image_to_window(map->mlx_ptr, map->window_ptr, map->image_ptr, 0, 0);
	mlx_key_hook(map->window_ptr, key_hook, map);
	mlx_hook(map->window_ptr, 17, 0, close_window, map);
	//atexit(check_leaks);
	mlx_loop(map->mlx_ptr);
	return (0);
}
