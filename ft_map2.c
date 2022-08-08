/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:47:14 by arakhurs          #+#    #+#             */
/*   Updated: 2022/08/07 20:47:19 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_fill_monster(t_all *a, int i, int j)
{
	if (a->map.matrix[i][j] == 'M')
	{
		mlx_put_image_to_window(a->mlx, a->win, a->img.floor, \
			j * X, i * Y);
		mlx_put_image_to_window(a->mlx, a->win, a->img.monster, \
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
			ft_fill_monster(a, i, j);
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

void	ft_destroy_anim(t_all *a)
{
	mlx_destroy_image(a->mlx, a->img.coin);
	mlx_destroy_image(a->mlx, a->img.coin2);
	mlx_destroy_image(a->mlx, a->img.monster);
	mlx_destroy_image(a->mlx, a->img.monster2);
	mlx_destroy_image(a->mlx, a->img.player_r.ptr);
	mlx_destroy_image(a->mlx, a->img.player_l.ptr);
}

int	ft_destroy_window_2(t_all *a)
{
	ft_free_matrix(&(a->map.matrix));
	mlx_destroy_window(a->mlx, a->win);
	mlx_destroy_image(a->mlx, a->img.wall);
	mlx_destroy_image(a->mlx, a->img.floor);
	mlx_destroy_image(a->mlx, a->img.lock);
	mlx_destroy_image(a->mlx, a->img.exit);
	ft_destroy_anim(a);
	ft_printf(" ⭕️ ⭕️ ⭕️ ⭕️ ⭕️ ⭕️ ⭕️ ⭕️ ⭕️ \n");
	ft_printf("⭕️ YOU LOSE! TRY NEXT TIME⭕️ \n");
	ft_printf(" ⭕️ ⭕️ ⭕️ ⭕️ ⭕️ ⭕️ ⭕️ ⭕️ ⭕️ \n");
	exit(EXIT_SUCCESS);
}
