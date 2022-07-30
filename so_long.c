/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:42:28 by arakhurs          #+#    #+#             */
/*   Updated: 2022/07/25 16:42:30 by arakhurs         ###   ########.fr       */
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
	char	*str;
	int		fd;

	str = NULL;
	if (ft_strncmp(".ber", (mpath + (ft_strlen(mpath) - 4)), 4) != 0)
		ft_error("❌ Map format is not *.ber");
	fd = open(mpath, O_RDONLY);
	if (fd == -1)
		ft_error("❌ Can't Open MAP 🗺");
	line = "1";
	while (line != NULL)
	{
		line = get_next_line(fd);
		str = ft_strjoin(str, line);
		free(line);
	}
	if (close(fd) == -1)
		ft_error("❌ Can't close Map File 🗺");
	map->matrix = ft_split(str, '\n');
	ft_free_array(&str);
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
	a->win = mlx_new_window(a->mlx, a->map.width * TEXTURE_Y, a->map.height * TEXTURE_X, "so_long");
	if (a->win == NULL)
	{
		ft_free_matrix(&(a->map.matrix));
		ft_error("❌ Can't Creat Window 📺");
	}
	mlx_hook(a->win, 17, 0, ft_destroy_window, a);
}

void	ft_textures(t_img *img, void *mlx)
{
	int	width;
	int	height;

	img->wall = mlx_xpm_file_to_image(mlx, WALL, &width, &height);
	if (img->wall == NULL)
		ft_error("❌ Can't Open Wall 🚧 Texture");
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
		printf("%d\n", __LINE__);
		ft_draw_map(&a);
		printf("%d\n", __LINE__);
		mlx_hook(a.win, 2, 0, ft_key_press, &a);
		mlx_loop(a.mlx);
	}
	ft_error("❌ No Valid Argument❗️ \n➡️ ./so_long map_file.ber");
	return (0);
}
