/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:28:00 by aldferna          #+#    #+#             */
/*   Updated: 2025/01/13 20:32:51 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	close_esc(void *param) // param se pasa en el bucle de eventos de MLX
{
	mlx_t *mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE)) // y para resto de teclas
		mlx_close_window(mlx);
}

void	isometric(t_fdf *fdf)
{
	int			x;
	int			y;
	int			z;
	const int	posx = fdf->cam_x;
	const int	posy = fdf->cam_y;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			z = fdf->matrix[y][x].z * 2;
			fdf->matrix[y][x].x_iso = posx + (fdf->zoom * (x - y) * cos(0.523599));
			fdf->matrix[y][x].y_iso = posy + (fdf->zoom * (x + y) * sin(0.523599) - z);
			//fdf->matrix[y][x].x_iso = posx + fdf->zoom * (y - x) * cos(60);
			//fdf->matrix[y][x].y_iso = posy - fdf->zoom * (x + y) * sin(60) - z;
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	(void)argc;
	/*if (argc != 2)
		return(1);*/
	fill_matrix(argv[1], &fdf);
	fdf.mlx = mlx_init(fdf.win_width, fdf.win_height, "FDF", false);
	if (!fdf.mlx)
		return (1);
	fdf.img = mlx_new_image(fdf.mlx, fdf.win_width, fdf.win_height);
	if (!fdf.img || (mlx_image_to_window(fdf.mlx, fdf.img, 0, 0) < 0))
		return (1);

	isometric(&fdf);
	matrix_to_lines(&fdf);
	//test_draw_lines(&fdf, 100, 100, 50);
	mlx_loop_hook(fdf.mlx, &close_esc, fdf.mlx);
	mlx_loop(fdf.mlx);
	mlx_terminate(fdf.mlx);
	exit(0); // sin liberar memoria
}

// segun tamano del mapa ajustar zoom

//seg faul read memory access --> incompleto_   50-4   pylone
//seg faul write memory access --> incompleto_    100-6
//no pinta coordenadas con color_    elem-col
//height 0 (como si estuviera vacio)_    elem-fract   julia   pyra  t1   t2
//overflow_    mars
//sin alturas_   pyramide




//ok:
//esta formula da segment fault y no deberia
// fdf->matrix[y][x].x_iso = posx + fdf->zoom * (x - y) * cos(0.523599);
// fdf->matrix[y][x].y_iso = posy - fdf->zoom * (x + y) * sin(0.523599) - z;

// poner algun limites al dibujar---q no se salga fuera	-antes de dibujar comprobar
// el primer calloc en fill_matrix