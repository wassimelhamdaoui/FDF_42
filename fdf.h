/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waelhamd <waelhamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 23:16:18 by waelhamd          #+#    #+#             */
/*   Updated: 2022/02/22 22:31:38 by waelhamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <string.h>
# include <fcntl.h>

# define W_HEIGHT 1200
# define W_WIDTH 1800

typedef struct s_xy
{
	int	x;
	int	y;
}				t_xy;

typedef struct s_point
{
	int	heiht;
	int	colore;
}				t_point;

typedef struct s_fdf
{
	int		zoom;
	int		iso;
	int		y_shift;
	int		x_shift;
	int		height;
	int		rot;
	double	teta;
	int		x;
	int		y;
	t_point	**matrice;
}				t_fdf;

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
typedef struct s_all
{
	t_data	*mlx;
	t_fdf	*map;
}	t_all;

int		ft_wordcount(char const *s, char c);
int		get_colone(char *filename, int *ptr);
int		ft_atoi_hex(char *str);
t_fdf	*matrice(char *filename);
void	bresenham(t_xy *point1, t_xy *point2, t_data *img, int color);
void	draw_map(t_all *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *str);
int		handle_keys(int key, t_all *all);
int		ft_handle_exit(int keysym, t_data *img);
int		handle_keys(int key, t_all *all);
void	ft_altitude(int key, t_all *all);
void	ft_handle_iso(int key, t_fdf *data);
void	ft_handle_zoom(int key, t_all *all);
void	ft_handle_translation(int key, t_fdf *data);
void	handle_rot(int key, t_fdf *data);
void	init_bonus(t_all *all, char *av);
void	ft_zoom(t_fdf *data);
void	init_mandatory(t_all *all, char *av);
void	z_rotation(int *x, int *y, int *z, double teta);
void	y_rotation(int *x, int *y, int *z, double teta);
void	x_rotation(int *x, int *y, int *z, double teta);
void	iso(t_xy *point, int z);
t_fdf	*memory_allocate(char *filename);
#endif