/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:16:12 by nromito           #+#    #+#             */
/*   Updated: 2024/01/31 18:13:19 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	my_mlx_pixel_put(t_datas *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = data->addr + (y * data->line_length
				+ x *(data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

double	ft_map(double unscaled_num, double new_min,
				double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num) / (old_max) + new_min);
}

int	choose_iter(t_complex new, t_datas *data)
{
	int	it;

	it = 0;
	if (ft_strncmp(data->f_name, "mandelbrot", 10) == 0)
		it = iteration_mandelbrot(new, data);
	else if (ft_strncmp(data->f_name, "julia", 5) == 0)
		it = iteration_julia(new, data);
	else if (ft_strncmp(data->f_name, "geena", 5) == 0)
		it = iteration_julia(new, data);
	return (it);
}

void	pixel_management(int x, int y, t_datas *data)
{
	t_complex	new;
	int			it;

	new.real = ft_map(x, -3, 3, WIN_WIDTH) * data->zoom + data->move_x;
	new.imy = ft_map(y, -1.5, 1.5, WIN_HEIGHT) * data->zoom + data->move_y;
	it = choose_iter(new, data);
	if (it == MAX_ITER + data->iter)
		my_mlx_pixel_put(data, x + data->move_x, y + data->move_y, BLACK);
	else
	{
		data->color = ft_map(it, data->shade_1,
				data->shade_2, MAX_ITER + data->iter);
		my_mlx_pixel_put(data, x + data->move_x,
			y + data->move_y, data->color);
	}
}

double	ft_atod(const char *argv)
{
	unsigned short		j;
	unsigned short		a;
	double				num;
	double				r;

	j = 0;
	a = 0;
	num = 0;
	r = 0;
	if (argv[a] == 45)
		a++;
	while (argv[a] <= 57 && argv[a] >= 48)
		num = (10 * num) + argv[a++] - 48;
	if (argv[a] == 46)
	{
		j = a;
		a++;
		while (argv[a] <= 57 && argv[a] >= 48)
			r = (10 * r) + argv[a++] - 48;
	}
	check_num(argv, a);
	num += r / pow(10, a - j - 1);
	if (argv[0] == '-')
		return (num * -1);
	return (num);
}
