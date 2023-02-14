/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:50:53 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/14 15:31:25 by adantas-         ###   ########.fr       */
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
