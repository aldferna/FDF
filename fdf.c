/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:28:00 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/29 14:40:23 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	close_esc(void *param) // param se pasa en el bucle de eventos de MLX
{
	mlx_t *mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void	draw_line_V(int *coordenate, t_fdf *fdf, int *itera)
{
	int p;
	int i;
	int dir;
	int dx;
	int dy;
	int aux;

	if (coordenate[Y] > coordenate[Y2])
	{
		aux = coordenate[X];
		coordenate[X] = coordenate[X2];
		coordenate[X2] = aux;
		aux = coordenate[Y];
		coordenate[Y] = coordenate[Y2];
		coordenate[Y2] = aux;
	}
	dx = coordenate[X2] - coordenate[X];
	dy = coordenate[Y2] - coordenate[Y];
	if (dx < 0)
		dir = -1;
	else
		dir = 1;
	dx *= dir;
	i = 0;
	p = 2*dx - dy;
	while (i < abs(dy) * zoom)
	{
		coordenate[Y] += 1;
		mlx_put_pixel(fdf->img, coordenate[X] * zoom, coordenate[Y] * zoom, fdf->matrix[itera[1]][itera[0]].color);
		if (p >= 0)
		{
			coordenate[X] += dir;
			p = p - 2*dy;
		}
		p = p + 2*dx;              
		i++;
	}
}

void	draw_line_H(int *coordenate, t_fdf *fdf, int *itera)
{
	int p;
	int i;
	int dir;
	int dx;
	int dy;
	int aux;

	if (coordenate[X] > coordenate[X1])
	{
		aux = coordenate[X];
		coordenate[X] = coordenate[X1];
		coordenate[X1] = aux;
		aux = coordenate[Y];
		coordenate[Y] = coordenate[Y1];
		coordenate[Y1] = aux;
	}
	dx = coordenate[X1] - coordenate[X];
	dy = coordenate[Y1] - coordenate[Y];
	if (dy < 0)
		dir = -1;
	else
		dir = 1;
	dy *= dir;
	i = 0;
	p = 2*dy - dx;
	while (i < abs(dx) * zoom)
	{
		coordenate[X] += 1;
		mlx_put_pixel(fdf->img, coordenate[X] * zoom, coordenate[Y] * zoom, fdf->matrix[itera[1]][itera[0]].color);
		if (p >= 0)
		{
			coordenate[Y] += dir;
			p = p - 2*dx;
		}
		p = p + 2*dy;              
		i++;
	}

}

void	what_pair_coordenates(int *coordenate, t_fdf *fdf, char line, int *itera)
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
		if (abs(dy) > abs(dx))
			draw_line_V(coordenate, fdf, itera);
		else
			draw_line_H(coordenate, fdf, itera);
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
			coordenate[X] = matrix[y][x].x;
			coordenate[Y] = matrix[y][x].y;
			if (x < fdf->width - 1)
			{
				//printf("x: %i y: %i  -  x1: %i y1: %i  -  x2: %i y2: %i\n", coordenate[X], coordenate[Y], coordenate[X1], coordenate[Y1], coordenate[X2], coordenate[Y2]); //raro y
				itera[0] = x;
				itera[1] = y;
				coordenate[X1] = matrix[y][x + 1].x;
				coordenate[Y1] = matrix[y][x + 1].y;
				what_pair_coordenates(coordenate, fdf, 'h', itera);
			}
			if (y < fdf->height - 1)
			{				
				//printf("height-1: %i - y:%i\n", fdf->height - 1, y); 
				//printf("x:%i, y:%i - x2:%i, y2:%i\n", matrix[y][x].x, matrix[y][x].y, matrix[y + 1][x].x, matrix[y + 1][x].y); 
				itera[0] = x;
				itera[1] = y;
				coordenate[X2] = matrix[y + 1][x].x;
				coordenate[Y2] = matrix[y + 1][x].y;
				what_pair_coordenates(coordenate, fdf, 'v', itera);
			}
			x++;
		}
		y++;
	}
}



/*void draw_line(int *coordenate, t_fdf *fdf, int *itera, char line)
{
	if (line == 'v')
	{
		if (abs(coordenate[X2] - coordenate[X]) > (abs(coordenate[Y2] - coordenate[Y])))
			draw_line_H(coordenate, fdf, itera);
		else	
			draw_line_V(coordenate, fdf, itera);
	}
	if (line == 'h')
	{
		if (abs(coordenate[X1] - coordenate[X]) > (abs(coordenate[Y1] - coordenate[Y])))
			draw_line_H(coordenate, fdf, itera);
		else
			draw_line_V(coordenate, fdf, itera);
	}

}*/


int	main(int argc, char **argv)
{
	t_fdf	fdf;

	(void)argc;
	/*if (argc != 2)
		return(1);*/
	fill_matrix(argv[1], &fdf);
	fdf.mlx = mlx_init(1920, 1080, "FDF", true);
	if (!fdf.mlx)
		return (1);
	fdf.img = mlx_new_image(fdf.mlx, 500, 500);
	if (!fdf.img || (mlx_image_to_window(fdf.mlx, fdf.img, 0, 0) < 0))
		return (1);
	matrix_to_lines(&fdf);
	mlx_loop_hook(fdf.mlx, &close_esc, fdf.mlx);
	mlx_loop(fdf.mlx);
	mlx_terminate(fdf.mlx);
	exit (0); //sin liberar memoria
}

//con julia height 0
//raro con mapas con numeros negativos- ¿falta slope?¿guardo el -?
//definir zoom y ponerlo en el medio
//las ultimas lineas
