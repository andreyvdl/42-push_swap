/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:34:23 by adantas-          #+#    #+#             */
/*   Updated: 2023/02/22 11:35:22 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_stack *stks)
{
	size_t	i;
	size_t	j;
	size_t	ref;

	ref = 0;
	while (stks->sz_a != 3 && !is_sorted(stks, 1))
	{
		i = -1;
		j = 0;
		while (stks->a[++i] != stks->f[ref] && i < stks->sz_a)
			j++;
		select_send_next(stks, j, ref);
		ref++;
	}
	if (stks->sz_a == 3)
		stooge_sort(stks);
	while (stks->sz_b)
		push_a(stks);
}

void	select_send_next(t_stack *stks, size_t dist, size_t ref)
{
	if (stks->sz_a / 2 < dist)
	{
		while (stks->a[0] != stks->f[ref])
			revrot_a(stks);
	}
	else
	{
		while (dist--)
			rot_a(stks);
	}
	if (!is_sorted(stks, 1))
		push_b(stks);
}
