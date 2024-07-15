#ifndef		FRACTOL_H
#define		FRACTOL_H


#include <stdio.h> // for test
#include <stdlib.h>
#include <unistd.h> 
#include <math.h>
//#include "minilibx-linux/mlx.h"
//#include <X11/keysym.h>
//#include <X11/X.h>

#define ERROR_MESSAGE "Please enter\n\t./fractol mandelbrot"

#define	WIDTH	800
#define HEIGHT	800

//colors
#define	BLACK	0x000000 //RGB(0, 0, 0)
#define WHITE	0xFFFFFF // RGB(255, 0, 0)

typedef	struct	s_complex {
	double	x;
	double	y;
}		t_complex;

typedef	struct s_img
{
	void	*img_ptr; //pointer to image struct
	char	*pixels_ptr; //points to the actual pixels
	int	bpp;
	int	endian;
	int	line_len;
}		t_img;



typedef	struct s_fractal {
	//mlx
	void	*mlx_connection; //mlx_init()
	void	*mlx_window;	//mlx_new_window()
	char	*name;
	//Image
	t_img;	img;
	//hooks variables
	double	escape_value //hypotenuse
	int	iteratios;  // value tight with the image quality & rendering
	double	shift_x;
	double	shift_y;
	double	zoom;
	//for julia
	double	julia_x;
	double	julia_y;
	
}		t_fractal;

//math
double  map(double uns_nb, double n_min, double n_max, double o_min, double o_max);
t_complex       sum_complex(t_complex z1, t_complex z2);
t_complex       square_complex(t_complex z);

//hooks_events
int	key_handler(int	keysym, t_fractal *fractal);
int	close_handler(t_fractal *fractal);


#endif
