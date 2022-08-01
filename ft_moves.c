/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:20:02 by arakhurs          #+#    #+#             */
/*   Updated: 2022/07/29 17:20:03 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_all *a)
{
	if (a->map.matrix[a->img.player.y - 1][a->img.player.x] == '0')
	{
		ft_fill_player(a, a->img.player.y - 1, a->img.player.x);
		ft_fill_floor(a, a->img.player.y, a->img.player.x);
		a->img.player.y--;
	}
	else if (a->map.matrix[a->img.player.y - 1][a->img.player.x] == 'C')
	{
		ft_fill_player(a, a->img.player.y - 1, a->img.player.x);
		ft_fill_floor(a, a->img.player.y, a->img.player.x);
		a->map.matrix[a->img.player.y - 1][a->img.player.x] = '0';
		a->map.collect--;
		a->img.player.y--;
	}
	else if (a->map.matrix[a->img.player.y - 1][a->img.player.x] == 'E')
	{
		if (a->map.collect)
			return ;
		ft_fill_player(a, a->img.player.y - 1, a->img.player.x);
		ft_fill_floor(a, a->img.player.y, a->img.player.x);
		ft_destroy_window(a);
	}
}

void	ft_move_down(t_all *a)
{
	if (a->map.matrix[a->img.player.y + 1][a->img.player.x] == '0')
	{
		ft_fill_player(a, a->img.player.y + 1, a->img.player.x);
		ft_fill_floor(a, a->img.player.y, a->img.player.x);
		a->img.player.y++;
	}
	else if (a->map.matrix[a->img.player.y + 1][a->img.player.x] == 'C')
	{
		ft_fill_player(a, a->img.player.y + 1, a->img.player.x);
		ft_fill_floor(a, a->img.player.y, a->img.player.x);
		a->map.matrix[a->img.player.y + 1][a->img.player.x] = '0';
		a->map.collect--;
		a->img.player.y++;
	}
	else if (a->map.matrix[a->img.player.y + 1][a->img.player.x] == 'E')
	{
		if (a->map.collect)
			return ;
		ft_fill_player(a, a->img.player.y + 1, a->img.player.x);
		ft_fill_floor(a, a->img.player.y, a->img.player.x);
		ft_destroy_window(a);
	}
}

void	ft_move_left(t_all *a)
{
	if (a->map.matrix[a->img.player.y][a->img.player.x - 1] == '0')
	{
		ft_fill_player(a, a->img.player.y, a->img.player.x - 1);
		ft_fill_floor(a, a->img.player.y, a->img.player.x);
		a->img.player.x--;
	}
	else if (a->map.matrix[a->img.player.y][a->img.player.x - 1] == 'C')
	{
		ft_fill_player(a, a->img.player.y, a->img.player.x - 1);
		ft_fill_floor(a, a->img.player.y, a->img.player.x);
		a->map.matrix[a->img.player.y][a->img.player.x - 1] = '0';
		a->map.collect--;
		a->img.player.x--;
	}
	else if (a->map.matrix[a->img.player.y][a->img.player.x - 1] == 'E')
	{
		if (a->map.collect)
			return ;
		ft_fill_player(a, a->img.player.y, a->img.player.x - 1);
		ft_fill_floor(a, a->img.player.y, a->img.player.x);
		ft_destroy_window(a);
	}
}

void	ft_move_right(t_all *a)
{
	if (a->map.matrix[a->img.player.y][a->img.player.x + 1] == '0')
	{
		ft_fill_player(a, a->img.player.y, a->img.player.x + 1);
		ft_fill_floor(a, a->img.player.y, a->img.player.x);
		a->img.player.x++;
	}
	else if (a->map.matrix[a->img.player.y][a->img.player.x + 1] == 'C')
	{
		ft_fill_player(a, a->img.player.y, a->img.player.x + 1);
		ft_fill_floor(a, a->img.player.y, a->img.player.x);
		a->map.matrix[a->img.player.y][a->img.player.x + 1] = '0';
		a->map.collect--;
		a->img.player.x++;
	}
	else if (a->map.matrix[a->img.player.y][a->img.player.x + 1] == 'E')
	{
		if (a->map.collect)
			return ;
		ft_fill_player(a, a->img.player.y, a->img.player.x + 1);
		ft_fill_floor(a, a->img.player.y, a->img.player.x);
		ft_destroy_window(a);
	}
}
