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
# include <string.h>
# include <unistd.h>

# define X 64
# define Y 64
# define WALL "./Texture/wall.xpm"
# define LOCK "./Texture/lock.xpm"
# define EXIT "./Texture/exit.xpm"
# define FLOOR "./Texture/floor.xpm"
# define C1 "./Texture/Coin/coin2.xpm"
# define C2 "./Texture/Coin/coin5.xpm"
# define PLAYER_L "./Texture/player_L.xpm"
# define PLAYER_R "./Texture/player_R.xpm"
# define M1 "./Texture/monster.xpm"
# define M2 "./Texture/monster2.xpm"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//MAP
typedef struct s_map
{
	int		width;
	int		height;
	int		coin;
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
	void		*id;
	void		*wall;
	void		*floor;
	void		*coin;
	void		*coin2;
	void		*lock;
	void		*exit;
	void		*monster;
	void		*monster2;
	t_player	player_l;
	t_player	player_r;
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
int		ft_destroy_window_2(t_all *a);
int		ft_key_press(int keycode, t_all *a);

//MOVES 🦶
void	ft_move_up(t_all *a);
void	ft_move_down(t_all *a);
void	ft_move_left(t_all *a);
void	ft_move_right(t_all *a);
void	ft_move_up2(t_all *a);
void	ft_move_down2(t_all *a);
void	ft_move_left2(t_all *a);
void	ft_move_right2(t_all *a);
void	ft_move_coin_up(t_all *a);
void	ft_move_coin_down(t_all *a);
void	ft_move_coin_left(t_all *a);
void	ft_move_coin_right(t_all *a);

//TEXTURES 🎨
void	ft_textures(t_img *img, void *mlx);
void	ft_fill_player(t_all *a, int i, int j);
void	ft_fill_player_2(t_all *a, int i, int j);
void	ft_fill_monster(t_all *a, int i, int j);
void	ft_fill_floor(t_all *a, int i, int j);
void	ft_fill_exit(t_all *a, int i, int j);
void	ft_fill_lock(t_all *a, int i, int j, int dir);
void	ft_fill_locked_exit(t_all *a, int i, int j);
void	ft_anim_coin(t_all *a, int i, int j, int stat);
void	ft_anim_monster(t_all *a, int i, int j, int stat);
int		loop_hook(t_all *a);

//MAP 🗺
void	ft_map(t_map *map, const char *mpath);
void	ft_draw_map(t_all *a);
void	ft_put_image(t_all *a, int i, int j);
void	ft_put_image2(t_all *a, int i, int j);
void	ft_put_player(t_all *a, int i, int j);
void	ft_put_coin(t_all *a, int i, int j, int cond);
void	ft_put_monster(t_all *a, int i, int j, int cond);
void	ft_check_num(char **n, int *coin);
void	ft_check_wall(t_map *map);
void	ft_check_map(t_map *map);

//LIBFT 📚
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
int		ft_atoi(const char *str);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_substr(char	const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);

//UTILES 🛠
# define BUFFER_SIZE 100

char	*get_next_line(int fd);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);

// 📠
int		ft_printf(const char *s, ...);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_print_unsigned(unsigned int n);
int		ft_print_pointer(unsigned long long l);
int		ft_print_hex(unsigned long long num, unsigned int b, int a);

#endif
