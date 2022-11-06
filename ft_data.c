/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waelhamd <waelhamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:41:13 by waelhamd          #+#    #+#             */
/*   Updated: 2022/02/21 23:13:41 by waelhamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	error_map(void)
{
	write(1, "error map", 9);
	exit(1);
}

int	get_colone(char *filename, int *ptr)
{
	int		i;
	int		fd;
	char	*str;

	fd = open (filename, O_RDONLY);
	str = get_next_line(fd);
	if (str == NULL)
		error_map();
	i = ft_wordcount (str, ' ');
	while (str)
	{
		(*ptr)++;
		if (ft_wordcount (str, ' ') != i)
		{
			free(str);
			error_map();
		}
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close (fd);
	return (i);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	create_data(t_fdf *data, int x, char **split1)
{
	int		y;
	char	**split2;

	y = 0;
	while (y < data->y)
	{
		split2 = ft_split(split1[y], ',');
		data->matrice[x][y].heiht = ft_atoi(split2[0]);
		data->matrice[x][y].colore = ft_atoi_hex(split2[1]);
		free_tab(split2);
		y++;
	}
}

t_fdf	*matrice(char *filename)
{
	t_fdf	*data;
	int		x;
	int		fd;
	char	*line;
	char	**split1;

	x = 0;
	data = memory_allocate(filename);
	fd = open(filename, O_RDONLY);
	while (x < data->x)
	{
		line = get_next_line(fd);
		split1 = ft_split(line, ' ');
		create_data(data, x, split1);
		free_tab(split1);
		free(line);
		x++;
	}
	close(fd);
	return (data);
}
