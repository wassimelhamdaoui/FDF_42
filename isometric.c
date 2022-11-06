/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waelhamd <waelhamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:43:32 by waelhamd          #+#    #+#             */
/*   Updated: 2022/02/21 23:01:41 by waelhamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	iso(t_xy *point, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = point->x;
	previous_y = point->y;
	point->x = (previous_x - previous_y) * cos(0.523599);
	point->y = (previous_x + previous_y) * sin(0.523599) - z;
}

void	x_rotation(int *x, int *y, int *z, double teta)
{
	(void)(x);
	*y = *y * cos(teta) + *z * sin(teta);
	*z = -(*y) * sin(teta) + *z * (cos(teta));
}

void	y_rotation(int *x, int *y, int *z, double teta)
{
	(void)(y);
	*x = *x * cos(teta) + *z * sin(teta);
	*z = -(*x) * sin(teta) + *z * (cos(teta));
}

void	z_rotation(int *x, int *y, int *z, double teta)
{
	(void)(z);
	*x = *x * cos(teta) - *y * sin(teta);
	*y = (*x) * sin(teta) + *y * (cos(teta));
}
