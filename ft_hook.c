/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:55:02 by arakhurs          #+#    #+#             */
/*   Updated: 2022/07/28 19:55:04 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop_hook(t_all *a)
{
	static int	stat;
	int			i;
	int			j;

	mlx_put_image_to_window(a->mlx, a->win, a->img.exit, j * X, i * Y);
	i = -1;
	while (a->map.matrix[++i])
	{
		j = -1;
		while (a->map.matrix[i][++j])
		{
			if (a->map.matrix[i][j] == 'C')
			{
				mlx_put_image_to_window(a->mlx, a->win, a->img.floor, \
					j * X, i * Y);
				if (stat % 15 == 0)
					mlx_put_image_to_window(a->mlx, a->win, a->img.coin, \
						j * X, i * Y);
				else
					mlx_put_image_to_window(a->mlx, a->win, a->img.coin2, \
						j * X, i * Y);
			}
		}
	}
	return (stat++);
}

static void	ft_check_key(int keycode, t_all *a)
{
	char	c;

	if (keycode == 0)
	{
		c = a->map.matrix[a->img.player.y][a->img.player.x - 1];
		if (c == '0' || c == 'C' || (c == 'E' && a->map.coin == 0))
			printf("⬅️  Move🦶  %d\n", ++a->moves);
		ft_move_left(a);
	}
	if (keycode == 1)
	{
		c = a->map.matrix[a->img.player.y + 1][a->img.player.x];
		if (c == '0' || c == 'C' || (c == 'E' && a->map.coin == 0))
			printf("⬇️  Move🦶  %d\n", ++a->moves);
		ft_move_down(a);
	}
	if (keycode == 2)
	{
		c = a->map.matrix[a->img.player.y][a->img.player.x + 1];
		if (c == '0' || c == 'C' || (c == 'E' && a->map.coin == 0))
			printf("➡️  Move🦶  %d\n", ++a->moves);
		ft_move_right(a);
	}
}

int	ft_key_press(int keycode, t_all *a)
{
	char	c;

	if (keycode == 53)
		ft_destroy_window(a);
	ft_check_key(keycode, a);
	if (keycode == 13)
	{
		c = a->map.matrix[a->img.player.y - 1][a->img.player.x];
		if (c == '0' || c == 'C' || (c == 'E' && a->map.coin == 0))
			printf("⬆️  Move🦶  %d\n", ++a->moves);
		ft_move_up(a);
	}
	return (0);
}

void	ft_free_array(char **c)
{
	if (!c || !*c)
		return ;
	free(*c);
	*c = NULL;
}

void	ft_free_matrix(char ***m)
{
	int	i;

	if (!m || !*m)
		return ;
	i = 0;
	while ((*m)[i])
	{
		ft_free_array(*m + i);
		i++;
	}
	free(*m);
	*m = NULL;
}
