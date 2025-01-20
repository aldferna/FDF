/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:25:59 by aldferna          #+#    #+#             */
/*   Updated: 2025/01/17 17:49:06 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libs/MLX42/include/MLX42/MLX42.h"
# include "libs/libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define X 0
# define Y 1
# define X1 2
# define Y1 3
//# define PI 3.14159265358979323846

typedef struct s_node
{
	int			x;
	int			x_pers;
	int			y;
	int			y_pers;
	int			z;
	int			color;
}				t_node;

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_node		**matrix;
	int			win_width;
	int			win_height;
	int			width;
	int			height;
	float		zoom;
	int			cam_x;
	int			cam_y;
	float		hook_z;
	int			z_adj;
}				t_fdf;

void			fill_matrix(char *file_name, t_fdf *fdf);
int				ft_atoi_hexa(const char *nptr);

int				fd_open(char *file_name);
void			init_fdf(t_fdf *fdf);

// bresenham
void			matrix_to_lines(t_fdf *fdf);
void			isometric(t_fdf *fdf);
int				check_direction(int delta);
void			my_put_pixel(int *c, t_fdf *fdf, int *it);

#endif