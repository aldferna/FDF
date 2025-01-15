/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:38:33 by aldferna          #+#    #+#             */
/*   Updated: 2025/01/15 20:06:47 by aldferna         ###   ########.fr       */
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
			z = fdf->matrix[y][x].z * 2 * fdf->zoom / 60 ;
			fdf->matrix[y][x].x_iso = posx + (fdf->zoom * (x - y) * cos(0.523599));
			fdf->matrix[y][x].y_iso = posy + (fdf->zoom * (x + y) * sin(0.523599) - z);
			x++;
		}
		y++;
	}
}
