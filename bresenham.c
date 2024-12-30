/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:06:04 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/30 19:10:49 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void swap_coordenates(int **coordenate)
{
	int aux;
	
	aux = (*coordenate)[X];
	(*coordenate)[X] = (*coordenate)[X1];
	(*coordenate)[X1] = aux;
	aux = (*coordenate)[Y];
	(*coordenate)[Y] = (*coordenate)[Y1];
	(*coordenate)[Y1] = aux;
}

void	draw_line_V(int *coordenate, t_fdf *fdf, int *iter)
{
	int p;
	int i;
	int dir;
	int dx;
	int dy;

	if (coordenate[Y] > coordenate[Y1])
		swap_coordenates(&coordenate);
	dx = coordenate[X1] - coordenate[X];
	dy = coordenate[Y1] - coordenate[Y];
	if (dx < 0)
		dir = -1;
	else
		dir = 1;
	dx *= dir;
	i = 0;
	p = 2*dx - dy;
	while (i < abs(dy))
	{
		coordenate[Y] += 1;
		if (p >= 0)
		{
			coordenate[X] += dir;
			p = p - 2*dy;
		}
		p = p + 2*dx;
		//printf("%u\n", fdf->matrix[iter[1]][iter[0]].color);
		//printf("%i\n", fdf->matrix[iter[1]][iter[0]].color);
		mlx_put_pixel(fdf->img, coordenate[X], coordenate[Y], fdf->matrix[iter[1]][iter[0]].color);
		i++;
	}
}

void	draw_line_H(int *coordenate, t_fdf *fdf, int *iter)
{
	int p;
	int i;
	int dir;
	int dx;
	int dy;

	if (coordenate[X] > coordenate[X1])
		swap_coordenates(&coordenate);
	dx = coordenate[X1] - coordenate[X];
	dy = coordenate[Y1] - coordenate[Y];
	if (dy < 0)
		dir = -1;
	else
		dir = 1;
	dy *= dir;
	i = 0;
	p = 2*dy - dx;
	while (i < abs(dx))
	{
		coordenate[X] += 1;
		if (p >= 0)
		{
			coordenate[Y] += dir;
			p = p - 2*dx;
		}
		p = p + 2*dy;              
		mlx_put_pixel(fdf->img, coordenate[X], coordenate[Y], fdf->matrix[iter[1]][iter[0]].color);
		i++;
	}
}

void	draw_line(int *coordenate, t_fdf *fdf, int *iter)
{
	int dx;
	int dy;

	dx = coordenate[X1] - coordenate[X];
	dy = coordenate[Y1] - coordenate[Y];
	// if (dx != 0)
	// {
		if (abs(dx) > abs(dy))
			draw_line_H(coordenate, fdf, iter);
		else
			draw_line_V(coordenate, fdf, iter);
	//}
}

void matrix_to_lines(t_fdf *fdf)
{
	int y;
	int x;
	t_node **matrix;
	int coordenate[4];
	int iter[2];

	matrix = fdf->matrix;
	y = 0;
	printf("height %i\n", fdf->height);
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			iter[0] = x;
			iter[1] = y;
			if (x < fdf->width - 1)
			{
				coordenate[X] = matrix[y][x].x_iso;
				coordenate[Y] = matrix[y][x].y_iso;
				coordenate[X1] = matrix[y][x + 1].x_iso;
				coordenate[Y1] = matrix[y][x + 1].y_iso;
				draw_line(coordenate, fdf, iter);
			}
			if (y < fdf->height - 1)
			{
				coordenate[X] = matrix[y][x].x_iso;
				coordenate[Y] = matrix[y][x].y_iso;	
				coordenate[X1] = matrix[y + 1][x].x_iso;
				coordenate[Y1] = matrix[y + 1][x].y_iso;
				draw_line(coordenate, fdf, iter);
			}
			x++;
		}
		y++;
	}
}


/*void test_draw_lines(t_fdf *fdf, int x, int y, int length)
{
    int coordenate[4];

    // Norte
    coordenate[X] = x;
    coordenate[Y] = y;
    coordenate[X1] = x;
    coordenate[Y1] = y - length;
    draw_line(coordenate, fdf);

    // Sur
    coordenate[X] = x;
    coordenate[Y] = y;
    coordenate[X1] = x;
    coordenate[Y1] = y + length;
    draw_line(coordenate, fdf);

    // Este
    coordenate[X] = x;
    coordenate[Y] = y;
    coordenate[X1] = x + length;
    coordenate[Y1] = y;
    draw_line(coordenate, fdf);

    // Oeste
    coordenate[X] = x;
    coordenate[Y] = y;
    coordenate[X1] = x - length;
    coordenate[Y1] = y;
    draw_line(coordenate, fdf);

    // Noreste
    coordenate[X] = x;
    coordenate[Y] = y;
    coordenate[X1] = x + length;
    coordenate[Y1] = y - length + 25;
    draw_line(coordenate, fdf);

    // Noroeste
    coordenate[X] = x;
    coordenate[Y] = y;
    coordenate[X1] = x - length;
    coordenate[Y1] = y - length + 25;
    draw_line(coordenate, fdf);

    // Sureste
    coordenate[X] = x;
    coordenate[Y] = y;
    coordenate[X1] = x + length - 40;
    coordenate[Y1] = y + length;
    draw_line(coordenate, fdf);

    // Suroeste
    coordenate[X] = x;
    coordenate[Y] = y;
    coordenate[X1] = x - length + 25;
    coordenate[Y1] = y + length;
    draw_line(coordenate, fdf);
}*/