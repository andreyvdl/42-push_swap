/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:36:28 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/28 14:41:35 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		ft_putchar('-');
		if (n < -9)
			ft_putnbr((n / 10) * -1);
	}
	if (n > 9)
		ft_putnbr(n / 10);
	c = ft_absolute(n % 10) + '0';
	ft_putchar(c);
}
