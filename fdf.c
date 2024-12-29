/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:28:00 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/29 19:38:09 by aldferna         ###   ########.fr       */
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
	//test_draw_lines(&fdf, 100, 100, 50);
	mlx_loop_hook(fdf.mlx, &close_esc, fdf.mlx);
	mlx_loop(fdf.mlx);
	mlx_terminate(fdf.mlx);
	exit (0); //sin liberar memoria
}


//con julia height 0??
//raro con mapas con numeros negativos- ¿falta slope?¿guardo el - al parsear?
//definir zoom y ponerlo en el medio
//las ultimas lineas se pintan bien?
//poner algun limites al dibujar---q no se salga fuera