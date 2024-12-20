/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:08:57 by lud-adam          #+#    #+#             */
/*   Updated: 2024/12/20 11:50:09 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "./libft/libft.h"

int	ft_putnbr_base(long long nb, char *base,  long long size_base);
int	print_memory(void *p, char *base, long long size_base);
int	print_char(char c);
int	print_str(char *str);
int	print_nbr(long long nb, char *base, long long size_base);
int	ft_printf(const char *format, ...);

#endif
