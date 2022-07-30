#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*img;
	void	*win;
	char	*relative_path = "/Texture/collect.xpm";
	int		img_width;
	int		img_height;
	int     img_1;

	mlx = mlx_init();
	win = mlx_new_window(mlx,500,500,"test");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	img_1 = mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);

}	

