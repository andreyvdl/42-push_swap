/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_pt2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:24:46 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/29 10:56:46 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_matrixdup(char **matrix)
{
	size_t	i;
	char	**copy;

	if (!matrix || !*matrix)
		return (0x0);
	i = 0;
	while (matrix[i])
		i++;
	copy = (char **)ft_calloc(i + 1, sizeof(char *));
	if (!copy)
		return (0x0);
	copy[0] = ft_strdup(matrix[0]);
	while (i > 0)
	{
		copy[i - 1] = ft_strdup(matrix[i - 1]);
		i--;
	}
	return (copy);
}
