/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_allocate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waelhamd <waelhamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:08:11 by waelhamd          #+#    #+#             */
/*   Updated: 2022/02/21 23:08:51 by waelhamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

t_fdf	*memory_allocate(char *filename)
{
	t_fdf	*data;
	int		x;

	x = 0;
	data = (t_fdf *) malloc(sizeof(t_fdf));
	data->x = 0;
	data->y = get_colone(filename, &data->x);
	data->matrice = (t_point **)malloc(sizeof(t_point *) * data->x);
	while (x < data->x)
	{
		data->matrice[x] = (t_point *)malloc(sizeof(t_point) * data->y);
		x++;
	}
	return (data);
}
