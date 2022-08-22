/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunez-n <enunez-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:59:08 by enunez-n          #+#    #+#             */
/*   Updated: 2022/04/25 10:15:18 by enunez-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!(unsigned char *)dst && !(unsigned char *)src)
		return (NULL);
	while (i < len)
	{
		if (dst < src)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		else
			((unsigned char *)dst)[len - i - 1] = ((unsigned char *)src)[len - i
				- 1];
		i++;
	}
	return (dst);
}
