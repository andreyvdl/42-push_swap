/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:57:34 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/30 11:19:25 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = 0x0;
	}
}

void	ft_free_matrix(void **matrix)
{
	size_t	i;

	i = -1;
	if (matrix || *matrix)
	{
		while (matrix[++i])
		{
			free(matrix[i]);
			matrix[i] = 0x0;
		}
		free(matrix);
		matrix = 0x0;
	}
}
