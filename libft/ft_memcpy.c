/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunez-n <enunez-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:47:47 by enunez-n          #+#    #+#             */
/*   Updated: 2022/04/25 11:57:25 by enunez-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t		count;
	char		*d;
	const char	*s;

	count = 0;
	d = dst;
	s = src;
	if (d == 0 && s == 0)
		return (NULL);
	if (dst != src)
	{
		while (count < len)
		{
			d[count] = s[count];
			count++;
		}
	}
	return (dst);
}
