/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:51:50 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/30 19:15:52 by aldferna         ###   ########.fr       */
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

char	*fill_nodes(t_fdf *fdf, char **line, int x, int y)
{
	if ((**line >= '0' && **line <= '9') || **line == '-')
	{
		fdf->matrix[y][x].x = x;
		fdf->matrix[y][x].y = y;
		fdf->matrix[y][x].z = ft_atoi(*line);
		//printf("posicion %i - z: %i\n", x, fdf->matrix[y][x].z);
		fdf->matrix[y][x].color = 0xFF0000FF;
		(*line)++;
	}
	while (**line >= '0' && **line <= '9')
		(*line)++;
	if (**line == ',')
	{
		(*line)++;
		fdf->matrix[y][x].color = ft_atoi_hexa(*line);
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
		line_aux = fill_nodes(fdf, &line_aux, x, y);
		x++;
	}
}

void fill_matrix(char *file_name, t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		y;

	ft_memset(fdf, 0, sizeof(t_fdf));
	fdf->width = 2147483647;         //llevar alguna linea al main
	fdf->win_width = 1920;
	fdf->win_height = 1080;
	fdf->zoom = fdf->win_height / 25;
	fdf->cam_x = fdf->win_width / 2;
	fdf->cam_y = fdf->win_height / 3;
	fd = open(file_name, O_RDONLY);
	y = 0;
	fdf->matrix = ft_calloc(100, sizeof(t_node *));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[0] == '\n' || line[0] == ' ')
			return (free(line));
		fdf->height++;
		process_line(fdf, line, y);
		y++;
		free(line);
	}
	close(fd);
}
