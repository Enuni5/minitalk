/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunez-n <enunez-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:29:47 by enunez-n          #+#    #+#             */
/*   Updated: 2022/08/24 07:42:41 by enunez-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_bits(unsigned char c_byte, int server_pid)
{
	int				i;
	unsigned char	bit;

	i = 7;
	while (i)
	{
		bit = (c_byte >> i & 1) + '0';
		if (bit == '1')
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(100);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*str;

	if (argc != 3 | ft_strlen(argv[2]) == 0)
	{
		ft_printf("Invalid arguments. Check server id / message sent");
		return (0);
	}
	str = argv[2];
	server_pid = ft_atoi(argv[1]);
	while (str)
	{
		send_bits(&str, server_pid);
		str++;
	}
	return (0);
}
