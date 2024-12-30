/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:25:59 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/30 14:52:25 by aldferna         ###   ########.fr       */
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
	int			win_width;  //1920
	int			win_height; //1080
	int			zoom; //fdf->win_height / 100
	int			cam_x;
	int			cam_y;
}				t_fdf;

void			fill_matrix(char *file_name, t_fdf *fdf);
int				ft_atoi_hexa(const char *nptr);

// bresenham
void			matrix_to_lines(t_fdf *fdf);

#endif