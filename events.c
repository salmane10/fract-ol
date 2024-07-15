#include "fractol.h"

// ESC 
int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection,
			fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection,
			fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

// SHIFT KEYS FOR SHIFTING AND CLOSING 
int	key_handler(int	keysym, t_fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	if (keysym == XK_Left)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_plus)
		fractal->iterations += 5;
	else if (keysym == XK_minus)
		fractal->iterations -= 5;
	fractal_render(fractal); // refresh image
	return (0);
}

// MOUSE KEYS FOR ZOOM IN, ZOOM OUT
int	mouse_handler(int botton, int x, int y, t_fractal *fractal)
{
	
	if (button == Button5) //zoom in
	{
		fractal->zoom *= 0.95;
	}
	else if (button == Button4) //zoom out
	{
		fractal->zoom *= 1.05;
	}

	fracral_render(fractal); // refresh
	return (0);
}
