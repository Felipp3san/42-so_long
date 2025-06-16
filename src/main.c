#include "libft.h"
#include "mlx.h"
#include "mlx_int.h"

#define WIDTH 800
#define HEIGHT 800

typedef struct s_vars
{
	t_xvar		*mlx;
	t_win_list	*win;
}	t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

int	on_key_press(int key_code, t_vars *vars)
{
	(void) vars;	
	ft_printf("Hello from key_hook. KeyCode: %d\n", key_code);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	squares_img(t_data *img)
{
	int	x;
	int y;

	y = 100;
	while (y < HEIGHT)
	{
		x = 100;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(img, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}

int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);

	img.img = mlx_new_image(vars.mlx, HEIGHT, WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
							  &img.line_length, &img.endian);
	vars.win = mlx_new_window(vars.mlx, HEIGHT, WIDTH, "My window");
	if (!vars.win)
	{
		mlx_destroy_display(vars.win);
		free(vars.win);
		return (1);
	}
	squares_img(&img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, on_key_press, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);

	return (0);
}
