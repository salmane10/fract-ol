#include "fractol.h"

// z = z^2 + c
// julia is a 
// z = pixel_point + constan
// <real> <i>

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	(unsigned int *)(img->pixels_ptr + offset) = color

}

static	void	mandel_or_julia(t_complex *z, t_complex *c, t_fractal fractal)
{
	if (!ft_strncmp(fractal->name, "Julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int		i;

	// iteration
	//z.x = 0.0;
	//z.y = 0.0;

	// pixel coordinate x && y scaled to fit mandel needs
	z.x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, +2, -2, 0, HEITH) * fractal->zoom) + fractal->shift_y;

	mandel_or_julia(&z, &c, fractal);
	//how many times to iterate z^2 + c
	while (i < fractal->iterations)
	{
		z = sum_complex(square_complex(z), c)

		if ((z.x * z.x) + (z.y * z.y) > fractal->excape_value)
		{
			color = map(i , BLACK, WHITE, 0, fractal->iterations;
			my_pixel_put(x , y, frctal-img, color);
			return ;
		}
		i++;

	}
	//we're in mandelbrot given the iterations
	my_pixel_put(x, y, &fractal->img, WHITE);
}

void	fractal_render(t_fractal *fractal)
{
	int x;
	int y;

	y = 0;
	while (y++ < HEIGHT)
	{	
		X = 0;
		WHILE (x++ < WIDTH)
		{
			handel_pixel();
		}
	}
	mlx_put_imgage_to_window(fractal->mlx_connection, mlx_ptr,
			fractal->mlx_window, win_ptr, fractal->img.img_ptr, img_ptr
			0, 0);
}
