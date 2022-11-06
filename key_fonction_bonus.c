/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fonction_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waelhamd <waelhamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 23:40:17 by waelhamd          #+#    #+#             */
/*   Updated: 2022/02/23 03:40:10 by waelhamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	ft_altitude(int key, t_all *all)
{
	if (key == 69)
		all->map->height += 1;
	else if (key == 78)
		all->map->height -= 1;
}

void	ft_handle_zoom(int key, t_all *all)
{
	if (key == 126)
		all->map->zoom += 1;
	else if (key == 125)
	{
		if (all->map->zoom > 1)
		all->map->zoom -= 1;
	}
}

void	ft_handle_iso(int key, t_fdf *data)
{
	if (key == 82)
		data->iso = 1;
	else if (key == 65)
		data->iso = 0;
}

void	ft_handle_translation(int key, t_fdf *data)
{
	if (key == 86)
		data->x_shift -= 15;
	else if (key == 88)
		data->x_shift += 15;
	else if (key == 91)
		data->y_shift -= 15;
	else if (key == 84)
		data->y_shift += 15;
}

void	handle_rot(int key, t_fdf *data)
{
	if (key == 12 || key == 0 || key == 6)
	{
		if (key == 12)
			data->rot = 1;
		else if (key == 0)
			data->rot = 2;
		else if (key == 6)
			data->rot = 3;
		data->teta += 0.2;
	}
	else if (key == 13 || key == 1 || key == 7)
	{
		if (key == 13)
			data->rot = 1;
		else if (key == 1)
			data->rot = 2;
		else if (key == 7)
			data->rot = 3;
		data->teta -= 0.2;
	}
}
