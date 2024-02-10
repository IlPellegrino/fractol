/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:41:44 by nromito           #+#    #+#             */
/*   Updated: 2024/01/31 18:15:18 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <time.h>
#include <stdio.h>

void	rendering(t_datas *data)
{
	short	x;
	short	y;

	y = -1;
	while (++y <= WIN_HEIGHT)
	{
		x = -1;
		while (++x <= WIN_WIDTH)
			pixel_management(x, y, data);
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
}

void	data_init(t_datas *data)
{
	data->iter = 1;
	data->color = 0;
	data->x = 0;
	data->y = 0;
	data->move_x = 0.0;
	data->move_y = 0.0;
	data->zoom = 1.0;
	data->shade_1 = BLACK;
	data->shade_2 = WHITE;
}

void	start(t_datas data)
{
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		ft_error(&data);
	data.window = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	if (data.window == NULL)
		ft_error(&data);
	data.img = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (data.img == NULL)
		ft_error(&data);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	mlx_key_hook(data.window, &key_events, &data);
	mlx_hook(data.window, 17, 1L << 17, &ft_close, &data);
	mlx_mouse_hook(data.window, &ft_zoom, &data);
	rendering(&data);
	mlx_loop(data.mlx);
}

int	main(int argc, char *argv[])
{
	t_datas	data;

	data_init(&data);
	data.f_name = argv[1];
	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		start(data);
	else if (argc == 4 && ((ft_strncmp(argv[1], "julia", 5) == 0)
			|| (ft_strncmp(argv[1], "geena", 5) == 0)))
	{
		data.x = ft_atod(argv[2]);
		data.y = ft_atod(argv[3]);
		start(data);
	}
	else
		ft_putstr_fd("Error:type 'mandelbrot','julia x y', 'geena x y'\n", 1);
	return (0);
}
