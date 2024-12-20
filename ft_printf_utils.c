/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:17:43 by lud-adam          #+#    #+#             */
/*   Updated: 2024/12/20 13:51:08 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long long nb, char *base, long long size_base)
{
	int count;

	count = 0;
	if (nb >= size_base)
		count += ft_putnbr_base(nb / size_base, base, size_base);
	count += write(1, &base[nb % size_base], 1);
	if (count == -1)
		return (-1);
	return (count);
}

int	print_char(char c)
{
	return (write(1, &c, 1));	
}

int	print_str(char *str)
{
	int		count;

	count = 0;
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (-1);
	}
	count += ft_putstr_fd(str, 1);
	return (count);
}

int	print_nbr(long long nb, char *base, long long size_base)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		nb = -nb;
		count += write(1, "-", 1);
	}
	count += ft_putnbr_base(nb, base, size_base);
	return (count);
}

int	print_memory(void *p, char *base, long long size_base)
{
	int		count;

	count = 0;
	if (!p)
	{
		count = ft_putstr_fd("(nil)", 1);
		return (count);
	}
	count += ft_putstr_fd("0x", 1);
	count += print_nbr((unsigned long)p, base, size_base);
	return (count);
}
