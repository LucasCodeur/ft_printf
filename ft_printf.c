/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:07:01 by lud-adam          #+#    #+#             */
/*   Updated: 2024/12/19 14:07:59 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(char specifier, va_list arguments)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char((char)va_arg(arguments, int));
	else if (specifier == 's')
		count += print_str((char *)va_arg(arguments, char *));
	else if (specifier == 'p')
		count += print_memory(va_arg(arguments, void *),"0123456789abcdef", 16);
	else if (specifier == 'd')
		count += print_nbr(va_arg(arguments, int), "0123456789abcdef", 10);
	else if (specifier == 'i')
		count += print_nbr(va_arg(arguments, int), "0123456789abcdef", 10);
	else if (specifier == 'x')
		count += print_nbr(va_arg(arguments, unsigned int), "0123456789abcdef", 16);
	else if (specifier == 'X')
		count += print_nbr(va_arg(arguments, unsigned int), "0123456789ABCDEF", 16);
	else if (specifier == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int	count;
	va_list	arguments;

	va_start(arguments, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_format(*++format, arguments);
		else
			count += write(1, format, 1);
		if (count == -1)
			return (count); 
		++format;
	}
	va_end(arguments);
	return (count);
}

// int	main(void)
// {
// 	ft_printf("%p\n", "fdsafsa");
// 	printf("%p\n", "fdsafsa");
// }
