/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 19:11:35 by arakhurs          #+#    #+#             */
/*   Updated: 2022/07/29 19:11:37 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image(t_all *a, int i, int j)
{
	if (a->map.matrix[i][j] == '1')
		mlx_put_image_to_window(a->mlx, a->win, a->img.wall, j * X, i * Y);
	if (a->map.matrix[i][j] == '0')
		mlx_put_image_to_window(a->mlx, a->win, a->img.floor, j * X, i * Y);
	if (a->map.matrix[i][j] == 'M')
		ft_fill_monster(a, i, j);
	if (a->map.matrix[i][j] == 'E')
		ft_fill_locked_exit(a, i, j);
	if (a->map.matrix[i][j] == 'P')
	{
		(a->img.player_r.x) = j;
		(a->img.player_r.y) = i;
		ft_fill_player(a, i, j);
		a->map.matrix[i][j] = '0';
	}
}

void	ft_draw_map(t_all *a)
{
	int	i;
	int	j;

	i = 0;
	while (a->map.matrix[i])
	{
		j = 0;
		while (a->map.matrix[i][j])
		{
			ft_put_image(a, i, j);
			ft_put_coin(a, i, j, 0);
			ft_put_monster(a, i, j, 0);
			j++;
		}
		i++;
	}
}

void	ft_check_num(char **n, int *coin)
{
	int	i;
	int	j;
	int	e_p[2];

	e_p[0] = 0;
	e_p[1] = 0;
	i = -1;
	while (n[++i])
	{
		j = -1;
		while (n[i][++j])
		{
			if ((n[i][j] != 'C') && (n[i][j] != 'P') && (n[i][j] != 'E') \
				&& (n[i][j] != '1') && (n[i][j] != '0' && (n[i][j] != 'M')))
				ft_error("❌ No correct symbol in MAP 🗺");
			if (n[i][j] == 'C')
				(*coin)++;
			else if (n[i][j] == 'E')
				e_p[0]++;
			else if (n[i][j] == 'P')
				e_p[1]++;
		}
	}
	if ((*coin) < 1 || e_p[0] < 1 || e_p[1] != 1)
		ft_error("❌Map symbol count Error❗️");
}

void	ft_check_wall(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (i == 0 && map->matrix[i][j] != '1')
				ft_error("❌ The map not closed/surrounded by walls 🚧");
			else if (j == 0 && map->matrix[i][j] != '1')
				ft_error("❌ The map not closed/surrounded by walls 🚧");
			else if (i == map->height - 1 && map->matrix[i][j] != '1')
				ft_error("❌ The map not closed/surrounded by walls 🚧");
			else if ((j == map->width - 1 && map->matrix[i][j] != '1') || \
				map->matrix[i][map->width] != '\0')
				ft_error("❌ The map not closed/surrounded by walls 🚧");
			j++;
		}
		i++;
	}
}

void	ft_check_map(t_map *map)
{
	map->height = 0;
	while (&(map->matrix[map->height][0]) != NULL)
		map->height++;
	map->width = 0;
	while (map->matrix[0][map->width] != '\0')
		map->width++;
	if (map->height <= 0 || map->width <= 0)
		ft_error("❌ Not a Valid Map 🗺❗️");
	ft_check_wall(map);
	map->coin = 0;
	ft_check_num(map->matrix, &(map->coin));
}
