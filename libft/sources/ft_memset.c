/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:42:10 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/30 11:13:05 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n)
		((char *)s)[i++] = c;
	return (s);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	tmp_src = (unsigned char *)src;
	tmp_dst = (unsigned char *)dst;
	if (tmp_dst < tmp_src)
		ft_memcpy(tmp_dst, tmp_src, n);
	else
	{
		while (n--)
			tmp_dst[n] = tmp_src[n];
	}
	return (dst);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n)
		((char *)s)[i++] = '\0';
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*arr;
	size_t	i;
	size_t	memlmt;

	memlmt = nmemb * size;
	if (memlmt / size != nmemb || memlmt / nmemb != size)
		return (0x0);
	arr = (char *)malloc(nmemb * size);
	if (arr == 0x0)
		return (0x0);
	i = 0;
	while (nmemb * size != i)
	{
		arr[i] = '\0';
		i++;
	}
	return ((void *)arr);
}
