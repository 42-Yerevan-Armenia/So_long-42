/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:57:48 by arakhurs          #+#    #+#             */
/*   Updated: 2022/08/04 19:57:53 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_player(t_all *a, int i, int j)
{
	if (a->map.matrix[i][j] == 'P')
	{
		mlx_put_image_to_window(a->mlx, a->win, a->img.floor, \
			j * X, i * Y);
		mlx_put_image_to_window(a->mlx, a->win, a->img.player.ptr, \
			j * X, i * Y);
	}
}

void	ft_put_image2(t_all *a, int i, int j)
{
	mlx_clear_window(a->mlx, a->win);
	while (1)
	{
		while (a->map.matrix[i][j] != 0)
		{
			ft_put_player(a, i, j);
			if (a->map.matrix[i][j] == '1')
				mlx_put_image_to_window(a->mlx, a->win, a->img.wall, \
					j * X, i * Y);
			else if (a->map.matrix[i][j] == '0')
				mlx_put_image_to_window(a->mlx, a->win, a->img.floor, \
					j * X, i * Y);
			else if (a->map.matrix[i][j] == 'E')
				mlx_put_image_to_window(a->mlx, a->win, a->img.exit, \
					j * X, i * Y);
			j++;
		}
		j = 0;
		i++;
		if (a->map.matrix[i] == NULL)
			break ;
	}
}

void	ft_put_coin(t_all *a, int i, int j, int cond)
{
	if (a->map.matrix[i][j] == 'C')
	{
		mlx_put_image_to_window(a->mlx, a->win, a->img.floor, j * X, i * Y);
		if (cond)
			mlx_put_image_to_window(a->mlx, a->win, a->img.coin, j * X, i * Y);
		else
			mlx_put_image_to_window(a->mlx, a->win, a->img.coin2, j * X, i * Y);
	}
}
