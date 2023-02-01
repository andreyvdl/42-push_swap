/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:34:50 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/28 15:17:35 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	al;
	int		n;
	int		i;

	i = 0;
	n = 0;
	if (!format)
		return (-1);
	va_start(al, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			n += this_flag(format[i + 1], al);
			i++;
		}
		else
			n += (int)write(1, &format[i], 1);
		i++;
	}
	va_end(al);
	return (n);
}

int	this_flag(unsigned char c, va_list al)
{
	if (c == 'c')
		return (print_chr(va_arg(al, int)));
	else if (c == 's')
		return (print_str(va_arg(al, char *)));
	else if (c == 'p')
		return (print_ptr_hex(va_arg(al, size_t)));
	else if (c == 'i' || c == 'd')
		return (print_int(va_arg(al, int)));
	else if (c == 'u')
		return (print_uint(va_arg(al, unsigned int)));
	else if (c == 'x')
		return (print_hex_low(va_arg(al, unsigned int)));
	else if (c == 'X')
		return (print_hex_cap(va_arg(al, unsigned int)));
	else if (c == '%')
		return ((int)write(1, "%", 1));
	else
		return ((int)write(1, "%", 1) + (int)write(1, &c, 1));
}

int	print_str(char *str)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	if (!str)
		return ((int)write(1, "(null)", 6));
	while (str[i])
	{
		n += (int)write(1, &str[i], 1);
		i++;
	}
	return (n);
}

int	print_chr(int c)
{
	return ((int)write(1, &c, 1));
}
