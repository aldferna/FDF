/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:34:28 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/24 15:21:58 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str_new;
	size_t	len_s;
	size_t	i;

	len_s = ft_strlen((char *)s);
	if (start > len_s)
		return (NULL);
	if ((len_s - start) < len)
		len = len_s - start;
	str_new = (char *)malloc((len + 1) * (sizeof(char)));
	if (!str_new)
		return (NULL);
	i = 0;
	while ((s[start] != '\0') && (i < len))
		str_new[i++] = s[start++];
	str_new[i] = '\0';
	return (str_new);
}

/*void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*array;
	int				n;

	n = nmemb * size;
	array = malloc(nmemb * size);
	if (!array)
		return (NULL);
	while (n > 0)
	{
		array[n - 1] = '\0';
		n--;
	}
	return (array);
}*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size_s1;
	int		size_s2;
	char	*str;
	int		i;
	int		j;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	str = ft_calloc(size_s1 + size_s2 + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size_s1)
		str[i++] = s1[j++];
	j = 0;
	while (j < size_s2)
		str[i++] = s2[j++];
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == '\0' && (char)c != '\0')
		return (NULL);
	return ((char *)&s[i]);
}
