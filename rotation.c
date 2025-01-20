/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:51:11 by aldferna          #+#    #+#             */
/*   Updated: 2025/01/17 17:27:42 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_x_matrix(t_fdf *fdf, float alpha)
{
	int			temp;
	int			x;
	int			y;
	t_node		fdfm;
	const float	alp_rad = alpha * (PI / 180.0);

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			fdfm = fdf->matrix[y][x];
			temp = fdf->matrix[y][x].y;
			fdf->matrix[y][x].y = temp * cos(alp_rad) - fdfm.z * sin(alp_rad);
			fdf->matrix[y][x].z = temp * sin(alp_rad) + fdfm.z * cos(alp_rad);
			x++;
		}
		y++;
	}
}

void	rotation_y_matrix(t_fdf *fdf, float alpha)
{
	int			temp;
	int			x;
	int			y;
	t_node		fdfm;
	const float	alp_rad = alpha * (PI / 180.0);

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			fdfm = fdf->matrix[y][x];
			temp = fdf->matrix[y][x].x;
			fdf->matrix[y][x].x = temp * cos(alp_rad) + fdfm.z * sin(alp_rad);
			fdf->matrix[y][x].z = fdfm.z * cos(alp_rad) - temp * sin(alp_rad);
			x++;
		}
		y++;
	}
}

void	rotation_z_matrix(t_fdf *fdf, float alpha)
{
	int			temp;
	int			x;
	int			y;
	t_node		fdfm;
	const float	alp_rad = alpha * (PI / 180.0);

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			fdfm = fdf->matrix[y][x];
			temp = fdf->matrix[y][x].x;
			fdf->matrix[y][x].x = temp * cos(alp_rad) - fdfm.y * sin(alp_rad);
			fdf->matrix[y][x].y = temp * sin(alp_rad) + fdfm.y * cos(alp_rad);
			x++;
		}
		y++;
	}
}

/*if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
{
	fdf->alpha += 0.1;
	rotation_X_matrix(fdf, fdf->alpha);
}
if	(mlx_is_key_down(fdf->mlx, MLX_KEY_S))
{
	fdf->alpha += 0.1;
	rotation_Y_matrix(fdf, fdf->alpha);
}
if	(mlx_is_key_down(fdf->mlx, MLX_KEY_D))
{
	fdf->alpha += 0.1;
	rotation_Z_matrix(fdf, fdf->alpha);
}*/