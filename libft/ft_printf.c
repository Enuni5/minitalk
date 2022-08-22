/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunez-n <enunez-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:17:09 by enunez-n          #+#    #+#             */
/*   Updated: 2022/06/06 16:50:04 by enunez-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printlen[1];

	*printlen = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			ft_evaluator(*(format + 1), args, printlen);
			format++;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			printlen[0] += 1;
		}
		format++;
	}
	return (*printlen);
}

void	ft_evaluator(const char conversion, va_list args, int *printlen)
{
	if (conversion == 'c')
		printlen[0] += ft_printchar(va_arg(args, int));
	else if (conversion == 's')
		printlen[0] += ft_printstring(va_arg(args, char *));
	else if (conversion == 'p')
		printlen[0] += ft_printptr(va_arg(args, unsigned long long));
	else if (conversion == 'd' || conversion == 'i')
		printlen[0] += ft_printdec(va_arg(args, int));
	else if (conversion == 'u')
		printlen[0] += ft_printudec(va_arg(args, unsigned int));
	else if (conversion == 'x')
		printlen[0] += ft_basehexa(va_arg(args, unsigned int), 0);
	else if (conversion == 'X')
		printlen[0] += ft_basehexa(va_arg(args, unsigned int), 1);
	else if (conversion == '%')
		printlen[0] += ft_printchar('%');
}

/* int	main(void)
{
	int	ptr[1];

	// Single char
	printf("Native test: %c \n", 'a');
	ft_printf("Custom test: %c \n", 'a');
	//String
	printf("Native test: %s \n", "String");
	ft_printf("Custom test: %s \n", "String");
	//Void *
	printf("Native test: %p \n", ptr);
	ft_printf("Custom test: %p \n", ptr);
	//Integer or decimal
	printf("%d\n", printf("Native test: %ld %i \n", -2147483648, 2147483647));
	printf("%d\n", ft_printf("Custom test: %d %i \n", -2147483648, 2147483647));
	//Unsigned decimal
	printf("Native test: %u\n", -10);
	ft_printf("Custom test: %u \n", -10);
	//Hexadecimal lowercase
	printf("Native test: %lx\n", 123456);
	ft_printf("Custom test: %x \n", 123456);
	//Hexadecimal upercase
	printf("Native test: %llX\n", 123456);
	ft_printf("Custom test: %X \n", 123456);
	// % symbol
	printf("Native test: %% %d\n", 123456);
	ft_printf("Custom test: %% %d \n", 123456);
	return (0);
} */
