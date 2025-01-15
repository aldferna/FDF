/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:06:04 by aldferna          #+#    #+#             */
/*   Updated: 2025/01/15 20:32:41 by aldferna         ###   ########.fr       */
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

void	draw_line_V(int *c, t_fdf *fdf, int *it)
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
		if (c[X] > 1920 || c[Y] > 1080 || c[X] < 0 || c[Y] < 0)
			return ;
		mlx_put_pixel(fdf->img, c[X], c[Y], fdf->matrix[it[1]][it[0]].color);
		i++;
	}
}

/*void	my_put_pixel(int *c, t_fdf *fdf, int *it)
{
	if (c[X] > 1920 || c[Y] > 1080 || c[X] < 0 || c[Y] < 0)
		return ;
	mlx_put_pixel(fdf->img, c[X], c[Y], fdf->matrix[it[1]][it[0]].color);
}*/

void	draw_line_H(int *c, t_fdf *fdf, int *it)
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
		if (c[X] > 1920 || c[Y] > 1080 || c[X] < 0 || c[Y] < 0)
			return ;
		mlx_put_pixel(fdf->img, c[X], c[Y], fdf->matrix[it[1]][it[0]].color);
		//my_put_pixel(c, fdf, it);
		i++;
	}
}

void	draw_line(t_fdf *fdf, int *it, char line)
{
	int	dx;
	int	dy;
	int	coordenate[4];

	coordenate[X] = fdf->matrix[it[1]][it[0]].x_iso;
	coordenate[Y] = fdf->matrix[it[1]][it[0]].y_iso;
	if (line == 'h')
	{
		coordenate[X1] = fdf->matrix[it[1]][it[0] + 1].x_iso;
		coordenate[Y1] = fdf->matrix[it[1]][it[0] + 1].y_iso;
	}
	else if (line == 'v')
	{
		coordenate[X1] = fdf->matrix[it[1] + 1][it[0]].x_iso;
		coordenate[Y1] = fdf->matrix[it[1] + 1][it[0]].y_iso;
	}
	dx = coordenate[X1] - coordenate[X];
	dy = coordenate[Y1] - coordenate[Y]; // si 2 coord fuera no
	/*if ((coordenate[X] < 0 && coordenate[Y] < 0) || (coordenate[X1] < 0
			&& coordenate[Y1] < 0) || (coordenate[X] > 1920
			&& coordenate[Y] > 1080) || (coordenate[X1] > 1920
			&& coordenate[Y1] > 1080))
		return ;*/
	if (abs(dx) > abs(dy))
		draw_line_H(coordenate, fdf, it);
	draw_line_V(coordenate, fdf, it);
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

// void	draw_line_H(int *c, t_fdf *fdf, int *it)
// {
// 	int	p;
// 	int	i;
// 	int	dir;
// 	int	dx;
// 	int	dy;

// 	if (c[X] > c[X1])
// 		swap_coordenates(&c);
// 	dx = c[X1] - c[X];
// 	dy = c[Y1] - c[Y];
// 	if (dy < 0)
// 		dir = -1;
// 	else
// 		dir = 1;
// 	dy *= dir;
// 	i = 0;
// 	p = 2 * dy - dx;
// 	while (i < abs(dx))
// 	{
// 		c[X] += 1;
// 		if (p >= 0)
// 		{
// 			c[Y] += dir;
// 			p = p - 2 * dx;
// 		}
// 		p = p + 2 * dy;
// 		mlx_put_pixel(fdf->img, c[X], c[Y], fdf->matrix[it[1]][it[0]].color);
// 		i++;
// 	}
// }

/*void	draw_line(int *coordenate, t_fdf *fdf, int *iter)
{
	int	dx;
	int	dy;

	dx = coordenate[X1] - coordenate[X];
	dy = coordenate[Y1] - coordenate[Y];
	if (coordenate[X] < 0 || coordenate[Y] < 0 || coordenate[X1] < 0
		|| coordenate[Y1] < 0)
		return ;
	if (coordenate[X] > 1920 || coordenate[Y] > 1080 || coordenate[X1] > 1920
		|| coordenate[Y1] > 1080)
		return ;
	if (abs(dx) > abs(dy))
		draw_line_H(coordenate, fdf, iter);
	else
		draw_line_V(coordenate, fdf, iter);
}

void	matrix_to_lines(t_fdf *fdf)
{
	int y;
	int x;
	t_node **matrix;
	int coordenate[4];
	int it[2];

	matrix = fdf->matrix;
	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			it[0] = x;
			it[1] = y;
			if (x < fdf->width - 1)
			{
				coordenate[X] = matrix[y][x].x_iso;
				coordenate[Y] = matrix[y][x].y_iso;
				coordenate[X1] = matrix[y][x + 1].x_iso;
				coordenate[Y1] = matrix[y][x + 1].y_iso;
				draw_line(coordenate, fdf, it);
			}
			if (y < fdf->height - 1)
			{
				coordenate[X] = matrix[y][x].x_iso;
				coordenate[Y] = matrix[y][x].y_iso;
				coordenate[X1] = matrix[y + 1][x].x_iso;
				coordenate[Y1] = matrix[y + 1][x].y_iso;
				draw_line(coordenate, fdf, it);
			}
			x++;
		}
		y++;
	}
}*/
