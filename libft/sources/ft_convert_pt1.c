/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pt1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:46:27 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/01 12:43:13 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	decimal(int nbr);

char	*ft_itoa(int n)
{
	char	*arr;
	int		size;

	size = decimal(n);
	arr = (char *)malloc(sizeof(char) * size + 1);
	if (arr == 0x0)
		return (0x0);
	if (n == 0)
		arr[0] = '0';
	else if (n < 0)
		arr[0] = '-';
	arr[size--] = '\0';
	while (n != 0 && size >= 0)
	{
		arr[size--] = ft_absolute(n % 10) + '0';
		n /= 10;
	}
	return (arr);
}

static int	decimal(int nbr)
{
	int	house;

	house = 0;
	if (nbr <= 0)
		house = 1;
	while (nbr != 0)
	{
		nbr /= 10;
		house++;
	}
	return (house);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sgn;
	int	rslt;

	i = 0;
	rslt = 0;
	sgn = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || ft_isdigit(nptr[i]))
		sgn = 1;
	else if (nptr[i] == '-')
		sgn = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		rslt += (nptr[i] - '0');
		if (ft_isdigit(nptr[i + 1]))
			rslt *= 10;
		i++;
	}
	return (rslt * sgn);
}

size_t	ft_btoi(char *bin)
{
	size_t	total;
	size_t	i;

	if (!bin)
		return (0);
	i = 0;
	while ((bin[i] >= 9 && bin[i] <= 13) || bin[i] == ' ')
		i++;
	total = 0;
	while (bin[i] && (bin[i] == '0' || bin[i] == '1'))
	{
		if (bin[i] == '1')
			total |= 1;
		if (bin[i + 1] == '0' || bin[i + 1] == '1')
			total <<= 1;
		i++;
	}
	return (total);
}

char	*ft_itob(size_t nbr)
{
	char	*bin;
	size_t	i;

	if (nbr == 0 || nbr == 1)
		return (ft_itoa(nbr));
	bin = (char *)ft_calloc(64 + 1, sizeof(char));
	if (!bin)
		return (0x0);
	i = 0;
	while (nbr != 0)
	{
		bin[i] = nbr % 2 + '0';
		nbr /= 2;
		i++;
	}
	return (ft_strrev(bin));
}
