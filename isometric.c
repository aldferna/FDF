/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:38:33 by aldferna          #+#    #+#             */
/*   Updated: 2025/01/17 17:50:49 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
			z = (fdf->matrix[y][x].z * fdf->z_adj * fdf->zoom / 60)
				* fdf->hook_z / 5;
			fdf->matrix[y][x].x_pers = posx + (fdf->zoom * (x - y)
					* cos(0.523599));
			fdf->matrix[y][x].y_pers = posy + (fdf->zoom * (x + y)
					* sin(0.523599) - z);
			x++;
		}
		y++;
	}
}

// void	isometric(t_fdf *fdf)
// {
// 	int			x;
// 	int			y;
// 	int			z;
// 	const int	posx = fdf->cam_x;
// 	const int	posy = fdf->cam_y;

// 	y = 0;
// 	while (y < fdf->height)
// 	{
// 		x = 0;
// 		while (x < fdf->width)
// 		{
// 			z = fdf->matrix[y][x].z * (2 * fdf->zoom / 60) + fdf->change_z;
// 			fdf->matrix[y][x].x_iso = posx + (fdf->zoom * (fdf->matrix[y][x].x
//						- fdf->matrix[y][x].y) * cos(0.523599));
// 			fdf->matrix[y][x].y_iso = posy + (fdf->zoom * (fdf->matrix[y][x].x
//						+ fdf->matrix[y][x].y) * sin(0.523599) - z);
// 			x++;
// 		}
// 		y++;
// 	}
// }
