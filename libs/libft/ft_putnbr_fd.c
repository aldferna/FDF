/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:14:48 by aldferna          #+#    #+#             */
/*   Updated: 2024/10/07 16:51:07 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int i, int fd)
{
	char	c;

	if (i == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (i == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (i < 0)
	{
		write(fd, "-", 1);
		i = -i;
	}
	if (i >= 10)
		ft_putnbr_fd(i / 10, fd);
	c = (i % 10) + 48;
	write(fd, &c, 1);
}
