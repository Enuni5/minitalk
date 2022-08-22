/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunez-n <enunez-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:29:24 by enunez-n          #+#    #+#             */
/*   Updated: 2022/06/06 16:50:07 by enunez-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_printstring(char *str)
{
	int	count;

	if (!str)
		str = "(null)";
	count = 0;
	ft_putstr_fd(str, 1);
	count += ft_strlen(str);
	return (count);
}
