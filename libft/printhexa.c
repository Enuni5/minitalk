/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunez-n <enunez-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:30:18 by enunez-n          #+#    #+#             */
/*   Updated: 2022/06/06 16:50:05 by enunez-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printptr(uintptr_t ptr)
{
	int	count;

	count = 2;
	write(1, "0x", 2);
	if (!ptr)
	{
		write(1, "0", 1);
		count++;
	}
	else
		count += ft_basehexa(ptr, 0);
	return (count);
}

int	ft_basehexa(unsigned long long num, int up)
{
	static int	count;

	count = 0;
	if (num >= 16)
		ft_basehexa(num / 16, up);
	if (up == 0)
	{
		ft_putchar_fd("0123456789abcdef"[num % 16], 1);
		count++;
	}
	else
	{
		ft_putchar_fd("0123456789ABCDEF"[num % 16], 1);
		count++;
	}
	return (count);
}
