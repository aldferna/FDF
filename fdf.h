/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:25:59 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/29 19:33:15 by aldferna         ###   ########.fr       */
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
# define X2 4
# define Y2 5

# define zoom 25

typedef struct s_node
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_node;

typedef struct s_fdf
{
	t_node		**matrix;
	int			width;
	int			height;
	mlx_t		*mlx;
	mlx_image_t	*img;
}				t_fdf;

void			fill_matrix(char *file_name, t_fdf *fdf);
int				ft_atoi_hexa(const char *nptr);

// breseham
void			matrix_to_lines(t_fdf *fdf);

#endif