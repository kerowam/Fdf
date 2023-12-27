/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 23:00:19 by gfredes-          #+#    #+#             */
/*   Updated: 2023/12/27 23:11:21 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_map
{
	int		width;
	int		height;
	int		**z_values;
	void	*mlx_ptr;
	void	*window_ptr;
	int		zoom;
	int		color;
}			t_map;

void	read_map(char *map_file, t_map *map);
void	draw_line(float x, float y, float x1, float y1, t_map *map);
void	draw_sequence(t_map	*map);

#endif