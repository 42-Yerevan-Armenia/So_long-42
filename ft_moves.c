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
	if (a->map.matrix[a->img.player_r.y - 1][a->img.player_r.x] == '0')
	{
		ft_fill_player_2(a, a->img.player_r.y - 1, a->img.player_r.x);
		ft_fill_floor(a, a->img.player_r.y, a->img.player_r.x);
		if (a->map.matrix[a->img.player_r.y][a->img.player_r.x] == 'E')
			ft_fill_locked_exit(a, a->img.player_r.y, a->img.player_r.x);
		a->img.player_r.y--;
	}
	else if (a->map.matrix[a->img.player_r.y - 1][a->img.player_r.x] == 'C')
		ft_move_coin_up(a);
	else if (a->map.matrix[a->img.player_r.y - 1][a->img.player_r.x] == 'E')
		ft_move_up2(a);
	else if (a->map.matrix[a->img.player_r.y - 1][a->img.player_r.x] == 'M')
		ft_destroy_window_2(a);
}

void	ft_move_down(t_all *a)
{
	if (a->map.matrix[a->img.player_r.y + 1][a->img.player_r.x] == '0')
	{
		ft_fill_player(a, a->img.player_r.y + 1, a->img.player_r.x);
		ft_fill_floor(a, a->img.player_r.y, a->img.player_r.x);
		if (a->map.matrix[a->img.player_r.y][a->img.player_r.x] == 'E')
			ft_fill_locked_exit(a, a->img.player_r.y, a->img.player_r.x);
		a->img.player_r.y++;
	}
	else if (a->map.matrix[a->img.player_r.y + 1][a->img.player_r.x] == 'C')
		ft_move_coin_down(a);
	else if (a->map.matrix[a->img.player_r.y + 1][a->img.player_r.x] == 'E')
		ft_move_down2(a);
	else if (a->map.matrix[a->img.player_r.y + 1][a->img.player_r.x] == 'M')
		ft_destroy_window_2(a);
}

void	ft_move_left(t_all *a)
{
	if (a->map.matrix[a->img.player_r.y][a->img.player_r.x - 1] == '0')
	{
		ft_fill_player_2(a, a->img.player_r.y, a->img.player_r.x - 1);
		ft_fill_floor(a, a->img.player_r.y, a->img.player_r.x);
		if (a->map.matrix[a->img.player_r.y][a->img.player_r.x] == 'E')
			ft_fill_locked_exit(a, a->img.player_r.y, a->img.player_r.x);
		a->img.player_r.x--;
	}
	else if (a->map.matrix[a->img.player_r.y][a->img.player_r.x - 1] == 'C')
		ft_move_coin_left(a);
	else if (a->map.matrix[a->img.player_r.y][a->img.player_r.x - 1] == 'E')
		ft_move_left2(a);
	else if (a->map.matrix[a->img.player_r.y][a->img.player_r.x - 1] == 'M')
		ft_destroy_window_2(a);
}

void	ft_move_right(t_all *a)
{
	if (a->map.matrix[a->img.player_r.y][a->img.player_r.x + 1] == '0')
	{
		ft_fill_player(a, a->img.player_r.y, a->img.player_r.x + 1);
		ft_fill_floor(a, a->img.player_r.y, a->img.player_r.x);
		if (a->map.matrix[a->img.player_r.y][a->img.player_r.x] == 'E')
			ft_fill_locked_exit(a, a->img.player_r.y, a->img.player_r.x);
		a->img.player_r.x++;
	}
	else if (a->map.matrix[a->img.player_r.y][a->img.player_r.x + 1] == 'C')
		ft_move_coin_right(a);
	else if (a->map.matrix[a->img.player_r.y][a->img.player_r.x + 1] == 'E')
		ft_move_right2(a);
	else if (a->map.matrix[a->img.player_r.y][a->img.player_r.x + 1] == 'M')
		ft_destroy_window_2(a);
}

int	ft_destroy_window(t_all *a)
{
	ft_free_matrix(&(a->map.matrix));
	mlx_destroy_window(a->mlx, a->win);
	mlx_destroy_image(a->mlx, a->img.wall);
	mlx_destroy_image(a->mlx, a->img.floor);
	mlx_destroy_image(a->mlx, a->img.coin);
	mlx_destroy_image(a->mlx, a->img.coin2);
	mlx_destroy_image(a->mlx, a->img.lock);
	mlx_destroy_image(a->mlx, a->img.exit);
	mlx_destroy_image(a->mlx, a->img.player_r.ptr);
	mlx_destroy_image(a->mlx, a->img.monster);
	ft_printf(" ❇️ ❇️ ❇️ ❇️ ❇️ ❇️ ❇️ ❇️ ❇️ \n");
	ft_printf("❇️ CONGRATULATIONS!❇️ \n");
	ft_printf(" ❇️ ❇️ ❇️ ❇️ ❇️ ❇️ ❇️ ❇️ ❇️ \n");
	exit(EXIT_SUCCESS);
}
