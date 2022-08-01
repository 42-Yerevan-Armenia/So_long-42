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

void	ft_fill_player(t_all *a, int i, int j)
{
	mlx_put_image_to_window(a->mlx, a->win, a->img.floor, j * TEXTURE_X, i * TEXTURE_Y);
	mlx_put_image_to_window(a->mlx, a->win, a->img.player.ptr, j * TEXTURE_X, i * TEXTURE_Y);
}

void	ft_fill_floor(t_all *a, int i, int j)
{
	mlx_put_image_to_window(a->mlx, a->win, a->img.floor, j * TEXTURE_X, i * TEXTURE_Y);
}

void	ft_fill_(t_all *a, int i, int j)
{
	mlx_put_image_to_window(a->mlx, a->win, a->img.exit, j * TEXTURE_X, i * TEXTURE_Y);
}