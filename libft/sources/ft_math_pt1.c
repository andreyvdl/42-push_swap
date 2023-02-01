/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_pt1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:30:01 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/31 12:46:35 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_factorial(size_t n)
{
	size_t	total;

	if (n == 1 || n == 0)
		return (1);
	total = n;
	while (n > 2)
	{
		total *= (n - 1);
		--n;
	}
	return (total);
}

size_t	ft_termial(size_t n)
{
	size_t	total;

	total = n;
	while (n > 1)
	{
		total += (n - 1);
		n--;
	}
	return (total);
}

ssize_t	ft_next_prime(ssize_t nb)
{
	if (nb <= 1)
		return (2);
	else if (nb == 2)
		return (3);
	else if (nb == 3)
		return (5);
	else if (nb == 5)
		return (7);
	else if (nb == 7)
		return (11);
	while (nb % 2 == 0 || nb % 3 == 0 || nb % 5 == 0 || nb % 7 == 0)
	{
		if (nb < 0)
			return (2);
		++nb;
	}
	return (nb);
}

double	ft_power(double n, ssize_t exp)
{
	double	total;

	if (exp == 0 || (n == 1 && exp > 0))
		return (1);
	else if (n == 0)
		return (0);
	else if (exp == 1)
		return (n);
	else if (exp < 0)
		return (ft_neg_power(n, exp));
	total = n;
	while (exp > 1)
	{
		total *= n;
		exp--;
	}
	return (total);
}

double	ft_neg_power(double n, ssize_t exp)
{
	double	total;

	exp *= -1;
	total = n;
	while (exp > 1)
	{
		total *= n;
		exp--;
	}
	return (1 / total);
}
