#include "fractol.h"

/*
 * INIT
 * mlx
 * listening events
 * hooks data
 */

static	void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}


void	data_init(t_fractal * fractal)
{
	fractal->escape_value	= 4;
	fractal->iterations	= 42;
	fractal->shift_x	= 0.0;
	fractal->shift_y	= 0.0;
	fractal->zoom		= 1.0; //zoom fector
}

static	void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window,
			KeyPress,
			KeyPressMask,
			key_handler,
			fractal);

	mlx_hook(fractal->mlx_window,
			ButtonPress,
			ButtonPressMask,
			mouse_handler,
			fractal);

	mlx_hook(fractal->mlx_window,
			DestroyNotify,
			StructurNotifyMask,
			close_handler,
			fractal);
}

void	fractal_init(t_fractal *fractal)
{
	//mlx stuff
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		malloc_error();	//todo
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, fractal->name);
	
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		mallox_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
			mlx_ptr, WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fraactal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len,
			&fractal->img.endian);
	//events
	//data_init
}

