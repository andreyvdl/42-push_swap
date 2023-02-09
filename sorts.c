/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:50:53 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/09 17:38:34 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	three_sort(t_stack *stks)
{
	if (stks->[0] < stks->a[1] && stks->a[0] < stks->a[2])
	{
		revrot_a(stks);
		swap_a(stks);
	}
	else if (stks->a[0] > stks->a[1] && stks->a[0] < stks->a[2])
		swap_a(stks);
	else if (stks->a[0] < stks->a[1] && stks->a[0] > stks->a[2])
		revrot_a(stks);
	else if (stks->a[0] > stks->a[1] && stks->a[0] > stks->a[2])
		rot_a(stks);
	else if (stks->a[0] > stks->a[1] && stks->[1] > stks->a[2])
	{
		swap_a(stks);
		rot_a(stks);
	}
	if (!is_sorted(stks))
		return (stooge_sort(stks));
	return (0);
}

int	is_sorted(t_stack *stks)
{
	int	i;

	i = -1;
	while (++i < stks->sz_a - 1)
	{
		if (stks->a[i] > stks->a[i + 1])
			return (0);
	}
	return (1);
}

int	rev_sorted(t_stack *stks)
{
	int	i;

	i = -1;
	while (++i < stks->sz_b - 1)
	{
		if (stks->b[i] < stks->b[i + 1])
			return (0);
	}
	return (1);
}
