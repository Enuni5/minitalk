/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdigits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunez-n <enunez-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:29:52 by enunez-n          #+#    #+#             */
/*   Updated: 2022/06/06 16:50:06 by enunez-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printdec(long num)
{
	int	count;

	count = ft_countdec(num);
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num *= -1;
	}
	if (num > 9)
	{
		ft_printdec(num / 10);
		ft_printdec(num % 10);
	}
	else
		ft_putchar_fd(num + '0', 1);
	return (count);
}

int	ft_countdec(long num)
{
	int	count;

	count = 0;
	if (num <= 0)
		count++;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	ft_printudec(unsigned long n)
{
	int	count;

	count = ft_countdec(n);
	if (n <= 4294967295 && n >= 0)
	{
		if (n > 9)
		{
			ft_printudec(n / 10);
			ft_printudec(n % 10);
		}
		else
			ft_putchar_fd(n + '0', 1);
	}
	return (count);
}
