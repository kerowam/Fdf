/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 02:13:14 by gfredes-          #+#    #+#             */
/*   Updated: 2024/01/20 23:02:48 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void check_leaks(void)
{
	system("leaks fdf");
}

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
	map->window_ptr = mlx_new_window(map->mlx_ptr, 1000, 1000, "FDF");
	draw_sequence(map);
	mlx_key_hook(map->window_ptr, key_hook, map);
	atexit(check_leaks);
	mlx_hook(map->window_ptr, 17, 0, close_window, map);
	mlx_loop(map->mlx_ptr);
	return (0);
}
