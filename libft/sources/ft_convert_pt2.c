/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pt2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:50:08 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/31 11:00:48 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/libft_defines.h"

size_t	ft_otoi(char *octal)
{
	size_t	total;
	size_t	end;
	size_t	start;
	size_t	i;

	if (!octal)
		return (0);
	i = 0;
	while ((octal[i] >= 9 && octal[i] <= 13) || octal[i] == 32)
		i++;
	end = i;
	while (octal[i] && (ft_strchr("01234567", octal[i])))
		i++;
	start = i;
	total = 0;
	while (end < start)
	{
		total += octal[end] * ft_power(8, start - end - 1);
		end++;
	}
	return (total);
}

char	*ft_itoo(size_t n)
{
	char	*octal;
	size_t	i;

	if (n >= 0 && n <= 7)
		return (ft_itoa(n));
	octal = (char *)ft_calloc(22 + 1, sizeof(char));
	if (!octal)
		return (0x0);
	i = 0;
	while (n != 0)
	{
		octal[i] = n % 8 + '0';
		n /= 8;
		i++;
	}
	return (ft_strrev(octal));
}

size_t	ft_htoi(char *hex)
{
	size_t	total;
	size_t	end;
	size_t	start;
	size_t	i;

	if (!hex)
		return (0);
	i = 0;
	while ((hex[i] >= 9 && hex[i] <= 13) || hex[i] == 32)
		i++;
	end = i;
	while (hex[i] && (ft_strchr("0123456789abcdef", hex[i])))
		i++;
	start = i;
	total = 0;
	while (end < start)
	{
		total += hex[end] * ft_power(16, start - end - 1);
		end++;
	}
	return (total);
}

char	*ft_itoh(size_t n)
{
	char	*hex;
	size_t	i;

	if (n >= 0 && n <= 9)
		return (ft_itoa(n));
	if (n >= 10 && n <= 15)
	{
		hex = (char *)ft_calloc(1 + 1, sizeof(char));
		if (!hex)
			return (0x0);
		hex[0] = HEX_U[n];
		return (hex);
	}
	hex = (char *)ft_calloc(16 + 1, sizeof(char));
	if (!hex)
		return (0x0);
	i = 0;
	while (n != 0)
	{
		hex[i] = HEX_U[n % 16];
		n /= 16;
		i++;
	}
	return (ft_strrev(hex));
}
