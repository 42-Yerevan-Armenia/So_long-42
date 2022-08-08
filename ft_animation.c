/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:31:54 by arakhurs          #+#    #+#             */
/*   Updated: 2022/08/08 16:31:57 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_player(t_all *a, int i, int j)
{
	if (a->map.matrix[i][j] == 'P')
	{
		mlx_put_image_to_window(a->mlx, a->win, a->img.floor, \
			j * X, i * Y);
		mlx_put_image_to_window(a->mlx, a->win, a->img.player_r.ptr, \
			j * X, i * Y);
	}
}

void	ft_put_monster(t_all *a, int i, int j, int cond)
{
	if (a->map.matrix[i][j] == 'M')
	{
		mlx_put_image_to_window(a->mlx, a->win, a->img.floor, j * X, i * Y);
		if (cond)
			mlx_put_image_to_window(a->mlx, a->win, a->img.monster, \
				j * X, i * Y);
		else
			mlx_put_image_to_window(a->mlx, a->win, a->img.monster2, \
				j * X, i * Y);
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

void	ft_anim_coin(t_all *a, int i, int j, int stat)
{
	if (a->map.matrix[i][j] == 'C')
	{
		mlx_put_image_to_window(a->mlx, a->win, a->img.floor, \
			j * X, i * Y);
		if (stat % 15 == 0)
			mlx_put_image_to_window(a->mlx, a->win, a->img.coin, \
				(j * X) + 16, (i * Y) + 16);
		else
			mlx_put_image_to_window(a->mlx, a->win, a->img.coin2, \
				(j * X) + 16, (i * Y) + 16);
	}
}

void	ft_anim_monster(t_all *a, int i, int j, int stat)
{
	if (a->map.matrix[i][j] == 'M')
	{
		mlx_put_image_to_window(a->mlx, a->win, a->img.floor, \
			j * X, i * Y);
		if (stat % 10 == 0)
			mlx_put_image_to_window(a->mlx, a->win, a->img.monster, \
				j * X, i * Y);
		else
			mlx_put_image_to_window(a->mlx, a->win, a->img.monster2, \
				j * X, i * Y);
	}
}
