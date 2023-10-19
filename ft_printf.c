/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:32:32 by anporced          #+#    #+#             */
/*   Updated: 2023/10/19 14:14:10 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list arg, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (format == '%')
		return (ft_putchar(va_arg(arg, int)));
	else if (format == 'x')
		return (ft_putnbr_xX(va_arg(arg, unsigned int), 1));
	else if (format == 'X')
		return (ft_putnbr_xX(va_arg(arg, unsigned int), 0));
	else if (format == 'u')
		return (ft_putnbr_unsigned(va_arg(arg, unsigned int)));
	else if (format == 'p')
		return (ft_putptr(va_arg(arg, unsigned long int)));
}

int	ft_printf(char const *str, ...)
{
	va_list		arg;
	int			i;
	int			print_len;

	i = 0;
	print_len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += ft_format(arg, str[i + 1]);
			i += 2;
		}
		else
		{
			print_len += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(arg);
	return (print_len);
}

int	main(void)
{
	int x = 42;

	ft_printf("%X\n", x);
	printf("%X\n", x);
	ft_printf("%x\n", x);
	printf("%x\n", x);
	return (0);
}