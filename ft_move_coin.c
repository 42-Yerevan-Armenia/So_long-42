/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_coin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:11:15 by arakhurs          #+#    #+#             */
/*   Updated: 2022/08/08 18:11:17 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_coin_up(t_all *a)
{
	ft_fill_player_2(a, a->img.player_r.y - 1, a->img.player_r.x);
	ft_fill_floor(a, a->img.player_r.y, a->img.player_r.x);
	a->map.matrix[a->img.player_r.y - 1][a->img.player_r.x] = '0';
	a->map.coin--;
	a->img.player_r.y--;
	if (a->map.coin == 0)
	{
		a->map.matrix[a->img.player_r.y][a->img.player_r.x] = 'P';
		ft_put_image2(a, 0, 0);
		a->map.matrix[a->img.player_r.y][a->img.player_r.x] = '0';
	}
}

void	ft_move_coin_down(t_all *a)
{
	ft_fill_player(a, a->img.player_r.y + 1, a->img.player_r.x);
	ft_fill_floor(a, a->img.player_r.y, a->img.player_r.x);
	a->map.matrix[a->img.player_r.y + 1][a->img.player_r.x] = '0';
	a->map.coin--;
	a->img.player_r.y++;
	if (a->map.coin == 0)
	{
		a->map.matrix[a->img.player_r.y][a->img.player_r.x] = 'P';
		ft_put_image2(a, 0, 0);
		a->map.matrix[a->img.player_r.y][a->img.player_r.x] = '0';
	}
}

void	ft_move_coin_left(t_all *a)
{
	ft_fill_player_2(a, a->img.player_r.y, a->img.player_r.x - 1);
	ft_fill_floor(a, a->img.player_r.y, a->img.player_r.x);
	a->map.matrix[a->img.player_r.y][a->img.player_r.x - 1] = '0';
	a->map.coin--;
	a->img.player_r.x--;
	if (a->map.coin == 0)
	{
		a->map.matrix[a->img.player_r.y][a->img.player_r.x] = 'P';
		ft_put_image2(a, 0, 0);
		a->map.matrix[a->img.player_r.y][a->img.player_r.x] = '0';
	}
}

void	ft_move_coin_right(t_all *a)
{
	ft_fill_player(a, a->img.player_r.y, a->img.player_r.x + 1);
	ft_fill_floor(a, a->img.player_r.y, a->img.player_r.x);
	a->map.matrix[a->img.player_r.y][a->img.player_r.x + 1] = '0';
	a->map.coin--;
	a->img.player_r.x++;
	if (a->map.coin == 0)
	{
		a->map.matrix[a->img.player_r.y][a->img.player_r.x] = 'P';
		ft_put_image2(a, 0, 0);
		a->map.matrix[a->img.player_r.y][a->img.player_r.x] = '0';
	}
}
