/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:51:50 by aldferna          #+#    #+#             */
/*   Updated: 2025/01/15 18:31:57 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_width(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
			count++;
		if (line[i] == '-')
			i++;
		i++;
		while (line[i] != '\0' && line[i - 1] != ' ')
			i++;
	}
	return (count);
}

char	*fill_node(t_fdf *fdf, char **line, int x, int y)
{
	while (**line == ' ' || **line == '\t')
		(*line)++;
	if ((**line >= '0' && **line <= '9') || **line == '-')
	{
		fdf->matrix[y][x].x = x;
		fdf->matrix[y][x].y = y;
		fdf->matrix[y][x].z = ft_atoi(*line);
		fdf->matrix[y][x].color = 0xFF0FF0FF;
		(*line)++;
	}
	while (**line >= '0' && **line <= '9')
		(*line)++;
	if (**line == ',')
	{
		(*line)++;
		fdf->matrix[y][x].color = ((ft_atoi_hexa(*line) << 8) | 0xFF);
	}
	while (**line != '\0' && **line != ' ' && **line != '\t')
		(*line)++;
	while (**line == ' ' || **line == '\t')
		(*line)++;
	return (*line);
}

void	process_line(t_fdf *fdf, char *line, int y)
{
	int		x;
	char	*line_aux;
	int		current_width;

	current_width = count_width(line);
	if (current_width < fdf->width)
		fdf->width = current_width;
	fdf->matrix[y] = ft_calloc(current_width + 1, sizeof(t_node));
	x = 0;
	line_aux = line;
	while (x < fdf->width)
	{
		line_aux = fill_node(fdf, &line_aux, x, y);
		x++;
	}
}

void resize_matrix(t_fdf *fdf, int *space)
{
	t_node **aux_matrix;
	int y;

	aux_matrix = ft_calloc((*space) * 2, sizeof(t_node *));
	y = 0;
	while (y < (*space))
	{
		aux_matrix[y] = fdf->matrix[y];
		y++;
	}
	(*space) *= 2;
	free(fdf->matrix);
	fdf->matrix = aux_matrix;
	write(1, "loading...\n", 12);
}

void fill_matrix(char *file_name, t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		y;
	int		space;

	fdf->width = 2147483647;
	fd = fd_open(file_name);	
	y = 0;
	space = 100;
	fdf->matrix = ft_calloc(space, sizeof(t_node *));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		fdf->height++;
		if (y == space)
			resize_matrix(fdf, &space);
		process_line(fdf, line, y);
		y++;
		free(line);
	}
	close(fd);
	init_fdf(fdf);
}
