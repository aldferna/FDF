/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:25:59 by aldferna          #+#    #+#             */
/*   Updated: 2025/01/15 19:54:47 by aldferna         ###   ########.fr       */
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

typedef struct s_node
{
	int			x;
	int			x_iso;
	int			y;
	int			y_iso;
	int			z;
	int			color;
}				t_node;

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_node		**matrix;
	int			width;
	int			height;
	int			win_width;
	int			win_height;
	float		zoom;
	int			cam_x;
	int			cam_y;
	int			change_z;
}				t_fdf;

void			fill_matrix(char *file_name, t_fdf *fdf);
int				ft_atoi_hexa(const char *nptr);

int				fd_open(char *file_name);
void			init_fdf(t_fdf *fdf);

// bresenham
void			matrix_to_lines(t_fdf *fdf);
void			isometric(t_fdf *fdf);
int				check_direction(int delta);

#endif