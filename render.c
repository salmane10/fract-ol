#include "fractol.h"

// z = z^2 + c

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	(unsigned int *)(img->pixels_ptr + offset) = color

}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int		i;

	// iteration
	z.x = 0.0;
	z.y = 0.0;

	// pixel coordinate x && y scaled to fit mandel needs
	c.x = map(x, -2, +2, 0, WIDTH);
	c.y = map(y, +2, -2, 0, HEITH);

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
