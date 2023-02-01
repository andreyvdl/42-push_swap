/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_println.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:27:50 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/01 12:46:42 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_println(const char *str, ...)
{
	va_list	al;
	int		n;
	int		i;

	i = 0;
	n = 0;
	if (!str)
		return (-1);
	va_start(al, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			n += this_flag(str[i + 1], al);
			i++;
		}
		else
			n += (int)write(1, &str[i], 1);
		i++;
	}
	va_end(al);
	return ((int)write(1, "\n", 1) + n);
}
