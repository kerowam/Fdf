/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 02:13:14 by gfredes-          #+#    #+#             */
/*   Updated: 2024/01/04 02:45:32 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(void *param)
{
	/*int	y;


	y = 0;
	while (y < map->height)
	{
		free(map->z_values[y]);
		free(map->z_color[y]);
		map->z_values[y] == NULL;
		map->z_color[y] == NULL;
		y++;
	}
	free(map->z_values);
	map->z_values = NULL;
	free(map->z_color);
	map->z_color = NULL;
	free(map->mlx_ptr);
	map->mlx_ptr = NULL;
	free(map->window_ptr);
	map->window_ptr = NULL;
	free(map);
	map = NULL;*/
	(void)param;
	exit (0);
}

int	key_hook(int key, t_map *map, void *param)
{
	printf("%d\n", key); //AÑADIR MI FT_PRINTF A LIBFT Y UTILIZARLA AQUI!!!!???

	if (key == 65307)
		close_window(param);
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
		else if (key == 43)
			map->zoom += 10;
		else if (key == 45)
		{
			if (map->zoom > 10)
				map->zoom -= 10;
		}
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
	map->zoom = 20;
	map->mlx_ptr = mlx_init();
	map->window_ptr = mlx_new_window(map->mlx_ptr, 1000, 1000, "FDF");
	draw_sequence(map);
	mlx_key_hook(map->window_ptr, key_hook, map);
	mlx_hook(map->window_ptr, 17, 1L << 17, close_window, map);
	mlx_hook(map->window_ptr, 2, 0, close_window, map);
	mlx_loop(map->mlx_ptr);
	return (0);
}
