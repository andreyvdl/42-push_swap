/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:15:11 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/28 15:27:42 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcapitalize(char *str)
{
	size_t	i;

	i = 0;
	while (str[++i])
	{
		if (ft_islower(str[0]))
			str[0] -= 32;
		if (ft_islower(str[i]) && !ft_isalnum(str[i - 1]))
			str[i] -= 32;
		else if (ft_isupper(str[i]) && ft_isalnum(str[i - 1]))
			str[i] += 32;
	}
	return (str);
}

char	*ft_strlowcase(char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	return (str);
}

char	*ft_strupcase(char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	return (str);
}
