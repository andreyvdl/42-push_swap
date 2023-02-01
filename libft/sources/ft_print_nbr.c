/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:08:12 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/28 09:52:28 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int			decimal(int nbr);
static unsigned int	u_decimal(unsigned int nbr);

int	print_int(int nbr)
{
	int		n;
	char	*arr;
	int		size;

	size = decimal(nbr);
	arr = (char *)malloc(sizeof(char) * size + 1);
	if (!arr)
		return (0);
	if (!nbr)
		arr[0] = '0';
	else if (nbr < 0)
		arr[0] = '-';
	arr[size--] = '\0';
	while (nbr != 0 && size >= 0)
	{
		arr[size--] = ft_absolute(nbr % 10) + '0';
		nbr /= 10;
	}
	n = (int)write(1, arr, ft_strlen(arr));
	free(arr);
	arr = 0x0;
	return (n);
}

int	print_uint(unsigned int nbr)
{
	int		n;
	char	*arr;
	int		size;

	size = u_decimal(nbr);
	arr = (char *)malloc(sizeof(char) * size + 1);
	if (!arr)
		return (0);
	if (!nbr)
		arr[0] = '0';
	arr[size--] = '\0';
	while (nbr != 0 && size >= 0)
	{
		arr[size--] = nbr % 10 + '0';
		nbr /= 10;
	}
	n = (int)write(1, arr, ft_strlen(arr));
	free(arr);
	arr = 0x0;
	return (n);
}

static int	decimal(int nbr)
{
	int	house;

	house = 0;
	if (nbr <= 0)
		house = 1;
	while (nbr)
	{
		nbr /= 10;
		house++;
	}
	return (house);
}

static unsigned int	u_decimal(unsigned int nbr)
{
	unsigned int	house;

	house = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		house++;
	}
	return (house);
}
