/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:46:03 by nromito           #+#    #+#             */
/*   Updated: 2024/01/31 18:06:08 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_close(t_datas *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free (data->mlx);
	exit (0);
}

int	ft_error(t_datas *data)
{
	free (data->mlx);
	free (data->window);
	return (MLX_ERROR);
}

void	check_num(const char *argv, int a)
{
	if (argv[a] != '\0')
	{
		ft_putstr_fd("Error:type 'mandelbrot','julia x y', 'geena x y'\n", 1);
		exit (MLX_ERROR);
	}
}
