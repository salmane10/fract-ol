/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slouham <slouham@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:44:56 by slouham           #+#    #+#             */
/*   Updated: 2024/07/18 14:55:28 by slouham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> 
# include <math.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH	800
# define HEIGHT	800

//colors
# define BLACK			0x000000
# define WHITE			0xFFFFFF
# define RED     		0xFF0000
# define GREEN   		0x00FF00
# define BLUE    		0x0000FF
# define YELLOW          0xFFFF00
# define CYAN            0x00FFFF
# define MAGENTA         0xFF00FF
# define SILVER          0xC0C0C0
# define GRAY            0x808080
# define MAROON          0x800000
# define OLIVE           0x808000
# define PURPLE          0x800080
# define TEAL            0x008080
# define NAVY            0x000080
# define ORANGE          0xFFA500
# define PINK            0xFFC0CB
# define BROWN           0xA52A2A
# define GOLD            0xFFD700
# define VIOLET          0xEE82EE
# define INDIGO          0x4B0082

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_params
{
	double	n_min;
	double	n_max;
	double	o_min;
	double	o_max;
}			t_params;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_fractal
{
	void	*mlx_connection;
	void	*mlx_window;
	char	*name;
	t_img	img;
	double	escape_value;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractal;

//fractol
void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);

//math
double		map(double unsc_nb, t_params params);

t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);

//hooks_events
int			mouse_handler(int botton, int x, int y, t_fractal *fractal);
int			key_handler(int keysym, t_fractal *fractal);
int			close_handler(t_fractal *fractal);

//utils
int			ft_strncmp(char *s1, char *s2, int n);
double		atodbl(char *s);

#endif