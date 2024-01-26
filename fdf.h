/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 23:00:19 by gfredes-          #+#    #+#             */
/*   Updated: 2024/01/20 22:00:18 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
//# include "minilibx_macos/mlx_int.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_map
{
	int		width;
	int		height;
	int		**z_values;
	int		**z_color;
	void	*mlx_ptr;
	void	*window_ptr;
	void 	*image_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		zoom;
	int		x_move;
	int		y_move;
	char	*line;
	float	x;
	float	x1;
	float	y;
	float	y1;
	int		z;
	int		z1;
	float	angle_x;
	float	angle_y;
	int		z_mod;
	int		projection;
}			t_map;

int		get_height(char *map_file, t_map *map);
int		word_counter(char *line, char c);
int		get_width(char *map_file);
void	read_map(char *map_file, t_map *map);
void	draw_line(float x, float y, t_map *map);
void	draw_sequence(t_map	*map);
int		close_window(t_map *map);
int		key_hook(int key, t_map *map);
int		ft_atoi_base(const char *str, int str_base);
void	set_z_z1(t_map *map, float x, float y);
void	set_x1_y1(int x1, int y1, t_map *map);
void	set_x_y(int x, int y, t_map *map);
void	set_parameters(t_map *map);
void	isometric_projection(float *x, float *y, int z);
int		deal_key(int key,void *map);

#endif