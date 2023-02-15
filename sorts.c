/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:50:53 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/15 16:57:04 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stooge_sort(t_stack *stks)
{
	while (!is_sorted(stks))
	{
		if (stks->a[0] < stks->a[1] && stks->a[0] < stks->a[2])
		{
			revrot_a(stks);
			swap_a(stks);
		}
		else if (stks->a[0] > stks->a[1] && stks->a[0] < stks->a[2])
			swap_a(stks);
		else if (stks->a[0] < stks->a[1] && stks->a[0] > stks->a[2])
			revrot_a(stks);
		else if (stks->a[0] > stks->a[1] && stks->a[1] < stks->a[2])
			rot_a(stks);
		else if (stks->a[0] > stks->a[1] && stks->a[1] > stks->a[2])
		{
			rot_a(stks);
			swap_a(stks);
		}
	}
}

int	is_sorted(t_stack *stks)
{
	size_t	i;

	i = -1;
	while (++i < stks->sz_a - 1)
	{
		if (stks->a[i] > stks->a[i + 1])
			return (0);
	}
	return (1);
}

void	insertion_sort(t_stack *stks)
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

void	selection_sort(t_stack *stks, size_t dist, size_t ref)
{
	if (stks->sz_a / 2 <= dist)
	{
		while (stks->a[0] != stks->f[ref])
			revrot_a(stks);
	}
	else
	{
		while (dist--)
			rot_a(stks);
	}
	push_b(stks);
}
