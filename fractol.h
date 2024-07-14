#ifndef		FRACTOL_H
#define		FRACTOL_H


#include <stdio.h> // for test
#include <stdlib.h>
#include <unistd.h> 
#include <math.h>
#include "minilibx-linux/mlx.h"

#define ERROR_MESSAGE "Please enter\n\t./fractol mandelbrot"

#define	WIDTH	800
#define HEIGHT	800
/*
typedef	struct	s_complex {
	double	x;
	double	y;
}		t_complex;
*/

typedef	struct s_img
{
	void	*img_ptr;
	char	&pixels_ptr;
	int	bpp;
	int	endian;
	int	line_len;
}		t_img;



typedef	struct s_fractal {
	//mlx
	void	*mlx_connection;
	void	*mlx_window;
	char	*name;
	//Image
	t_img;	img;
	//hooks
	
}		t_fractal;






#endif
