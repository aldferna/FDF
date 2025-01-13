/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:20:15 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/30 18:21:52 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	while (nptr[i] != '\0' && (nptr[i] == ' ' || nptr[i] == '\n'
			|| nptr[i] == '\t' || nptr[i] == '\f' || nptr[i] == '\v'
			|| nptr[i] == '\r'))
		i++;
	sign = 1;
	if (nptr[i] != '\0' && (nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	number = 0;
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		number = number * 10 + (nptr[i] - 48);
		i++;
	}
	//printf("zen atoi: %i\n", sign*number);
	return (sign * number);
}
