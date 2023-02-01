/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_pt2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:24:04 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/28 15:24:35 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t	i;
	size_t	j;

	if (!to_find[0])
		return ((char *)str);
	else if (!to_find[0] && !str[0])
		return ((char *)str);
	i = -1;
	while (str[++i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == 0)
				return (&((char *)str)[i]);
			j++;
		}
	}
	return (0x0);
}
