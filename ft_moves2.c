/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:20:24 by arakhurs          #+#    #+#             */
/*   Updated: 2022/08/04 20:20:25 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_fill_player_2(t_all *a, int i, int j)
{
	mlx_put_image_to_window(a->mlx, a->win, a->img.floor, j * X, i * Y);
	mlx_put_image_to_window(a->mlx, a->win, a->img.player_r.ptr, j * X, i * Y);
}

void	ft_move_up2(t_all *a)
{
	if (a->map.matrix[a->img.player_r.y - 1][a->img.player_r.x] == 'E')
	{	
		ft_fill_floor(a, a->img.player_r.y, a->img.player_r.x);
		a->map.matrix[a->img.player_r.y - 1][a->img.player_r.x] = 'E';
		ft_fill_lock(a, a->img.player_r.y - 1, a->img.player_r.x, 0);
		a->img.player_r.y--;
		if (a->map.coin)
			return ;
		ft_destroy_window(a);
	}
}

void	ft_move_down2(t_all *a)
{
	if (a->map.matrix[a->img.player_r.y + 1][a->img.player_r.x] == 'E')
	{	
		ft_fill_floor(a, a->img.player_r.y, a->img.player_r.x);
		a->map.matrix[a->img.player_r.y + 1][a->img.player_r.x] = 'E';
		ft_fill_lock(a, a->img.player_r.y + 1, a->img.player_r.x, 'd');
		a->img.player_r.y++;
		if (a->map.coin)
			return ;
		ft_destroy_window(a);
	}
}

void	ft_move_left2(t_all *a)
{
	if (a->map.matrix[a->img.player_r.y][a->img.player_r.x - 1] == 'E')
	{
		ft_fill_floor(a, a->img.player_r.y, a->img.player_r.x);
		a->map.matrix[a->img.player_r.y][a->img.player_r.x - 1] = 'E';
		ft_fill_lock(a, a->img.player_r.y, a->img.player_r.x - 1, 0);
		a->img.player_r.x--;
		if (a->map.coin)
			return ;
		ft_destroy_window(a);
	}
}

void	ft_move_right2(t_all *a)
{
	if (a->map.matrix[a->img.player_r.y][a->img.player_r.x + 1] == 'E')
	{	
		ft_fill_floor(a, a->img.player_r.y, a->img.player_r.x);
		a->map.matrix[a->img.player_r.y][a->img.player_r.x + 1] = 'E';
		ft_fill_lock(a, a->img.player_r.y, a->img.player_r.x + 1, 'd');
		a->img.player_r.x++;
		if (a->map.coin)
			return ;
		ft_destroy_window(a);
	}
}
