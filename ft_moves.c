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
		if (a->map.matrix[a->img.player.y][a->img.player.x] == 'E')
			ft_fill_locked_exit(a, a->img.player.y, a->img.player.x);
		a->img.player.y--;
	}
	else if (a->map.matrix[a->img.player.y - 1][a->img.player.x] == 'C')
	{
		ft_fill_player(a, a->img.player.y - 1, a->img.player.x);
		ft_fill_floor(a, a->img.player.y, a->img.player.x);
		a->map.matrix[a->img.player.y - 1][a->img.player.x] = '0';
		a->map.coin--;
		a->img.player.y--;
		if (a->map.coin == 0)
		{
			a->map.matrix[a->img.player.y][a->img.player.x] = 'P';
			ft_put_image2(a, 0, 0);
		}
	}
	ft_move_up2(a);
}

void	ft_move_down(t_all *a)
{
	if (a->map.matrix[a->img.player.y + 1][a->img.player.x] == '0')
	{
		ft_fill_player(a, a->img.player.y + 1, a->img.player.x);
		ft_fill_floor(a, a->img.player.y, a->img.player.x);
		if (a->map.matrix[a->img.player.y][a->img.player.x] == 'E')
			ft_fill_locked_exit(a, a->img.player.y, a->img.player.x);
		a->img.player.y++;
	}
	else if (a->map.matrix[a->img.player.y + 1][a->img.player.x] == 'C')
	{
		ft_fill_player(a, a->img.player.y + 1, a->img.player.x);
		ft_fill_floor(a, a->img.player.y, a->img.player.x);
		a->map.matrix[a->img.player.y + 1][a->img.player.x] = '0';
		a->map.coin--;
		a->img.player.y++;
		if (a->map.coin == 0)
		{
			a->map.matrix[a->img.player.y][a->img.player.x] = 'P';
			ft_put_image2(a, 0, 0);
		}
	}
	ft_move_down2(a);
}

void	ft_move_left(t_all *a)
{
	if (a->map.matrix[a->img.player.y][a->img.player.x - 1] == '0')
	{
		ft_fill_player(a, a->img.player.y, a->img.player.x - 1);
		ft_fill_floor(a, a->img.player.y, a->img.player.x);
		if (a->map.matrix[a->img.player.y][a->img.player.x] == 'E')
			ft_fill_locked_exit(a, a->img.player.y, a->img.player.x);
		a->img.player.x--;
	}
	else if (a->map.matrix[a->img.player.y][a->img.player.x - 1] == 'C')
	{
		ft_fill_player(a, a->img.player.y, a->img.player.x - 1);
		ft_fill_floor(a, a->img.player.y, a->img.player.x);
		a->map.matrix[a->img.player.y][a->img.player.x - 1] = '0';
		a->map.coin--;
		a->img.player.x--;
		if (a->map.coin == 0)
		{
			a->map.matrix[a->img.player.y][a->img.player.x] = 'P';
			ft_put_image2(a, 0, 0);
		}
	}
	ft_move_left2(a);
}

void	ft_move_right(t_all *a)
{
	if (a->map.matrix[a->img.player.y][a->img.player.x + 1] == '0')
	{
		ft_fill_player(a, a->img.player.y, a->img.player.x + 1);
		ft_fill_floor(a, a->img.player.y, a->img.player.x);
		if (a->map.matrix[a->img.player.y][a->img.player.x] == 'E')
			ft_fill_locked_exit(a, a->img.player.y, a->img.player.x);
		a->img.player.x++;
	}
	else if (a->map.matrix[a->img.player.y][a->img.player.x + 1] == 'C')
	{
		ft_fill_player(a, a->img.player.y, a->img.player.x + 1);
		ft_fill_floor(a, a->img.player.y, a->img.player.x);
		a->map.matrix[a->img.player.y][a->img.player.x + 1] = '0';
		a->map.coin--;
		a->img.player.x++;
		if (a->map.coin == 0)
		{
			a->map.matrix[a->img.player.y][a->img.player.x] = 'P';
			ft_put_image2(a, 0, 0);
		}
	}
	ft_move_right2(a);
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
	mlx_destroy_image(a->mlx, a->img.player.ptr);
	printf(" ❇️ ❇️ ❇️ ❇️ ❇️ ❇️ ❇️ ❇️ ❇️ \n");
	printf("❇️ CONGRATULATIONS!❇️ \n");
	printf(" ❇️ ❇️ ❇️ ❇️ ❇️ ❇️ ❇️ ❇️ ❇️ \n");
	exit(EXIT_SUCCESS);
}
