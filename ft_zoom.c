/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waelhamd <waelhamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:33:08 by waelhamd          #+#    #+#             */
/*   Updated: 2022/02/21 23:15:25 by waelhamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	ft_zoom(t_fdf *data)
{
	if (data->y > 0 && data->y <= 50)
		data->zoom = 20;
	else if (data->y > 50 && data->y <= 100)
		data->zoom = 10;
	else if (data->y > 100 && data->y <= 200)
		data->zoom = 5;
	else
		data->zoom = 2;
}
