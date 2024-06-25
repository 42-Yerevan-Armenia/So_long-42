/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <arakhurs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:55:02 by arakhurs          #+#    #+#             */
/*   Updated: 2024/06/25 20:35:21 by arakhurs         ###   ########.fr       */
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
				ft_anim_coin(a, i, j, stat);
			if (a->map.matrix[i][j] == 'M')
				ft_anim_monster(a, i, j, stat);
		}
	}
	return (stat++);
}

static void	ft_check_key(int keycode, t_all *a)
{
	char	c;

	if (keycode == 0 || keycode == 123)
	{
		c = a->map.matrix[a->img.player_r.y][a->img.player_r.x - 1];
		if (c == '0' || c == 'C' || (c == 'E' && a->map.coin == 0))
			ft_printf("⬅️  Move🦶  %d\n", ++a->moves);
		ft_move_left(a);
	}
	if (keycode == 1 || keycode == 125)
	{
		c = a->map.matrix[a->img.player_r.y + 1][a->img.player_r.x];
		if (c == '0' || c == 'C' || (c == 'E' && a->map.coin == 0))
			ft_printf("⬇️  Move🦶  %d\n", ++a->moves);
		ft_move_down(a);
	}
	if (keycode == 2 || keycode == 124)
	{
		c = a->map.matrix[a->img.player_r.y][a->img.player_r.x + 1];
		if (c == '0' || c == 'C' || (c == 'E' && a->map.coin == 0))
			ft_printf("➡️  Move🦶  %d\n", ++a->moves);
		ft_move_right(a);
	}
}

int	ft_key_press(int keycode, t_all *a)
{
	char	c;

	if (keycode == 53)
		ft_destroy_window_2(a);
	ft_check_key(keycode, a);
	if (keycode == 13 || keycode == 126)
	{
		c = a->map.matrix[a->img.player_r.y - 1][a->img.player_r.x];
		if (c == '0' || c == 'C' || (c == 'E' && a->map.coin == 0))
			ft_printf("⬆️  Move🦶  %d\n", ++a->moves);
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
