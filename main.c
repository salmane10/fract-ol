/* PROJECT FRACT-OL
 *
 * Mandelbrot 
 * julia
 */

int	main(int ac, char **av)
{
	t_fractal fractal;

	if ((ac == 2 && av[1] == "mandelbrot")
		|| ac == 4 && av[1] == julia)
	{
		fractal.name = av[1];
		//Start
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);




	}
	else
	{
		write(2, "error\n", 6);
		exit(EXIT_FAILURE);
	}

}
