/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunez-n <enunez-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:29:40 by enunez-n          #+#    #+#             */
/*   Updated: 2022/08/25 17:17:55 by enunez-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	receive_bits(int sig)
{
	static unsigned char	str = 0;
	static int				bit_pos = 7;

	if (sig == SIGUSR2)
		str = (1 << bit_pos) | str;
	bit_pos--;
	if (bit_pos < 0)
	{
		if (str == '\0')
		{
			bit_pos = 7;
			ft_printf("\n");
			return ;
		}
		ft_printf("%c", str);
		bit_pos = 7;
		str = 0;
	}
}

int	main(void)
{
	ft_printf("\nSERVER PID: %d\n\n", getpid());
	signal(SIGUSR1, receive_bits);
	signal(SIGUSR2, receive_bits);
	while (1)
		pause();
	return (0);
}
