/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:41:59 by anporced          #+#    #+#             */
/*   Updated: 2023/10/19 14:17:01 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nbrlen_unsigned(unsigned int nbr, int base)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_putnbr_unsigned(nb / 10);
		ft_putnbr_unsigned(nb % 10);
	}
	else
		ft_putchar(nb + '0');
	return (ft_nbrlen_unsigned(nb, 10));
}

int	ft_putnbr_hex(unsigned long int nbr)
{
	if (nbr > 16)
	{
		ft_putnbr_hex(nbr / 16);
		ft_putnbr_hex(nbr % 16);
	}
	else
	{
		if (nbr > 9)
			nbr += 'a' - '9' - 1;
		ft_putchar(nbr + '0');
	}
	return (ft_nbrlen_unsigned(nbr, 16));
}

int	ft_putnbr_xX(unsigned long int nbr, int check)
{
	if (nbr > 16)
	{
		ft_putnbr_xX(nbr / 16, check);
		ft_putnbr_xX(nbr % 16, check);
	}
	else
	{
		if (nbr > 9 && check)
			ft_putchar(nbr + 'a' - 10);
		else if (nbr > 9 && !check)
			ft_putchar(nbr + 'A' - 10);
		else
			ft_putchar(nbr + '0');

	}
	return (ft_nbrlen_unsigned(nbr, 16));
}

int	ft_putptr(unsigned long int ptr)
{
	if (!ptr)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_putstr("0x");
	return (ft_putnbr_hex(((unsigned long int) ptr)) + 2);
}
