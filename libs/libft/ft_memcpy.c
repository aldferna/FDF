/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:22:41 by aldferna          #+#    #+#             */
/*   Updated: 2024/10/09 16:41:36 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ud;
	const unsigned char	*us;

	if (dest == NULL && src == NULL)
		return (NULL);
	ud = (unsigned char *)dest;
	us = (const unsigned char *)src;
	while (n > 0)
	{
		ud[n - 1] = us[n - 1];
		n--;
	}
	return (dest);
}
