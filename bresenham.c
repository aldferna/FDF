/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:06:04 by aldferna          #+#    #+#             */
/*   Updated: 2025/01/17 17:29:40 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	swap_coordenates(int **coordenate, char line)
{
	int	aux;

	if ((*coordenate)[X] <= (*coordenate)[X1] && line == 'h')
		return ;
	if ((*coordenate)[Y] <= (*coordenate)[Y1] && line == 'v')
		return ;
	aux = (*coordenate)[X];
	(*coordenate)[X] = (*coordenate)[X1];
	(*coordenate)[X1] = aux;
	aux = (*coordenate)[Y];
	(*coordenate)[Y] = (*coordenate)[Y1];
	(*coordenate)[Y1] = aux;
}

void	draw_line_v(int *c, t_fdf *fdf, int *it)
{
	int	p;
	int	i;
	int	dir;
	int	dx;
	int	dy;

	swap_coordenates(&c, 'v');
	dx = c[X1] - c[X];
	dy = c[Y1] - c[Y];
	dir = check_direction(dx);
	dx *= dir;
	i = 0;
	p = 2 * dx - dy;
	while (i < abs(dy))
	{
		c[Y] += 1;
		if (p >= 0)
		{
			c[X] += dir;
			p = p - 2 * dy;
		}
		p = p + 2 * dx;
		my_put_pixel(c, fdf, it);
		i++;
	}
}

void	draw_line_h(int *c, t_fdf *fdf, int *it)
{
	int	p;
	int	i;
	int	dir;
	int	dx;
	int	dy;

	swap_coordenates(&c, 'h');
	dx = c[X1] - c[X];
	dy = c[Y1] - c[Y];
	dir = check_direction(dy);
	dy *= dir;
	i = 0;
	p = 2 * dy - dx;
	while (i < abs(dx))
	{
		c[X] += 1;
		if (p >= 0)
		{
			c[Y] += dir;
			p = p - 2 * dx;
		}
		p = p + 2 * dy;
		my_put_pixel(c, fdf, it);
		i++;
	}
}

void	draw_line(t_fdf *fdf, int *it, char line)
{
	int	dx;
	int	dy;
	int	coordenate[4];

	coordenate[X] = fdf->matrix[it[1]][it[0]].x_pers;
	coordenate[Y] = fdf->matrix[it[1]][it[0]].y_pers;
	if (line == 'h')
	{
		coordenate[X1] = fdf->matrix[it[1]][it[0] + 1].x_pers;
		coordenate[Y1] = fdf->matrix[it[1]][it[0] + 1].y_pers;
	}
	else if (line == 'v')
	{
		coordenate[X1] = fdf->matrix[it[1] + 1][it[0]].x_pers;
		coordenate[Y1] = fdf->matrix[it[1] + 1][it[0]].y_pers;
	}
	dx = coordenate[X1] - coordenate[X];
	dy = coordenate[Y1] - coordenate[Y];
	if (abs(dx) > abs(dy))
		draw_line_h(coordenate, fdf, it);
	draw_line_v(coordenate, fdf, it);
}

void	matrix_to_lines(t_fdf *fdf)
{
	int	y;
	int	x;
	int	it[2];

	ft_memset(fdf->img->pixels, 1, fdf->img->width * fdf->img->height * 4UL);
	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			it[0] = x;
			it[1] = y;
			if (x < fdf->width - 1)
				draw_line(fdf, it, 'h');
			if (y < fdf->height - 1)
				draw_line(fdf, it, 'v');
			x++;
		}
		y++;
	}
}
