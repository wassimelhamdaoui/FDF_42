/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waelhamd <waelhamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:31:26 by waelhamd          #+#    #+#             */
/*   Updated: 2022/02/23 03:52:43 by waelhamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	freepoint(t_xy *point1, t_xy *point2)
{
	free(point1);
	free(point2);
}

int	max(int a, int b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}

void	bresenham(t_xy *point1, t_xy *point2, t_data *img, int color)
{
	int	x;
	int	y;
	int	error[2];

	error[0] = abs (point1->x - point2->x) - abs(point1->y - point2->y);
	x = point1->x;
	y = point1->y;
	while (x != point2->x || y != point2->y)
	{
		my_mlx_pixel_put(img, x, y, color);
		error[1] = error[0] * 2;
		if (error[1] > -abs(point1->y - point2->y))
		{
			error[0] -= abs(point1->y - point2->y);
			x += max(point1->x, point2->x);
		}
		if (error[1] < abs(point1->x - point2->x))
		{
			error[0] += abs(point1->x - point2->x);
			y += max(point1->y, point2->y);
		}
	}
	freepoint(point1, point2);
}
