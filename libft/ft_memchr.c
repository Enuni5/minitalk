/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunez-n <enunez-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:21:05 by enunez-n          #+#    #+#             */
/*   Updated: 2022/04/25 12:20:46 by enunez-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	cins;
	size_t			i;

	ptr = (unsigned char *)s;
	cins = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == cins)
			return (ptr + i);
		i++;
	}
	return (0);
}
