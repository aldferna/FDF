/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:49:48 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/24 15:38:07 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi_hexa(const char *nptr)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while (nptr[i] != '\0' && (nptr[i] == ' ' || nptr[i] == '\n'
			|| nptr[i] == '\t' || nptr[i] == '\f' || nptr[i] == '\v'
			|| nptr[i] == '\r'))
		i++;
    if (nptr[i] == '0' && (nptr[i + 1] == 'x' || nptr[i + 1] == 'X'))
        i += 2;
    while (nptr[i] != ' ' && nptr[i] != '\0' && nptr != NULL)
    {
        if (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
            number = number * 16 + (nptr[i] - 48);
        else if(nptr[i] >= 'A' && nptr[i] <= 'F')
            number =  number * 16 + (nptr[i] - 'A' + 10);
        else if(nptr[i] >= 'a' && nptr[i] <= 'f')
            number =  number * 16 + (nptr[i] - 'a' + 10);
        i++;
    }
	return (number);
}
        
/*int main()
{
    //int x = 0x820505; 8520965
    //int y = 0xFF9000; 16748544
    const char *color = "0xFF9000";
    ft_atoi_hexa(color);
}*/