#include "libft.h"
#include "mlx.h"
#include "mlx_int.h"

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

int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);

	img.img = mlx_new_image(vars.mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
							  &img.line_length, &img.endian);
	vars.win = mlx_new_window(vars.mlx, 800, 800, "My window");
	if (!vars.win)
	{
		mlx_destroy_display(vars.win);
		free(vars.win);
		return (1);
	}
	mlx_key_hook(vars.win, on_key_press, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);

	return (0);
}
