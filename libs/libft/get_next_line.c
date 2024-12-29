/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:33:50 by aldferna          #+#    #+#             */
/*   Updated: 2024/10/22 19:08:08 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*last_line(char *storage, char *buffer)
{
	char	*line;

	if (!storage)
		return (free(buffer), NULL);
	if (!storage[0])
	{
		free(storage);
		storage = NULL;
		return (free(buffer), NULL);
	}
	line = ft_substr(storage, 0, ft_strlen(storage));
	free(storage);
	return (free(buffer), line);
}

char	*read_and_store(int fd, char *storage)
{
	int		bytesread;
	char	*buffer;
	char	*aux;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytesread = 1;
	while (!ft_strchr(storage, '\n') && bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
			return (free(buffer), free(storage), NULL);
		if (bytesread == 0)
			return (last_line(storage, buffer));
		buffer[bytesread] = '\0';
		aux = storage;
		storage = ft_strjoin(aux, buffer);
		free(aux);
		if (!storage)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (storage);
}

char	*find_line(char *storage)
{
	int		i;
	char	*line;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = ft_substr(storage, 0, i);
	return (line);
}

char	*new_storage(char *storage)
{
	int		i;
	char	*new_storage;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	new_storage = ft_substr(storage, i + 1, ft_strlen(storage) - i);
	free(storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = read_and_store(fd, storage);
	if (!storage)
		return (NULL);
	line = find_line(storage);
	if (!line)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = new_storage(storage);
	return (line);
}

/*int	main(void)
{
	int fd;
	char *line;

	fd = open("text3.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	printf("\n%s", line);
	close(fd);
	return (0);
}*/
