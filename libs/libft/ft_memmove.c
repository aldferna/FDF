/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:37:12 by aldferna          #+#    #+#             */
/*   Updated: 2024/10/08 21:59:30 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	make_copy(unsigned char *ud, const unsigned char *us, size_t n)
{
	size_t	i;

	if (us < ud)
	{
		while (n > 0)
		{
			ud[n - 1] = us[n - 1];
			n--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			ud[i] = us[i];
			i++;
		}
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ud;
	const unsigned char	*us;

	if (dest == NULL && src == NULL)
		return (NULL);
	us = (const unsigned char *)src;
	ud = (unsigned char *)dest;
	make_copy(ud, us, n);
	return (dest);
}
