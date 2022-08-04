/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:38:19 by arakhurs          #+#    #+#             */
/*   Updated: 2022/07/29 17:38:20 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_fill_floor(t_all *a, int i, int j)
{
	mlx_put_image_to_window(a->mlx, a->win, a->img.floor, j * X, i * Y);
}

void	ft_fill_player(t_all *a, int i, int j)
{
	mlx_put_image_to_window(a->mlx, a->win, a->img.floor, j * X, i * Y);
	mlx_put_image_to_window(a->mlx, a->win, a->img.player.ptr, j * X, i * Y);
}

void	ft_fill_exit(t_all *a, int i, int j)
{
	mlx_put_image_to_window(a->mlx, a->win, a->img.exit, j * X, i * Y);
}

void	ft_fill_locked_exit(t_all *a, int i, int j)
{
	mlx_put_image_to_window(a->mlx, a->win, a->img.exit, j * X, i * Y);
	mlx_put_image_to_window(a->mlx, a->win, a->img.lock, j * X, i * Y);
}

void	ft_fill_lock(t_all *a, int i, int j)
{
	mlx_put_image_to_window(a->mlx, a->win, a->img.exit, j * X, i * Y);
	mlx_put_image_to_window(a->mlx, a->win, a->img.lock, j * X, i * Y);
	mlx_put_image_to_window(a->mlx, a->win, a->img.player.ptr, j * X, i * Y);
}
