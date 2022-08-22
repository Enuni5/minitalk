/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunez-n <enunez-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:31:55 by enunez-n          #+#    #+#             */
/*   Updated: 2022/04/28 16:55:08 by enunez-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	size_t	nblen;
	long	lonn;

	nblen = 0;
	lonn = n;
	if (lonn <= 0)
	{
		nblen++;
		lonn *= -1;
	}
	while (lonn > 0)
	{
		lonn /= 10;
		nblen++;
	}
	return (nblen);
}

char	*ft_itoa(int n)
{
	char	*itoad;
	size_t	nblen;
	long	nb;

	nblen = ft_nbrlen(n);
	itoad = malloc(nblen + 1);
	if (!itoad)
		return (0);
	itoad[nblen--] = '\0';
	if (n == 0)
		itoad[0] = '0';
	if (n < 0)
	{
		itoad[0] = '-';
		nb = -(long)n;
	}
	else
		nb = (long)n;
	while (nb > 0)
	{
		itoad[nblen--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (itoad);
}
