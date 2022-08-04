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

void	ft_move_up2(t_all *a)
{
	if (a->map.matrix[a->img.player.y - 1][a->img.player.x] == 'E')
	{
		ft_fill_player(a, a->img.player.y - 1, a->img.player.x);
		ft_fill_floor(a, a->img.player.y, a->img.player.x);
		a->map.matrix[a->img.player.y - 1][a->img.player.x] = 'E';
		ft_fill_lock(a, a->img.player.y - 1, a->img.player.x);
		a->img.player.y--;
		if (a->map.coin)
			return ;
		ft_destroy_window(a);
	}
}

void	ft_move_down2(t_all *a)
{
	if (a->map.matrix[a->img.player.y + 1][a->img.player.x] == 'E')
	{
		ft_fill_player(a, a->img.player.y + 1, a->img.player.x);
		ft_fill_floor(a, a->img.player.y, a->img.player.x);
		a->map.matrix[a->img.player.y + 1][a->img.player.x] = 'E';
		ft_fill_lock(a, a->img.player.y + 1, a->img.player.x);
		a->img.player.y++;
		if (a->map.coin)
			return ;
		ft_destroy_window(a);
	}
}

void	ft_move_left2(t_all *a)
{
	if (a->map.matrix[a->img.player.y][a->img.player.x - 1] == 'E')
	{
		ft_fill_player(a, a->img.player.y, a->img.player.x - 1);
		ft_fill_floor(a, a->img.player.y, a->img.player.x);
		a->map.matrix[a->img.player.y][a->img.player.x - 1] = 'E';
		ft_fill_lock(a, a->img.player.y, a->img.player.x - 1);
		a->img.player.x--;
		if (a->map.coin)
			return ;
		ft_destroy_window(a);
	}
}

void	ft_move_right2(t_all *a)
{
	if (a->map.matrix[a->img.player.y][a->img.player.x + 1] == 'E')
	{
		ft_fill_player(a, a->img.player.y, a->img.player.x + 1);
		ft_fill_floor(a, a->img.player.y, a->img.player.x);
		a->map.matrix[a->img.player.y][a->img.player.x + 1] = 'E';
		ft_fill_lock(a, a->img.player.y, a->img.player.x + 1);
		a->img.player.x++;
		if (a->map.coin)
			return ;
		ft_destroy_window(a);
	}
}
