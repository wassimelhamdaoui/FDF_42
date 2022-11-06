/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waelhamd <waelhamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 23:40:10 by waelhamd          #+#    #+#             */
/*   Updated: 2022/02/21 23:17:39 by waelhamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	handle_keys(int key, t_all *all)
{
	ft_handle_iso(key, all->map);
	ft_handle_zoom(key, all);
	ft_handle_exit(key, all->mlx);
	ft_altitude(key, all);
	ft_handle_translation(key, all->map);
	handle_rot(key, all->map);
	mlx_destroy_image(all->mlx->mlx, all->mlx->img);
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	all->mlx->img = mlx_new_image(all->mlx->mlx, W_WIDTH, W_HEIGHT);
	draw_map(all);
	mlx_put_image_to_window(all->mlx->mlx,
		all->mlx->mlx_win, all->mlx->img, 0, 0);
	return (0);
}
