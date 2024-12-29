/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:06:04 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/29 12:32:02 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	slope_greater_one(int *coordenate, int dx, int dy, t_fdf *fdf, int *itera)
{
	int p;
	int i;

	i = 0;
	p = 2*dy - dx;
	while (i < dy)
	{
		coordenate[Y] += 1;
		if (p >= 0)
		{
			coordenate[X] += 1;
			p = p + 2*dx - 2*dy;
		}
		else
			p = p + 2*dx;
		// printf("X: %d Y: %d\n", coordenate[X], coordenate[Y]);
		// printf("%u\n", fdf->matrix[coordenate[X]][coordenate[Y]].color);
		mlx_put_pixel(fdf->img, coordenate[X], coordenate[Y], fdf->matrix[itera[1]][itera[0]].color);
		//coordenate[Y] += 1;
		i++;
	}
}

void	slope_less_one(int *coordenate, int dx, int dy, t_fdf *fdf, int *itera)
{
	int p;
	int i;

	i = 0;
	p = 2*dy - dx;
	while (i < dx)
	{
		coordenate[X] += 1;
		if (p >= 0)
		{
			coordenate[Y] += 1;
			p = p + 2*dy - 2*dx;
		}
		else
			p = p + 2*dy;              
		//printf("%u\n", fdf->matrix[coordenate[Y]][coordenate[X]].color);  //multiplicar sumar aqui (poner slope -)
		//printf("%i %i\n", coordenate[Y], coordenate[X]);
		mlx_put_pixel(fdf->img, coordenate[X], coordenate[Y], fdf->matrix[itera[1]][itera[0]].color);
		//coordenate[X] += 1;
		i++;
	}
}

void	what_slope(int *coordenate, t_fdf *fdf, char line, int *itera)
{
	int dx = 0;
	int dy = 0;

	if (line == 'h')
	{
		dx = coordenate[X1] - coordenate[X];
		dy = coordenate[Y1] - coordenate[Y];
	}
	else if (line == 'v')
	{
		dx = coordenate[X2] - coordenate[X];
		dy = coordenate[Y2] - coordenate[Y];
	}
	if (dx != 0)
	{
		if (dy > dx)
			slope_greater_one(coordenate, dx, dy, fdf, itera);
		else if (dx > dy)
			slope_less_one(coordenate, dx, dy, fdf, itera);
		//si dx = dy?
	}
}

void matrix_to_lines(t_fdf *fdf)
{
	int y;
	int x;
	t_node **matrix;
	int coordenate[6];
	int itera[2];

	matrix = fdf->matrix;
	y = 0;
	printf("height %i\n", fdf->height);
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			coordenate[X] = matrix[y][x].x * zoom;
			coordenate[Y] = matrix[y][x].y * zoom;
			if (x < fdf->width - 1)
			{
				//printf("x: %i y: %i  -  x1: %i y1: %i  -  x2: %i y2: %i\n", coordenate[X], coordenate[Y], coordenate[X1], coordenate[Y1], coordenate[X2], coordenate[Y2]); //raro y
				itera[0] = x;
				itera[1] = y;
				coordenate[X1] = matrix[y][x + 1].x * zoom;
				coordenate[Y1] = matrix[y][x + 1].y * zoom;
				what_slope(coordenate, fdf, 'h', itera);
			}
			if (y < fdf->height - 1)
			{				
				//printf("height-1: %i - y:%i\n", fdf->height - 1, y); 
				//printf("x:%i, y:%i - x2:%i, y2:%i\n", matrix[y][x].x, matrix[y][x].y, matrix[y + 1][x].x, matrix[y + 1][x].y); 
				itera[0] = x;
				itera[1] = y;
				coordenate[X2] = matrix[y + 1][x].x * zoom;
				coordenate[Y2] = matrix[y + 1][x].y * zoom;
				what_slope(coordenate, fdf, 'v', itera);
			}
			x++;
		}
		y++;
	}
}