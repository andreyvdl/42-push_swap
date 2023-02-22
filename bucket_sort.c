/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:58:16 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/22 16:49:28 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bucket_sort(t_stack *stks, int bucket[], int buck_sz, int limiter)
{
	size_t	h_first;
	size_t	h_last;

	h_first = 0;
	h_last = stks->sz_a - 1;
	if (buck_sz > limiter + 1)
		return ;
	while (h_first < stks->sz_a - 1 && h_last != 0)
	{
		h_first = 0;
		h_last = stks->sz_a - 1;
		while (stks->a[h_first] > bucket[buck_sz - 1]
			&& h_first < stks->sz_a - 1)
			h_first++;
		while (stks->a[h_last] > bucket[buck_sz - 1] && h_last != 0)
			h_last--;
		if (h_first <= h_last)
			which_send(stks, h_first, h_last);
	}
	if (limiter == 100)
		bucket_sort(stks, bucket, buck_sz + 20, limiter);
	else
		bucket_sort(stks, bucket, buck_sz + 50, limiter);
}

void	which_send(t_stack *stks, size_t h_first, size_t h_last)
{
	if (stks->sz_a - h_last >= h_first)
		push_to_b(stks, stks->a[h_first], 1);
	else
		push_to_b(stks, stks->a[h_last], 0);
}

void	push_to_b(t_stack *stks, int ref, int rotation)
{
	if (rotation == 1)
		while (stks->a[0] != ref)
			rot_a(stks);
	else
		while (stks->a[0] != ref)
			revrot_a(stks);
	push_b(stks);
}

void	push_order(t_stack *stks)
{
	size_t	i;
	int		tmp;

	while (stks->sz_b)
	{
		i = -1;
		tmp = stks->b[0];
		while (++i < stks->sz_b)
			if (stks->b[i] > tmp)
				tmp = stks->b[i];
		i = 0;
		while (stks->b[i] != tmp)
			i++;
		if (i <= stks->sz_b / 2)
			while (stks->b[0] != tmp)
				rot_b(stks);
		else
			while (stks->b[0] != tmp)
				revrot_b(stks);
		push_a(stks);
	}
}
