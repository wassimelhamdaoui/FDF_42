/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waelhamd <waelhamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:42:35 by waelhamd          #+#    #+#             */
/*   Updated: 2022/02/21 21:22:31 by waelhamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	init_mandatory(t_all *all, char *av)
{
	all->map = matrice(av);
	all->mlx->mlx = mlx_init();
	all->mlx->mlx_win = mlx_new_window(all->mlx->mlx, W_WIDTH, W_HEIGHT, "FDF");
	all->mlx->img = mlx_new_image(all->mlx->mlx, W_WIDTH, W_HEIGHT);
	all->mlx->addr = mlx_get_data_addr(all->mlx->img, &all->mlx->bits_per_pixel,
			&all->mlx->line_length, &all->mlx->endian);
	ft_zoom(all->map);
	all->map->height = 1;
	all->map->iso = 0;
	all->map->x_shift = 0;
	all->map->y_shift = 0;
	all->map->rot = 0;
	all->map->teta = 0.0;
	draw_map(all);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->mlx_win,
		all->mlx->img, 0, 0);
	mlx_key_hook(all->mlx->mlx_win, &ft_handle_exit, all->mlx);
	mlx_loop(all->mlx->mlx);
}
