/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:42:35 by nromito           #+#    #+#             */
/*   Updated: 2024/01/31 19:02:17 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <string.h>
# include <X11/X.h>
# include <math.h>

# define MLX_ERROR 1

# define WIN_HEIGHT 500
# define WIN_WIDTH 1000

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define INDIGO 0x6F00FF
# define PINK 0xFF1493
# define MANGO_TANGO 0xFF8243
# define NEON_GREEN 0x39FF14
# define BRIGHT_YELLOW 0xFFFF00
# define PURPLE 0xBF00FF
# define SEA_GREEN 0x2E8B57
# define LIME_GREEN 0x32CD32
# define ORANGE 0xFFA500
# define AMETHYST 0x9966CC
# define CHARTREUSE 0x7FFF00
# define RED_CRIMSON 0xDC143C
# define GOLD 0xFFD700

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361

# define A 97
# define B 98
# define C 99
# define D 100
# define E 101
# define F 102
# define G 103
# define H 104
# define I 105
# define J 106
# define K 107
# define L 108
# define M 109
# define N 110
# define O 111
# define P 112
# define Q 113
# define R 114
# define S 115
# define T 116
# define U 117
# define V 118
# define W 119
# define X 120
# define Y 121
# define Z 122

# define MAX_ITER 500

typedef struct s_complex
{
	double	real;
	double	imy;
}				t_complex;

typedef struct s_datas
{
	double					x;
	double					y;
	double					move_x;
	double					move_y;
	double					zoom;
	void					*mlx;
	void					*result;
	void					*img;
	void					*window;
	char					*addr;
	char					*f_name;
	int						bits_per_pixel;
	int						line_length;
	int						endian;
	int						color;
	int						iter;
	int						shade_1;
	int						shade_2;
}				t_datas;

double			ft_map(double unscaled_num, double new_min,
					double new_max, double old_max);
t_complex		formula_mandelbrot(t_complex pix, t_complex old);
int				iteration_mandelbrot(t_complex pix, t_datas *data);
t_complex		formula_julia(t_complex old, t_complex costante);
int				iteration_julia(t_complex new, t_datas *data);
t_complex		formula_geena(t_complex old, t_complex costante);

void			my_mlx_pixel_put(t_datas *data, int x, int y, int color);
int				choose_iter(t_complex new, t_datas *data);
void			pixel_management(int x, int y, t_datas *data);
double			ft_atod(const char *str);

void			start(t_datas data);
void			rendering(t_datas *data);

int				ft_close(t_datas *data);
int				ft_error(t_datas *data);
void			check_num(const char *argv, int a);

int				key_events(int keycode, t_datas *data);
int				ft_colors_shade1(int keycode, t_datas *data);
int				ft_colors_shade2(int keycode, t_datas *data);
int				ft_arrows(int keycode, t_datas *data);
int				ft_zoom(int keycode, int x, int y, t_datas *data);

#endif