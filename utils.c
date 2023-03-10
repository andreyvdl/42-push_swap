/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:24:15 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/22 11:34:48 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stks, int side)
{
	size_t	i;

	i = -1;
	if (side == 1)
	{
		while (++i < stks->sz_a - 1)
			if (stks->a[i] > stks->a[i + 1])
				return (0);
	}
	else
	{
		while (++i < stks->sz_b - 1)
			if (stks->b[i] > stks->b[i + 1])
				return (0);
	}
	return (1);
}

void	sort_reference(t_stack *stks)
{
	int		tmp;
	size_t	i;
	size_t	j;

	stks->f[0] = stks->a[0];
	i = 1;
	while (i < stks->sz_a)
	{
		j = i;
		stks->f[i] = stks->a[i];
		while (j != 0 && stks->f[j] < stks->f[j - 1])
		{
			tmp = stks->f[j - 1];
			stks->f[j - 1] = stks->f[j];
			stks->f[j] = tmp;
			j--;
		}
		i++;
	}
}
