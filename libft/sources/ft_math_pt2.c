/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_pt2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:02:00 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/30 16:02:26 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

double	ft_sum(size_t n, ...)
{
	va_list	al;
	double	total;
	size_t	i;

	va_start(al, n);
	i = 0;
	total = 0;
	while (i < n)
	{
		total += va_arg(al, double);
		i++;
	}
	va_end(al);
	return (total);
}
