/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunez-n <enunez-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 07:30:16 by enunez-n          #+#    #+#             */
/*   Updated: 2022/05/18 07:26:52 by enunez-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Allocates memory in a safe way filling it with zeros

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count + size < count || count + size < size)
		return (0);
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ptr = malloc(size * count);
	if (ptr)
		ft_bzero(ptr, count * size);
	return (ptr);
}
