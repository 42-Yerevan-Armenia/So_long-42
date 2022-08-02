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

int	ft_destroy_window(t_all *a)
{
	ft_free_matrix(&(a->map.matrix));
	mlx_destroy_window(a->mlx, a->win);
	mlx_destroy_image(a->mlx, a->img.wall);
	mlx_destroy_image(a->mlx, a->img.floor);
	mlx_destroy_image(a->mlx, a->img.coin);
	mlx_destroy_image(a->mlx, a->img.exit);
	mlx_destroy_image(a->mlx, a->img.player.ptr);
	printf(" ❇️ ❇️ ❇️ ❇️ ❇️ ❇️ ❇️ ❇️ ❇️ \n");
	printf("❇️ CONGRATULATIONS!❇️ \n");
	printf(" ❇️ ❇️ ❇️ ❇️ ❇️ ❇️ ❇️ ❇️ ❇️ \n");
	exit(EXIT_SUCCESS);
}

static void	ft_check_key(int keycode, t_all *a)
{
	char	c;
//printf("%d\n", keycode);
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

	if (keycode == 53)//ESC
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

	if(!m || !*m)
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
