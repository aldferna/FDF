/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:28:00 by aldferna          #+#    #+#             */
/*   Updated: 2025/01/17 17:49:17 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_hook(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->cam_y += 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->cam_y -= 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		fdf->cam_x += 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		fdf->cam_x -= 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_0))
		fdf->hook_z -= 0.3;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_1))
		fdf->hook_z += 0.3;
	isometric(fdf);
	matrix_to_lines(fdf);
}

void	zoom_hook(double xdelta, double ydelta, void *param)
{
	t_fdf	*fdf;

	(void)xdelta;
	fdf = (t_fdf *)param;
	if (ydelta > 0)
		fdf->zoom *= 1.1;
	else if (ydelta < 0)
		fdf->zoom *= 0.9;
	isometric(fdf);
	matrix_to_lines(fdf);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		return (1);
	ft_memset(&fdf, 0, sizeof(t_fdf));
	fill_matrix(argv[1], &fdf);
	fdf.mlx = mlx_init(fdf.win_width, fdf.win_height, "FDF", false);
	if (!fdf.mlx)
		return (1);
	fdf.img = mlx_new_image(fdf.mlx, fdf.win_width, fdf.win_height);
	if (!fdf.img || (mlx_image_to_window(fdf.mlx, fdf.img, 0, 0) < 0))
		return (1);
	isometric(&fdf);
	matrix_to_lines(&fdf);
	mlx_scroll_hook(fdf.mlx, &zoom_hook, &fdf);
	mlx_loop_hook(fdf.mlx, &key_hook, &fdf);
	mlx_loop(fdf.mlx);
	mlx_terminate(fdf.mlx);
	exit(0);
}
