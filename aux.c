/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:40:14 by aldferna          #+#    #+#             */
/*   Updated: 2025/01/17 17:51:46 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fd_open(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		write(1, "error\n", 7);
		exit(0);
	}
	return (fd);
}

void	init_fdf(t_fdf *fdf)
{
	fdf->win_width = 1920;
	fdf->win_height = 1080;
	fdf->cam_x = fdf->win_width / 2;
	fdf->cam_y = fdf->win_height / 20;
	fdf->hook_z = 5;
	if (fdf->height > fdf->width)
		fdf->zoom = 1000 / fdf->height;
	else
		fdf->zoom = 1000 / fdf->width;
	if (fdf->zoom < 40)
		fdf->z_adj = 18;
	else
		fdf->z_adj = 2;
}

int	check_direction(int delta)
{
	int	dir;

	if (delta < 0)
		dir = -1;
	else
		dir = 1;
	return (dir);
}

void	my_put_pixel(int *c, t_fdf *fdf, int *it)
{
	if ((c[X] >= 0 && c[X] <= 1920) && (c[Y] >= 0 && c[Y] <= 1080))
		mlx_put_pixel(fdf->img, c[X], c[Y], fdf->matrix[it[1]][it[0]].color);
}
