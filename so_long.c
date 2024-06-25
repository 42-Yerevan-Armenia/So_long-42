/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <arakhurs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:42:28 by arakhurs          #+#    #+#             */
/*   Updated: 2024/06/25 20:25:07 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	if (str && *str)
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
		exit(EXIT_FAILURE);
	}
}

void	ft_map(t_map *map, const char *mpath)
{
	char	*line;
	int		fd;

	map->str = NULL;
	if (ft_strncmp(".ber", (mpath + (ft_strlen(mpath) - 4)), 4) != 0)
		ft_error("❌ Map format is not *.ber");
	fd = open(mpath, O_RDONLY);
	if (fd == -1)
		ft_error("❌ Can't Open MAP 🗺");
	while (1)
	{
		line = get_next_line(fd);
		map->str = ft_strjoin(map->str, line);
		if (*line == (char) NULL)
			break ;
		free(line);
	}
	free(line);
	if (close(fd) == -1)
		ft_error("❌ Can't close Map File 🗺");
	ft_check_split(map, map->str);
	ft_free_array(&map->str);
	if (!(*(map->matrix)))
		ft_error("❌ Can't split❗️");
	ft_check_map(map);
}

void	ft_win(t_all *a)
{
	a->mlx = mlx_init();
	if (a->mlx == NULL)
	{
		ft_free_matrix(&(a->map.matrix));
		ft_error("❌ Can't do it 🤣");
	}
	a->win = mlx_new_window(a->mlx, a->map.width * Y, \
		a->map.height * X, "so_long");
	if (a->win == NULL)
	{
		ft_free_matrix(&(a->map.matrix));
		ft_error("❌ Can't Creat Window 📺");
	}
	mlx_hook(a->win, 17, 0, ft_destroy_window_2, a);
}

void	ft_textures(t_img *img, void *mlx)
{
	int	width;
	int	height;

	img->wall = mlx_xpm_file_to_image(mlx, WALL, &width, &height);
	if ((img->wall) == NULL)
		ft_error("❌ Can't Open Wall 🚧 Texture");
	img->coin = mlx_xpm_file_to_image(mlx, C1, &width, &height);
	img->coin2 = mlx_xpm_file_to_image(mlx, C2, &width, &height);
	if (img->coin == NULL)
		ft_error("Cant Open Coin Texture");
	img->exit = mlx_xpm_file_to_image(mlx, EXIT, &width, &height);
	img->lock = mlx_xpm_file_to_image(mlx, LOCK, &width, &height);
	if (img->exit == NULL)
		ft_error("Cant Open Exit Texture");
	img->floor = mlx_xpm_file_to_image(mlx, FLOOR, &width, &height);
	if (img->floor == NULL)
		ft_error("Cant Open Floor Texture");
	(img->player_r.ptr) = mlx_xpm_file_to_image(mlx, PLAYER_R, &width, &height);
	(img->player_l.ptr) = mlx_xpm_file_to_image(mlx, PLAYER_L, &width, &height);
	if ((img->player_r.ptr) == NULL)
		ft_error("Cant Open Player Texture");
	img->monster = mlx_xpm_file_to_image(mlx, M1, &width, &height);
	img->monster2 = mlx_xpm_file_to_image(mlx, M2, &width, &height);
}

int	main(int ac, char *av[])
{
	t_all	a;

	if (ac == 2)
	{
		ft_map(&a.map, av[1]);
		ft_win(&a);
		a.moves = 0;
		ft_textures(&(a.img), a.mlx);
		ft_draw_map(&a);
		mlx_hook(a.win, 2, 0, ft_key_press, &a);
		mlx_loop_hook(a.mlx, &loop_hook, &a);
		mlx_loop(a.mlx);
	}
	ft_error("❌ No Valid Argument❗️ \n➡️ ./so_long map_file.ber");
	return (0);
}
