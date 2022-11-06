/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waelhamd <waelhamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:11:38 by waelhamd          #+#    #+#             */
/*   Updated: 2022/02/21 23:01:18 by waelhamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

t_xy	*initcordonne(int a, int b, int z, t_fdf *data)
{
	t_xy	*point;

	point = (t_xy *)malloc(sizeof(t_xy));
	a *= data->zoom;
	b *= data->zoom;
	point->x = a;
	point->y = b;
	if (data->rot == 1)
		x_rotation(&point->x, &point->y, &z, data->teta);
	if (data->rot == 2)
		y_rotation(&point->x, &point->y, &z, data->teta);
	if (data->rot == 3)
		z_rotation(&point->x, &point->y, &z, data->teta);
	if (data->iso == 0)
		iso(point, z);
	point->x += 900 + data->x_shift;
	point->y += 200 + data->y_shift;
	return (point);
}

void	draw_map(t_all *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->map->x)
	{
		y = 0;
		while (y < data->map->y)
		{
			if (y < data->map->y - 1)
				bresenham (initcordonne(y, x, data->map->matrice[x][y].heiht
						* data->map->height, data->map), initcordonne(y + 1, x,
						data->map->matrice[x][y + 1].heiht * data->map->height,
						data->map), data->mlx, data->map->matrice[x][y].colore);
			if (x < data->map->x - 1)
				bresenham(initcordonne(y, x, data->map->matrice[x][y].heiht
						*data->map->height, data->map), initcordonne(y, x + 1,
						data->map->matrice[x + 1][y].heiht * data->map->height,
						data->map), data->mlx, data->map->matrice[x][y].colore);
			y++;
		}
		x++;
	}
}
