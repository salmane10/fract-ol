/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:44:56 by slouham           #+#    #+#             */
/*   Updated: 2024/07/17 21:34:46 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FRACTOL_H
#define		FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <math.h>
#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

#define	WIDTH	800
#define HEIGHT	800

//colors
#define	BLACK			0x000000 //RGB(0, 0, 0)
#define WHITE			0xFFFFFF // RGB(255, 0, 0)
#define RED     		0xFF0000
#define GREEN   		0x00FF00
#define BLUE    		0x0000FF
#define YELLOW          0xFFFF00
#define CYAN            0x00FFFF
#define MAGENTA         0xFF00FF
#define SILVER          0xC0C0C0
#define GRAY            0x808080
#define MAROON          0x800000
#define OLIVE           0x808000
#define PURPLE          0x800080
#define TEAL            0x008080
#define NAVY            0x000080
#define ORANGE          0xFFA500
#define PINK            0xFFC0CB
#define BROWN           0xA52A2A
#define GOLD            0xFFD700
#define VIOLET          0xEE82EE
#define INDIGO          0x4B0082

typedef	struct	s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef	struct s_img
{
	void	*img_ptr; //pointer to image struct
	char	*pixels_ptr; //points to the actual pixels
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef	struct s_fractal
{
	//mlx
	void	*mlx_connection; //mlx_init()
	void	*mlx_window;	//mlx_new_window()
	char	*name;
	//Image
	t_img	img;
	
	//hooks variables
	double	escape_value; //hypotenuse
	int		iterations;  // value tight with the image quality & rendering
	double	shift_x;
	double	shift_y;
	double	zoom;
	
	//for julia
	double	julia_x;
	double	julia_y;
	
}		t_fractal;

//fractol
void	fractal_init(t_fractal *fractal);
void	fractal_render(t_fractal *fractal);

//math
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
double	map(double unsc_nb, double n_min, double n_max, double o_min, double o_max);

//hooks_events
int	key_handler(int	keysym, t_fractal *fractal);
int	close_handler(t_fractal *fractal);
int	mouse_handler(int botton, int x, int y, t_fractal *fractal);

//utils
double	atodbl(char *s);
int		ft_strncmp(char *s1, char *s2, int n);


#endif