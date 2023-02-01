/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:43:19 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/28 15:30:00 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		i;

	if (s == 0x0)
		return (0x0);
	copy = (char *)malloc(ft_strlen(s) + 1);
	if (copy == 0x0)
		return (0x0);
	i = 0;
	while (s[i] != '\0')
	{
		copy[i] = ((char *)s)[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strcpy(char *dst, char *src)
{
	size_t	i;

	i = -1;
	if (!dst || !src)
		return (NULL);
	while (src[++i])
		dst[i] = src[i];
	dst[i] = 0;
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i + 1 < size && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	i = ft_strlen(src);
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	init;
	size_t	end;
	char	*str;

	if (s1 == 0x0)
		return (0x0);
	i = 0;
	while (ft_strchr(set, s1[i]) && s1[i] != '\0')
		i++;
	init = i;
	i = ft_strlen(s1) - 1;
	while (ft_strrchr(set, s1[i]) && i > init)
		i--;
	end = i + 1;
	str = (char *)malloc(sizeof(char) * (end - init) + 1);
	if (str == 0x0)
		return (0x0);
	i = 0;
	while (init != end)
		str[i++] = s1[init++];
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	str_sz;

	str_sz = ft_strlen(s);
	if (str_sz < start)
	{
		str = (char *)malloc(sizeof(char));
		str[0] = s[str_sz];
		return (str);
	}
	else if (str_sz < len)
		str = (char *)malloc(sizeof(char) * str_sz + 1);
	else if (len == str_sz)
		str = (char *)malloc(sizeof(char) * str_sz - start + 1);
	else
		str = (char *)malloc(sizeof(char) * len + 1);
	if (str == 0x0)
		return (0x0);
	i = 0;
	while (i != len && s[start] != '\0')
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
