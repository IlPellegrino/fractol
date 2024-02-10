/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:24:28 by nromito           #+#    #+#             */
/*   Updated: 2024/01/31 18:01:53 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	iteration_mandelbrot(t_complex pix, t_datas *data)
{
	t_complex	new;
	int			it;

	it = 0;
	new.imy = 0;
	new.real = 0;
	while (it < (MAX_ITER + data->iter)
		&& (new.real * new.real + new.imy * new.imy <= 4))
	{
		new = formula_mandelbrot(pix, new);
		it++;
	}
	return (it);
}

t_complex	formula_mandelbrot(t_complex pix, t_complex old)
{
	t_complex	ret;

	ret.real = (old.real * old.real - old.imy * old.imy + pix.real);
	ret.imy = (2 * old.real * old.imy + pix.imy);
	return (ret);
}

int	iteration_julia(t_complex new, t_datas *data)
{
	int			it;
	t_complex	costante;

	it = 0;
	costante.real = data->x;
	costante.imy = data->y;
	if (ft_strncmp(data->f_name, "julia", 5) == 0)
	{
		while (it < (MAX_ITER + data->iter)
			&& (new.real * new.real + new.imy * new.imy <= 4))
		{
			new = formula_julia(new, costante);
			it++;
		}
	}
	else if (ft_strncmp(data->f_name, "geena", 5) == 0)
	{
		while (it < (MAX_ITER + data->iter)
			&& (new.real * new.real + new.imy * new.imy <= 4))
		{
			new = formula_geena(new, costante);
			it++;
		}
	}
	return (it);
}

t_complex	formula_julia(t_complex old, t_complex costante)
{
	t_complex	ret;

	ret.real = old.real * old.real - old.imy * old.imy + costante.real;
	ret.imy = (2 * old.real * old.imy + costante.imy);
	return (ret);
}

t_complex	formula_geena(t_complex old, t_complex costante)
{
	t_complex	ret;

	ret.real = (old.real * old.real * old.real * old.real)
		- (6 * old.real * old.real * old.imy * old.imy)
		+ (old.imy * old.imy * old.imy * old.imy) + costante.real;
	ret.imy = ((4 * old.real * old.real * old.real * old.imy)
			- (4 * old.real * old.imy * old.imy * old.imy) + costante.imy);
	return (ret);
}
