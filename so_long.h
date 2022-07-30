/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:43:11 by arakhurs          #+#    #+#             */
/*   Updated: 2022/07/25 16:43:13 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define WALL "./Texture/wall.xpm"
# define EXIT "./Texture/exit.xpm"
# define FLOOR "./Texture/floor.xpm"
# define COLLECT "./Texture/collect.xpm"
# define PLAYER "./Texture/player.xpm"
# define TEXTURE_X 64
# define TEXTURE_Y 64

//MAP
typedef struct s_map
{
	int		width;
	int 	height;
	int 	collect;
	char	**matrix;
}				t_map;

//PLAYER
typedef struct s_player
{
	void	*ptr;
	int		x;
	int		y;
}				t_player;

//IMG
typedef struct s_img
{
	void		*wall;
	void		*floor;
	void		*collect;
	void		*exit;
	t_player	player;
}				t_img;

//ALL
typedef struct s_all
{
	void	*mlx;
	void	*win;
	int		moves;
	t_map	map;
	t_img	img;
}				t_all;

//Window 📺
void	ft_win(t_all *a);
void	ft_error(char *str);
/* Functions for Free Matrix and Arrary */
void	ft_free_array(char **arr);
void	ft_free_matrix(char ***matrix);

//HOOK 🎮
int		ft_destroy_window(t_all *a);
int		ft_key_press(int keycode, t_all *a);

//MOVES 🦶
void	ft_move_up(t_all *a);
void	ft_move_down(t_all *a);
void	ft_move_left(t_all *a);
void	ft_move_right(t_all *a);

//TEXTURES 🎨
void	ft_textures(t_img *img, void *mlx);
void	ft_fill_player(t_all *a, int i, int j);
void	ft_fill_floor(t_all *a, int i, int j);
void	ft_fill_exit(t_all *a, int i, int j);

//MAP 🗺
void	ft_map(t_map *map, const char *mpath);
void	ft_draw_map(t_all *a);
void	ft_put_image(t_all *a, int i, int j);
void	ft_check_num(char **n, int *collect);
void	ft_check_wall(t_map *map);
void	ft_check_map(t_map *map);
//void	ft_mapsize(char **pam, int *width, int *height);???

//LIBFT 📚
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
//size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_substr(char	const *s, unsigned int start, size_t len);//char const *s,
char	**ft_split(char const *s, char c);//char const *s,

//UTILES 🛠
# define BUFFER_SIZE 100
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);

#endif