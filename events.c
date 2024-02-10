/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:53:58 by nromito           #+#    #+#             */
/*   Updated: 2024/01/31 19:02:04 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	key_events(int keycode, t_datas *data)
{
	if (keycode == ESC)
		ft_close(data);
	else if (keycode == UP || keycode == RIGHT
		|| keycode == LEFT || keycode == DOWN)
		ft_arrows(keycode, data);
	else if (keycode == Q)
		data->iter += 1;
	else if (keycode == P)
		data->iter -= 1;
	ft_colors_shade2(keycode, data);
	ft_colors_shade1(keycode, data);
	if (keycode == G)
		data->f_name = "geena";
	else if (keycode == J)
		data->f_name = "julia";
	else if (keycode == M)
		data->f_name = "mandelbrot";
	mlx_clear_window(data->mlx, data->window);
	rendering(data);
	return (0);
}

int	ft_colors_shade2(int keycode, t_datas *data)
{
	if (keycode == H)
		data->shade_2 = AMETHYST;
	else if (keycode == K)
		data->shade_2 = SEA_GREEN;
	else if (keycode == L)
		data->shade_2 = INDIGO;
	else if (keycode == Z)
		data->shade_2 = CHARTREUSE;
	else if (keycode == X)
		data->shade_2 = ORANGE;
	else if (keycode == C)
		data->shade_2 = BLACK;
	else if (keycode == V)
		data->shade_2 = PURPLE;
	else if (keycode == B)
		data->shade_2 = RED_CRIMSON;
	else if (keycode == N)
		data->shade_2 = GOLD;
	else if (keycode == B)
		data->shade_2 = BRIGHT_YELLOW;
	else if (keycode == N)
		data->shade_2 = WHITE;
	return (0);
}

int	ft_colors_shade1(int keycode, t_datas *data)
{
	if (keycode == W)
		data->shade_1 = AMETHYST;
	else if (keycode == E)
		data->shade_1 = SEA_GREEN;
	else if (keycode == R)
		data->shade_1 = INDIGO;
	else if (keycode == T)
		data->shade_1 = CHARTREUSE;
	else if (keycode == Y)
		data->shade_1 = ORANGE;
	else if (keycode == U)
		data->shade_1 = BLACK;
	else if (keycode == I)
		data->shade_1 = PURPLE;
	else if (keycode == O)
		data->shade_1 = RED_CRIMSON;
	else if (keycode == A)
		data->shade_1 = GOLD;
	else if (keycode == S)
		data->shade_1 = BRIGHT_YELLOW;
	else if (keycode == D)
		data->shade_1 = NEON_GREEN;
	else if (keycode == F)
		data->shade_1 = WHITE;
	return (0);
}

int	ft_arrows(int keycode, t_datas *data)
{
	if (keycode == DOWN)
		data->move_y += (0.25 * data->zoom);
	else if (keycode == UP)
		data->move_y -= (0.25 * data->zoom);
	else if (keycode == LEFT)
		data->move_x -= (0.25 * data->zoom);
	else if (keycode == RIGHT)
		data->move_x += (0.25 * data->zoom);
	return (0);
}

int	ft_zoom(int keycode, int x, int y, t_datas *data)
{
	double	old_x;
	double	old_y;
	double	new_x;
	double	new_y;

	old_x = ft_map(x, -3, 3, WIN_WIDTH) * data->zoom + data->move_x;
	old_y = ft_map(y, -1.5, 1.5, WIN_HEIGHT) * data->zoom + data->move_y;
	if (keycode == Button4)
		data->zoom *= 0.95;
	if (keycode == Button5)
		data->zoom *= 1.05;
	new_x = ft_map(x, -3, 3, WIN_WIDTH) * data->zoom + data->move_x;
	new_y = ft_map(y, -1.5, 1.5, WIN_HEIGHT) * data->zoom + data->move_y;
	data->move_x += old_x - new_x;
	data->move_y += old_y - new_y;
	rendering(data);
	return (0);
}
